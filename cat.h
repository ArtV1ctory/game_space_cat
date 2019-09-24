#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <windows.h>
#include <QPixmap>
#include <QTimer>

class Cat : public QObject, public QGraphicsItem
{
	Q_OBJECT
public:
	explicit Cat(QObject *parent = nullptr);
	~Cat();
	void pause();

signals:
	void signalCheckItem(QGraphicsItem *item);

public slots:
    void slotGameTimer();

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

#endif // CAT_H
