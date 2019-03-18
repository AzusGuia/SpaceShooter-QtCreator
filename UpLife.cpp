#include "UpLife.h"
#include "Game.h"

extern Game * game;

UpLife::UpLife()
{
    setPixmap(QPixmap(":/images/life.png"));

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void UpLife::move(){

    setPos(x(), y()+5);

    if(pos().y() > 600)
    delete this;

    QList<QGraphicsItem *> collItems = collidingItems();

    for(int i=0, n = collItems.size(); i<n; ++i){
        if(typeid(*(collItems[i])) == typeid(Player)){
            game->getHealth()->addHealth();
            scene()->removeItem(this);
            delete this;
            return;
            }
    }

}

void UpLife::spawn(){

    UpLife * life = new UpLife();
    scene()->addItem(life);
}

