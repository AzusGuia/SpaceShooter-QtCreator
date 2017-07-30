#include "Meteor.h"
#include "Game.h"
#include "Bullet.h"

extern Game * game;

Meteor::Meteor(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    int randNumber = rand() % 700;
    setPos(randNumber,0);

    setPixmap(QPixmap(":/imagens/meteorSmall.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Meteor::move(){

        setPos(x(), y()+6);

        if(pos().y() > 700){
        scene()->removeItem(this);
        delete this;
        }

        QList<QGraphicsItem *> collItems = collidingItems();

        for(int i=0, n = collItems.size(); i<n; ++i){

            //Colisão com o jogador
            if(typeid(*(collItems[i])) == typeid(Player)){

                scene()->removeItem(collItems[i]);
                scene()->removeItem(this);
                delete collItems[i];
                delete this;
                return;
                }

            //Colisão com o tiro
            if(typeid(*(collItems[i])) == typeid(Bullet)){
                life--;
                if(life == 0){
                    game->getScore()->addPontos();
                    scene()->removeItem(this);
                    delete this;
                    return;
                }else{
                scene()->removeItem(collItems[i]);
                delete collItems[i];
                return;
                }

              }
        }
}
