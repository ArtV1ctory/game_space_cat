#include "back.h"

Back::Back(QObject *parent) : QObject(parent), QGraphicsItem()
{
	currentFrame = 0;
    spriteImage = new QPixmap(":/sources/items/back.png");
    timer = new QTimer();
	connect(timer, &QTimer::timeout, this, &Back::nextFrame);
    timer->start(40);
}

Back::~Back()
{}

QRectF Back::boundingRect() const
{
	return QRectF(0,0,900,600);
}

void Back::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0,0, *spriteImage, currentFrame, 0, 900,600);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Back::nextFrame()
{
    currentFrame += 1;
    if (currentFrame >= 2700 ) currentFrame = 0;
    this->update(0,0,900,600);
}

void Back::pause()
{
	if(timer->isActive()){
		  timer->stop();
	} else {
		  timer->start(40);
	}
}
