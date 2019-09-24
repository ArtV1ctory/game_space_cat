#ifndef LIFE_H
#define LIFE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QPixmap>
#include <QTimer>
#include <widget.h>

class Life : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit Life(QObject *parent = nullptr);
	~Life();

public slots:
    void slotGameTimer();

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap *spriteImage;

};

#endif // LIFE_H
