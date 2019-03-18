#include "Upgrade.h"

Upgrade::Upgrade()
{
     int randNumber = rand() % 700;
     setPos(randNumber,0);
}

void Upgrade::move(){

    setPos(x(), y()+5);

    if(pos().y() > 600)
    delete this;

    QList<QGraphicsItem *> collItems = collidingItems();

    for(int i=0, n = collItems.size(); i<n; ++i){
        if(typeid(*(collItems[i])) == typeid(Player)){

            scene()->removeItem(this);
            delete this;
            return;
            }
    }

}


