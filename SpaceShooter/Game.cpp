#include "Game.h"
#include <QFont>

Game::Game(QWidget *parent)
{
    cena = new QGraphicsScene();

    setFocusPolicy(Qt::StrongFocus);

    setScene(cena);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(800,600);
    cena->setSceneRect(0,0,800,600);

}

void Game::menuView(){

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/imagens/intro.mp3"));
    music->play();

    setBackgroundBrush(QBrush(QImage(":/imagens/AF518.jpg")));

    Button *playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(gameStart()));
    cena->addItem(playButton);
}

void Game::gameStart(){

    cena->clear();

    setBackgroundBrush(QBrush(QImage(":/imagens/stars.gif")));

    player = new Player();
    player->setPos(350, 500);
    cena->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    timer = new QTimer(this);
    timerUl = new QTimer(this);
    timerMe = new QTimer(this);

    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(tmp);

    QObject::connect(timerUl,SIGNAL(timeout()),player,SLOT(spawnLife()));
    timerUl->start(15000);

    QObject::connect(timerMe,SIGNAL(timeout()),player,SLOT(spawnMeteor()));
    timerMe->start(3000);

    score = new Score();
    cena->addItem(score);

    health = new Health();
    health->setPos(0, 25);
    cena->addItem(health);

    tempo = new QBasicTimer();
    tempo->start(300, this);

    music->stop();
    music->setMedia(QUrl("qrc:/imagens/lv.mp3"));
    music->play();
}

void Game::perdeu(){

    scene()->clear();

    delete tempo, health, player, timer, timerUl, timerMe;
    tmp = 3000;

    setBackgroundBrush(QBrush(QImage(":/imagens/gameover.jpg")));

    music->stop();
    music->setMedia(QUrl("qrc:/imagens/go.mp3"));
    music->play();

    Button *playButton = new Button(QString("Reiniciar Game"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 150;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(gameStart()));
    cena->addItem(playButton);
}

void Game::ganhou()
{
    scene()->clear();

    delete tempo, health, player, timer, timerUl, timerMe;
    tmp = 3000;

    setBackgroundBrush(QBrush(QImage(":/imagens/ganhou.jpg")));

    music->stop();
    music->setMedia(QUrl("qrc:/imagens/go.mp3"));
    music->play();

    Button *playButton = new Button(QString("Reiniciar Game"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(gameStart()));
    cena->addItem(playButton);
}

Score *Game::getScore() const
{
    return score;
}

void Game::setScore(Score *value)
{
    score = value;
}

Health *Game::getHealth() const
{
    return health;
}

void Game::setHealth(Health *value)
{
    health = value;
}

void Game::timerEvent(QTimerEvent *event){

    if(health->getHealth() <= 0)
        perdeu();

    if(!player->isActive())
        perdeu();

    if(music->state() == QMediaPlayer::StoppedState)
        music->play();

    if(score->getPontos() == ver)
    {
        timer->stop();
        timer->start(tmp-500);
        tmp -= 500;
        ver += 15;
    }

    if(tmp == 1000)
       ganhou();

}




