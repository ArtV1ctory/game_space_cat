#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QPixmap>
#include <QTimer>
#include <widget.h>

class Item : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Item(QObject *parent = nullptr);
    ~Item();

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap *spriteImage;
    int item;

};

#endif // ITEM_H
