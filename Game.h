#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsTextItem>
#include <QTimerEvent>
#include <QDebug>
#include <QBasicTimer>

#include "Button.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "Health.h"
#include "UpLife.h"
#include "Meteor.h"

class Game : public QGraphicsView
{
private:

    Q_OBJECT

    QGraphicsScene * cena;
    Player         * player;
    Score          * score;
    Health         * health;
    QBasicTimer    * tempo;
    QMediaPlayer   * music;
    QTimer         * timer, * timerUl, * timerMe;

    int tmp = 4000, ver = 15;

    void timerEvent(QTimerEvent *event);

private slots:

     void perdeu();
     void ganhou();
     void gameStart();

public:

    Game(QWidget *parent = 0); 

    void menuView();

    Score *getScore() const;
    void setScore(Score *value);
    Health *getHealth() const;
    void setHealth(Health *value);
};

#endif // GAME_H
