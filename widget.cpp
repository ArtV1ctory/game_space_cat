#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
	ui->setupUi(this);
	this->resize(900,600);
	this->setFixedSize(900,600);
	scene = new QGraphicsScene();
	ui->graphicsView->setScene(scene);
	ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(-250, -250, 900, 600);

	ui->lcdNumber->setVisible(false);
	ui->lcdNumber1->setVisible(false);
	ui->label->setVisible(false);
	ui->label_2->setVisible(false);
	ui->label_4->setVisible(true);

    timer = new QTimer();
    timerCreateLife = new QTimer();
    timerCreateBoom = new QTimer();
    timerCreateItem = new QTimer();

    gameState = GAME_STOPED;

    pauseKey = new QShortcut(this);
    pauseKey->setKey(Qt::Key_P);
    connect(pauseKey, &QShortcut::activated, this, &Widget::slotPause);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotDeleteItem(QGraphicsItem *it)
{
    foreach (QGraphicsItem *item, items) {
        if(item == it){
            scene->removeItem(item);
            items.removeOne(it);
            delete item;
            ui->lcdNumber->display(++count);
            if (count%50 == 0)
            {
                ui->lcdNumber1->display(++live);
            }
        }
    }
}

void Widget::slotCreateItem()
{
    Item *item = new Item();
    scene->addItem(item);
    item->setPos((635), (qrand() % (260)) * ((qrand()%2 == 1)?1:-1));
    item->setZValue(-1);
    items.append(item);
    connect(timer, &QTimer::timeout, item, &Item::slotGameTimer);
}

void Widget::slotDeleteLife(QGraphicsItem *item)
{
    foreach (QGraphicsItem *life, lifes) {
        if(life == item){
            scene->removeItem(life);
            lifes.removeOne(item);
            delete life;
            ui->lcdNumber1->display(++live);
        }
    }
}

void Widget::slotCreateLife()
{
    Life *life = new Life();
    scene->addItem(life);
    life->setPos((635),
                 (qrand() % (260)) * ((qrand()%2 == 1)?1:-1));
    life->setZValue(-1);
    lifes.append(life);
    connect(timer, &QTimer::timeout, life, &Life::slotGameTimer);
}

void Widget::slotDeleteBoom(QGraphicsItem *item)
{
    foreach (QGraphicsItem *boom, booms) {
        if(boom == item){
            scene->removeItem(boom);
            booms.removeOne(item);
            delete boom;
            ui->lcdNumber1->display(--live);
            if(live < 0)
            {
                ui->lcdNumber1->display(0);
                ui->lcdNumber->display(0);
                slotGameOver();
            }
        }
    }
}


void Widget::slotCreateBoom()
{
    Boom *boom = new Boom();
    scene->addItem(boom);
    boom->setPos((635+qrand()%500),
                 (qrand() % (250)) * ((qrand()%2 == 1)?1:-1));
    boom->setZValue(-1);
    booms.append(boom);
    connect(timer, &QTimer::timeout, boom, &Boom::slotGameTimer);
}

void Widget::on_pushButton_clicked()
{
	ui->lcdNumber->setVisible(true);
	ui->lcdNumber1->setVisible(true);
	ui->label->setVisible(true);
	ui->label_2->setVisible(true);
	ui->pushButton->setVisible(false);
	ui->label_3->setVisible(false);
	ui->label_4->setVisible(false);

	count = 0;
	live = 1;
	ui->lcdNumber1->display(live);

	cat = new Cat();
	back = new Back();
	scene->addItem(cat);
	cat->setPos(-200,0);
	scene->addItem(back);
	back->setPos(-250,-250);
	back->setZValue(-9);

	connect(timer, &QTimer::timeout, cat, &Cat::slotGameTimer);
	connect(timerCreateLife, &QTimer::timeout, this, &Widget::slotCreateLife);
	connect(timerCreateBoom, &QTimer::timeout, this, &Widget::slotCreateBoom);
    connect(timerCreateItem, &QTimer::timeout, this, &Widget::slotCreateItem);

	timer->start(1000 / 100);
	timerCreateLife->start(1000*100);
	timerCreateBoom->start(1000*5);
    timerCreateItem->start(1000);

	connect(cat, &Cat::signalCheckItem, this, &Widget::slotDeleteLife);
	connect(cat, &Cat::signalCheckItem, this, &Widget::slotDeleteBoom);
    connect(cat, &Cat::signalCheckItem, this, &Widget::slotDeleteItem);

	ui->pushButton->setEnabled(false);
	gameState = GAME_STARTED;
}

void Widget::slotGameOver()
{
	timer->stop();
	timerCreateLife->stop();
	timerCreateBoom->stop();
    timerCreateItem->stop();

	cat->pause();
	back->pause();

    QMessageBox::warning(this, "GAME OVER", "The cat is died :(");

	disconnect(timerCreateLife, &QTimer::timeout, this, &Widget::slotCreateLife);
	disconnect(timerCreateBoom, &QTimer::timeout, this, &Widget::slotCreateBoom);
    disconnect(timerCreateItem, &QTimer::timeout, this, &Widget::slotCreateItem);
	disconnect(timer, &QTimer::timeout, cat, &Cat::slotGameTimer);
    disconnect(cat, &Cat::signalCheckItem, this, &Widget::slotDeleteLife);
    disconnect(cat, &Cat::signalCheckItem, this, &Widget::slotDeleteBoom);
    disconnect(cat, &Cat::signalCheckItem, this, &Widget::slotDeleteItem);
	back->deleteLater();
	cat->deleteLater();

    foreach (QGraphicsItem *item, items) {
        scene->removeItem(item);
        items.removeOne(item);
        delete item;
    }
	foreach (QGraphicsItem *boom, booms) {
        scene->removeItem(boom);
        booms.removeOne(boom);
        delete boom;
	}
	foreach (QGraphicsItem *life, lifes) {
        scene->removeItem(life);
        lifes.removeOne(life);
        delete life;
	}

	ui->lcdNumber->setVisible(false);
	ui->lcdNumber1->setVisible(false);
	ui->label->setVisible(false);
	ui->label_2->setVisible(false);
	ui->label_3->setVisible(true);
	ui->pushButton->setVisible(true);
	ui->pushButton->setEnabled(true);
	ui->label_4->setVisible(true);
	gameState = GAME_STOPED;
}

void Widget::slotPause()
{
    if(gameState == GAME_STARTED){
        if(timer->isActive()){
            timer->stop();
            timerCreateLife->stop();
            timerCreateBoom->stop();
            timerCreateItem->stop();
            cat->pause();
            back->pause();
        } else {
            timer->start(1000/100);
            timerCreateItem->start(1000);
            timerCreateLife->start(1000*50);
            timerCreateBoom->start(1000*9);
            cat->pause();
            back->pause();
        }
    }
}
