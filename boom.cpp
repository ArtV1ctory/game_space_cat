#include "boom.h"

Boom::Boom(QObject *parent) : QObject(parent), QGraphicsItem()
{
    spriteImage = new QPixmap(":/sources/items/boom.png");
}

Boom::~Boom()
{}

QRectF Boom::boundingRect() const
{
	return QRectF(0,0,50,20);
}

void Boom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0,0, *spriteImage, 0, 0, 50, 20);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Boom::slotGameTimer()
{
	this->setPos(mapToParent(-1.1,0));
}
