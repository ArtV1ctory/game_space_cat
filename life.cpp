#include "life.h"

Life::Life(QObject *parent) : QObject(parent), QGraphicsItem()
{
    spriteImage = new QPixmap(":/sources/items/life.png");
}

Life::~Life()
{}

QRectF Life::boundingRect() const
{
	return QRectF(0,0,30,20);
}

void Life::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0,0, *spriteImage, 0, 0, 30, 20);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Life::slotGameTimer()
{
	this->setPos(mapToParent(-1.5,0));
}
