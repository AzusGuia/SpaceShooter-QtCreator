#ifndef UPGRADE_H
#define UPGRADE_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <typeinfo>
#include <QGraphicsScene>

#include "Player.h"

class Upgrade : public QGraphicsPixmapItem
{
public:

    Upgrade();

public slots:

    virtual void move();

};

#endif // UPGRADE_H
