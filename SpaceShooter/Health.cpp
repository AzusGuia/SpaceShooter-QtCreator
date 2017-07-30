#include "Health.h"

Health::Health(QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText(QString("Vidas: ") +  QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 18));
}

int Health::getHealth(){
    return health;
}

void Health::addHealth()
{
    health++;
    setPlainText(QString("Vida: ") +  QString::number(health));
}

void Health::loseHealth(){
    health--;
    setPlainText(QString("Vida: ") +  QString::number(health));
}
