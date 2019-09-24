#ifndef BOOM_H
#define BOOM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QPixmap>
#include <QTimer>
#include <widget.h>

class Boom : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit Boom(QObject *parent = nullptr);
	~Boom();

public slots:
    void slotGameTimer();

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QPixmap *spriteImage;

};

#endif // BOOM_H
