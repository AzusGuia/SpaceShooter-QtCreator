#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QObject>
#include <QFrame>
#include <QDebug>

class Player:public QObject, public QGraphicsPixmapItem
{
private:

    Q_OBJECT
    QMediaPlayer *somTiro;

public slots:

    void spawn();
    void spawnLife();
    void spawnMeteor();

public:

    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
