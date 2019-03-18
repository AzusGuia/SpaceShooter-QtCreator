#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
private:

    int pontos;

public:

    Score(QGraphicsItem * parent=0);

    int getPontos();
    void addPontos();
};

#endif // SCORE_H
