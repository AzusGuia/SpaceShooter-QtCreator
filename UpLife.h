#ifndef UPLIFE_H
#define UPLIFE_H

#include <QObject>
#include <QTimer>

#include "Upgrade.h"

class UpLife : public QObject, public Upgrade
{
    Q_OBJECT

public:

    UpLife();

public slots:

    void move();
    void spawn();
};

#endif // UPLIFE_H
