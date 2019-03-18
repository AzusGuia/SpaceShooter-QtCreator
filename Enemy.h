#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include "Game.h"
#include "Enemy.h"

class Enemy : public QObject, public QGraphicsPixmapItem{

private:

    Q_OBJECT
    int life;

public:

    Enemy(QGraphicsItem *parent = 0);

public slots:

    void move();

};

#endif // ENEMY_H
