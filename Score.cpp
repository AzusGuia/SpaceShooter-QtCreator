#include "Score.h"

Score::Score(QGraphicsItem *parent)
{
    pontos = 0;

    setPlainText(QString("Pontuação: ") +  QString::number(pontos));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 18));
}

int Score::getPontos(){
    return pontos;
}

void Score::addPontos(){
    pontos++;
    setPlainText(QString("Pontuação: ") +  QString::number(pontos));
}
