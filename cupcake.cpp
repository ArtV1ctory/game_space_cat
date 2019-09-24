#include "cupcake.h"

Cupcake::Cupcake(QObject *parent) : QObject(parent)
{
	spriteImage = new QPixmap(":/sources/items/cupcake.png");
}

Cupcake::~Cupcake()
{}

QRectF Icecream::boundingRect() const
{
	return QRectF(0,0,20,30);
}

void Cupcake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0,0, *spriteImage, 0, 0, 20, 20);
	Q_UNUSED(option);
	Q_UNUSED(widget);
}
