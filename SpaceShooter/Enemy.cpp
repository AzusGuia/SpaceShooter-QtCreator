#include "Enemy.h"
#include <QDebug>
#include "Player.h"
#include <QList>
#include <typeinfo>

extern Game * game;

Enemy::Enemy(QGraphicsItem  *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    int randNumber = rand() % 700;
    setPos(randNumber,0);

    setPixmap(QPixmap(":/imagens/enemyShip.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move(){

        setPos(x(), y()+5);

        if(pos().y() > 700){
        game->getHealth()->loseHealth();
        scene()->removeItem(this);
        delete this;
        }

        QList<QGraphicsItem *> collItems = collidingItems();

        for(int i=0, n = collItems.size(); i<n; ++i){
            if(typeid(*(collItems[i])) == typeid(Player)){
                game->getHealth()->loseHealth();
                scene()->removeItem(this);
                delete this;
                return;
                }
        }
}
