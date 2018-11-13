#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent)
{
//    this->Squares = new vector<vector<QGraphicsRectItem *>>();
    this->GLayout = new QGridLayout(this);
    this->GWidget = new QWidget(this);
    this->GClose = new QPushButton("Close");
    this->GameScene = new QGraphicsScene();
    this->GameView = new QGraphicsView(GameScene);

    this->GLayout->addWidget(GameView);

    this->CreateBoard();

    GameView->show();


    this->connect(this->GClose,SIGNAL(pressed()),this,SLOT(close()));

//    this->setStyleSheet("background-color:white");

    this->GLayout->addWidget(GClose,0,100);
    this->GWidget->setLayout(GLayout);
    this->setCentralWidget(GWidget);

}

void GameWindow::CreateBoard()
{
    for(int Y = -300 ; Y < 300 ; Y+= 75)
    {
        if(((Y / 75) % 2 == 1) || ((Y / 75) % 2 == -1))
        {
            this->CreateRow(QBrush(Qt ::white),QBrush(Qt::black),Y);
        }
        else if((Y / 75) % 2 == 0)
        {
            this->CreateRow(QBrush(Qt::black),QBrush(Qt::white),Y);
        }
    }
}

void GameWindow::CreateRow(QBrush first, QBrush last, int y)
{
    QBrush color;
    QPen gpen(Qt ::black);
    QGraphicsRectItem * r;
//    int i = 0 ,j = 0;
//    vector<QGraphicsRectItem *> v;

    for(int X = -300 ; X < 300 ; X += 75)
    {
        if(((X / 75) % 2) == 0)
        {
            color = first;
        }
        else if(((X / 75) % 2) == 1 || (((X / 75) % 2) == -1))
        {
            color = last;
        }

        r = this->GameScene->addRect(X,y,75,75,gpen,color);
        r->setFlags(QGraphicsItem ::ItemIsSelectable);

//        i = (X + 300) / 75;
//        j = (y + 300) / 75;

//        v.push_back(GameScene->addRect(X,y,75,75,gpen,color));
//        this->Squares[i].push_back(v);
//        QGraphicsRectItem * r = this->Squares->at(i).at(j);
//        r->setFlag(QGraphicsItem ::ItemIsSelectable);
    }
}
