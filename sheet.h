#ifndef SHEET_H
#define SHEET_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QPixmap>
#include <QTimer>
#include <widget.h>

class Sheet : public QObject, public QGraphicsItem//, public Icecream
{
	Q_OBJECT
public:
	explicit Sheet(QObject *parent = nullptr);
	~Sheet();

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	QPixmap *spriteImage; //переменная для хранения спрайт картинки

};

#endif // SHEET_H
