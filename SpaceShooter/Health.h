#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>

class Health : public QGraphicsTextItem
{
private:

    int health;

public:

    Health(QGraphicsTextItem *parent = 0);

    void loseHealth();
    int getHealth();
    void addHealth();

};

#endif // HEALTH_H
