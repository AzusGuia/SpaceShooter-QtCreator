#ifndef BULLET_H
#define BULLET_H

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsRectItem>
#include <QObject>
#include <typeinfo>
#include <QGraphicsPixmapItem>
#include "Enemy.h"
#include "Game.h"

class Bullet : public QObject, public QGraphicsPixmapItem
{
private:

    Q_OBJECT

public:

    Bullet(QGraphicsItem *parent = 0);

public slots:

    void move();
};

#endif // BULLET_H
