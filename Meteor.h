#ifndef METEOR_H
#define METEOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

class Meteor : public QObject, public QGraphicsPixmapItem{

private:

    Q_OBJECT
    int life = 2;

public:

    Meteor(QGraphicsItem *parent = 0);

public slots:

    void move();

};

#endif // METEOR_H
