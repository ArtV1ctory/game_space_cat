#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include <QTimer>
#include <QList>
#include <QPixmap>
#include <QMessageBox>
#include <QShortcut>
#include <QDebug>
#include <QPalette>
#include "cat.h"
#include "life.h"
#include "back.h"
#include "boom.h"
#include "item.h"

#define GAME_STOPED 0
#define GAME_STARTED 1

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	  Q_OBJECT

public:
      explicit Widget(QWidget *parent = nullptr);
	  ~Widget();

private:
	QTimer          *timer;
	QTimer          *timerCreateLife;
	QTimer          *timerCreateBoom;
    QTimer          *timerCreateItem;

	QList<QGraphicsItem *> lifes;
    QList<QGraphicsItem *> booms;
    QList<QGraphicsItem *> items;

    int count;
	int live;

	Ui::Widget *ui;
	QGraphicsScene *scene;
	Cat *cat;
	Back *back;

    QShortcut       *pauseKey;
    int             gameState;

private slots:
	void slotDeleteLife(QGraphicsItem * item);
	void slotCreateLife();
	void slotDeleteBoom(QGraphicsItem * item);
	void slotCreateBoom();
    void slotDeleteItem(QGraphicsItem * item);
    void slotCreateItem();

    void on_pushButton_clicked();
    void slotGameOver();
    void slotPause();
};

#endif // WIDGET_H
