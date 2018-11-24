#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->Squares = new QVector<QVector<QGraphicsRectItem *>>();
    this->ChessGame = new Chess();
    this->GLayout = new QGridLayout();
    this->TurnFont = new QFont("Arial Rounded MT Bold",30);
    this->TurnLayout = new QHBoxLayout();
    this->TurnLabel = new QLabel("Turn : White");
    this->GWidget = new QWidget();
    this->GClose = new QPushButton("Close",this);
    this->GameScene = new QGraphicsScene();
    this->GameView = new QGraphicsView(GameScene);

    this->GLayout->addLayout(TurnLayout,0,0);
    this->GLayout->addWidget(GameView);
    this->GLayout->addWidget(GClose);

    this->GClose->setStyleSheet("background:gray");

    this->TurnLabel->setFont(*TurnFont);
    this->TurnLayout->addWidget(TurnLabel,100,Qt::AlignCenter);

    TurnLabel->setStyleSheet("background-color:white");
    this->CreateBoard();
    this->InsertBeadPictures();

    GameView->show();

    this->connect(this->GClose,SIGNAL(pressed()),this,SLOT(close()));
    this->connect(this->GameScene,SIGNAL(selectionChanged()),this,SLOT(MoveBead()));
    this->connect(ChessGame,SIGNAL(TurnChanged()),this,SLOT(ModifyTurn()));
//    this->connect(this->ChessGame,SIGNAL(KingIsChecked()),this,SLOT)

//    this->setStyleSheet("background-color:white");

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
    QVector<QGraphicsRectItem *> v1;
//    int i = 0 ,j = 0;

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

        v1.push_back(r);

//        i = (X + 300) / 75;

//        v.push_back(GameScene->addRect(X,y,75,75,gpen,color));
//        this->Squares[i].push_back(v);
//        QGraphicsRectItem * r = this->Squares->at(i).at(j);
//        r->setFlag(QGraphicsItem ::ItemIsSelectable);
    }

//    j = (y + 300) / 75;
    this->Squares->push_back(v1);
}

void GameWindow::FirstMoveLevel(BoardPosition *sel)
{
    if(!sel->IsFull() | !ChessGame->WhoseTurnIsIt(*sel))
    {
        return;
    }

    Movement m;

    m.setCurrentPos(sel);

    this->ChessGame->AddToLastMoves(m);

    QList<BoardPosition> ml = this->ChessGame->nextChoices(*sel);
    this->ChessGame->AddToNextMoves(ml);
    this->ShowSuggestedPos(ml);
}

void GameWindow::SecondMoveLevel(BoardPosition *sel)
{
    Movement m = ChessGame->LastMove();

    m.setNextPos(sel);

    //          warning in BoardPosition :: operator==()    //
    if(!ChessGame->NextMovesContains(sel))
    {
        return;
    }

    this->ChessGame->ChangeTurn();
    ChessGame->Move(m);
    this->MovePicture(m);
//    this->ChessGame->ReplaceInLastMoves(m);
    this->ChessGame->ClearNextMoves();
}

void GameWindow::MovePicture(Movement &mv)
{
    QGraphicsRectItem * begin = Squares->at(mv.getCurrentPos()->getRow() - 1).at(mv.getCurrentPos()->getColumn() - 65);
    QGraphicsRectItem * end = Squares->at(mv.getNextPos()->getRow() - 1).at(mv.getNextPos()->getColumn() - 65);
    QGraphicsRectItem * r;
    BoardPosition bp;

    end->setBrush(begin->brush());
    bp = mv.getCurrentPos()->IncreaseCol(1);

    if(!bp.InRange())
    {
        bp = mv.getCurrentPos()->DecreaseCol(1);
    }

    r = Squares->at(bp.getRow() - 1).at(bp.getColumn() - 65);

    if(r->brush().color() == Qt::black)
    {
        begin->setBrush(Qt::white);
    }
    else
    {
        begin->setBrush(Qt::black);
    }

}

void GameWindow::ShowSuggestedPos(QList<BoardPosition> &sl)
{
    int i = 0 , j = 0;

    for(BoardPosition b : sl)
    {
        i = b.getColumn() - 65;
        j = b.getRow() - 1;

        Squares->at(i).at(j)->setBrush(QBrush(Qt::red));
    }
}

void GameWindow::MoveBead()
{
    QGraphicsRectItem * s = (QGraphicsRectItem * )this->GameScene->selectedItems().first();

    BoardPosition s2;

    //          converting to BoardPosition coordination    //
    s2.setColumn(s->x() + 365);
    s2.setRow(s->y() + 301);
    //          ==========================                  //

    BoardPosition * selected = this->ChessGame->FindPos(s2);

    if(!selected->IsFull())
    {
        return;
    }

    if(this->ChessGame->NextMovesIsEmpty())
    {
        this->FirstMoveLevel(selected);
    }
    else
    {
        this->SecondMoveLevel(selected);
    }
}

void GameWindow::ResolveCheck()
{
    BoardPosition * kingPos;

    if(ChessGame->getTurn() == BLACK_P)
    {
        kingPos = ChessGame->getChessBoard().getBlackKingPos();
    }
    else
    {
        kingPos = ChessGame->getChessBoard().getWhiteKingPos();
    }

    this->FirstMoveLevel(kingPos);
}

void GameWindow::ModifyTurn()
{
    //        this->TurnLabel->setText("Turn : Black");
    if(ChessGame->getTurn() == BLACK_P)
    {
        this->TurnLabel->setText("Turn : Black");
    }
    else
    {
        this->TurnLabel->setText("Trun : White");
    }
}
