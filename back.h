#ifndef BACK_H
#define BACK_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QPixmap>
#include <QTimer>

class Back : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit Back(QObject *parent = nullptr);
	~Back();
	void pause();

private slots:
	void nextFrame();

protected:
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
	QPixmap *spriteImage;
    QTimer *timer;
	int currentFrame;

};

#endif // BACK_H
