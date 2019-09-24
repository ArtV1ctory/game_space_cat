#include "item.h"

Item::Item(QObject *parent) : QObject(parent), QGraphicsItem()
{
    const char* pictures[7] = {":/sources/items/icecream.png",
                               ":/sources/items/cake.png",
                               ":/sources/items/cookie.png",
                               ":/sources/items/cupcake.png",
                               ":/sources/items/lollypop.png",
                               ":/sources/items/peppermint.png",
                               ":/sources/items/strawberry.png"};
    this->item = qrand()%7;
    spriteImage = new QPixmap(pictures[this->item]);
}

Item::~Item()
{}

QRectF Item::boundingRect() const
{
    if (this->item == 0 or this->item == 4) {
        return QRectF(0,0,20,30);
    }
    else {
        return QRectF(0,0,20,20);
    }
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (this->item == 0 or this->item == 4) {
        painter->drawPixmap(0, 0, *spriteImage, 0, 0, 20, 30);
    }
    else {
        painter->drawPixmap(0, 0, *spriteImage, 0, 0, 20, 20);
    }
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

void Item::slotGameTimer()
{
    this->setPos(mapToParent(-1.4,0));
}
