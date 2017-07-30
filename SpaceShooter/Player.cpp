#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "UpLife.h"
#include "Meteor.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent){

    somTiro = new QMediaPlayer();
    somTiro->setMedia(QUrl("qrc:/imagens/tiro.mp3"));

    setPixmap(QPixmap(":/imagens/player.png"));
    setTransformOriginPoint(50,50);
    setRotation(0);

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-10,y());
            setPixmap(QPixmap(":/imagens/playerLeft.png"));

        }

    }
    else if(event->key() == Qt::Key_Right){

        if(pos().x() + 100 < 800){
            setPos(x()+10,y());
            setPixmap(QPixmap(":/imagens/playerRight.png"));
        }

    }

    else if (event->key() == Qt::Key_Space){

        Bullet * bullet = new Bullet();
        bullet->setPos(x()+45,y()-25);

        scene()->addItem(bullet);

        if(somTiro->state() == QMediaPlayer::PlayingState)
            somTiro->setPosition(0);
        else if(somTiro->state() == QMediaPlayer::StoppedState)
            somTiro->play();
    }
    else{
        setPixmap(QPixmap(":/imagens/player.png"));
    }
}

void Player::spawn(){

    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spawnLife(){

    UpLife * life = new UpLife();
    scene()->addItem(life);
}

void Player::spawnMeteor()
{
    Meteor * meteor = new Meteor();
    scene()->addItem(meteor);
}

