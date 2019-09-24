#include "sheet.h"

Sheet::Sheet(QObject *parent) : QObject(parent), QGraphicsItem()//, Icecream()
{
	spriteImage = new QPixmap(":/sources/items/sheet.png"); // Загружаем изображение спрайта в QPixmap
}

Sheet::~Sheet()
{}

QRectF Sheet::boundingRect() const
{
	return QRectF(0,0,80,80);
}

void Sheet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawPixmap(0,0, *spriteImage, 0, 0, 80, 80);
	Q_UNUSED(option);
	Q_UNUSED(widget);
}
