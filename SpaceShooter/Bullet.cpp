#include "Bullet.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/imagens/laserGreen.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(25);
}

void Bullet::move(){

    QList<QGraphicsItem *> collItems = collidingItems();

    for(int i=0, n = collItems.size(); i<n; ++i){
        if(typeid(*(collItems[i])) == typeid(Enemy)){

            game->getScore()->addPontos();
            scene()->removeItem(collItems[i]);
            scene()->removeItem(this);

            delete collItems[i];
            delete this;
            return;
         }
     }

    setPos(x(), y()-10);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }

}
