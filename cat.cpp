#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent), QGraphicsItem()
{
	currentFrame = 0;
    spriteImage = new QPixmap(":/sources/sprite.png");
    timer = new QTimer();
	connect(timer, &QTimer::timeout, this, &Cat::nextFrame);
    timer->start(100);
}

Cat::~Cat()
{}

QRectF Cat::boundingRect() const
{
	return QRectF(-10,-10,90,70);
}

void Cat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(-10,-10, *spriteImage, currentFrame, 0, 80,60);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Cat::nextFrame()
{
    currentFrame += 80;
    if (currentFrame >= 320 ) currentFrame = 0;
    this->update(-10,-10,80,60);
}

void Cat::slotGameTimer()
{
	if(GetAsyncKeyState(VK_UP)){
        setPos(mapToParent(0, -5));
	}
	if(GetAsyncKeyState(VK_DOWN)){
         setPos(mapToParent(0, 5));
	}
	if(GetAsyncKeyState(VK_LEFT)){
		 setPos(mapToParent(-3, 0));
	}
	if(GetAsyncKeyState(VK_RIGHT)){
		 setPos(mapToParent(3, 0));
    }
	QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
	                                                          << mapToScene(0, 0)
	                                                          << mapToScene(70,0 )
	                                                          << mapToScene(70,50)
	                                                          << mapToScene(0,50));
    foreach (QGraphicsItem *item, foundItems) {
        if (item == this)
            continue;
            emit signalCheckItem(item);
        }

	if (this->x() - 10 < -254)
	{
		this->setX(-244);
	}
	if (this->x() + 10 > 595)
	{
		this->setX(585);
	}
	if (this->y() - 10 < -250)
	{
		this->setY(-240);
	}
	if (this->y() + 10 > 310)
	{
		this->setY(300);
	}
}

void Cat::pause()
{
	if(timer->isActive()){
		  timer->stop();
	} else {
		  timer->start(100);
	}
}
