#ifndef CUPCAKE_H
#define CUPCAKE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QPixmap>
#include <QTimer>
#include <widget.h>

class Cupcake : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit Cupcake(QObject *parent = nullptr);
	~Cupcake();

signals:

public slots:

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	QPixmap *spriteImage;
};

#endif // CUPCAKE_H
