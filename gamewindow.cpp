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

void GameWindow::setSquares(VOV *sq)
{
    this->Squares = sq;
}

VOV *GameWindow::getSquares()
{
    return this->Squares;
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
    }

    this->Squares->push_back(v1);
}

void GameWindow::FirstMoveLevel(BoardPosition *sel)
{
    QList<BoardPosition> ml;
    Movement m;

    if(!sel->IsFull() | !ChessGame->WhoseTurnIsIt(*sel))
    {
        return;
    }


    m.setCurrentPos(sel);

    this->ChessGame->AddToLastMoves(m);
    ml = this->ChessGame->nextChoices(*sel);

    //      ml must be edited...
    //      this->ChessGame->EditChoices(ml);

    this->ChessGame->AddToNextMoves(ml);
    this->ShowSuggestedPos(ml);
//    return ml;
}

void GameWindow::SecondMoveLevel(BoardPosition *sel)
{

    this->RestoreSuggestedPos(ChessGame->getNextMoves());

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

    //          retreiving first position of bead brush       //
    this->RestoreCurrentPosBrush(m);
    //          =====================           //

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

    //              resetting the begining position color...      //
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
//    int i = 0 , j = 0;

    for(BoardPosition b : sl)
    {
        int i = 0 , j = 0;

        j = b.getColumn() - 65;
        i = b.getRow() - 1;

        if(b.InRange())
        {
            Squares->at(i).at(j)->setBrush(QBrush(Qt::red));
        }
    }
}

void GameWindow::RestoreSuggestedPos(QList<BoardPosition> sl)
{
    int i = 0 , j = 0;

    for(BoardPosition b : sl)
    {
        i = b.getRow();
        j = b.getColumn() - 65;

        if((i % 2 == 1) && (j % 2 == 0))
        {
            this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::black));
        }
        else if((i % 2 == 0) && (j % 2 == 1))
        {
            this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::black));
        }
        else if((i % 2 == 1) && (j % 2 == 1))
        {
            this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::white));
        }
        else if((i % 2 == 0) && (j % 2 == 0))
        {
            this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::white));
        }


//        if((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1))
//        {
//            this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::black));
//        }
////        else if(i % 2 == 0 && j % 2 == 1)
////        {
////            this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::black));
////        }
//        else
//        {
//            this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::white));
//        }
    }
}

void GameWindow::RestoreCurrentPosBrush(Movement &m)
{
    int i = m.getCurrentPos()->getRow() , j = m.getCurrentPos()->getColumn() - 65;

    if((i % 2 == 1) && (j % 2 == 0))
    {
        this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::black));
    }
    else if((i % 2 == 0) && (j % 2 == 1))
    {
        this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::black));
    }
    else if((i % 2 == 1) && (j % 2 == 1))
    {
        this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::white));
    }
    else if((i % 2 == 0) && (j % 2 == 0))
    {
        this->Squares->at(i - 1).at(j)->setBrush(QBrush(Qt::white));
    }

}

void GameWindow::InsertBeadPictures()
{
    QImage pawnpic(":/BeadPics/blackpawn.jpg");

    pawnpic = pawnpic.scaled(98,93,Qt::KeepAspectRatio,Qt::FastTransformation);


    //Black pawns       //
    QBrush b(pawnpic);

    for(int i = 0 ; i < 8 ; i++)
    {
        Squares->at(1).at(i)->setBrush(b);
    }

    //white pawns      //
    QImage bp(":/BeadPics/whitepawn.jpg");

    bp = bp.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);

    for(int i = 0 ; i < 8 ; i++)
    {
        this->Squares->at(6).at(i)->setBrush(QBrush(bp));
    }

    //Rook              //
    QImage wrp(":/BeadPics/whiterook.jpg");
    QImage brp(":/BeadPics/blackrook.jpg");

    wrp = wrp.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);
    brp = brp.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);

    this->Squares->at(0).at(0)->setBrush(QBrush(brp));
    this->Squares->at(0).at(7)->setBrush(QBrush(brp));

    this->Squares->at(7).at(0)->setBrush(QBrush(wrp));
    this->Squares->at(7).at(7)->setBrush(QBrush(wrp));

    //knight            //
    QImage wkp(":/BeadPics/whiteknight.jpg");
    QImage bkp(":/BeadPics/blackknight.jpg");

    wkp = wkp.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);
    bkp = bkp.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);

    this->Squares->at(0).at(1)->setBrush(QBrush(bkp));
    this->Squares->at(0).at(6)->setBrush(QBrush(bkp));

    this->Squares->at(7).at(1)->setBrush(QBrush(wkp));
    this->Squares->at(7).at(6)->setBrush(QBrush(wkp));

    //Bishop        //
    QImage wb(":/BeadPics/whitebishop.jpg");
    QImage bb(":/BeadPics/blackbishop.jpg");

    wb = wb.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);
    bb = bb.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);

    this->Squares->at(0).at(2)->setBrush(QBrush(bb));
    this->Squares->at(0).at(5)->setBrush(QBrush(bb));

    this->Squares->at(7).at(2)->setBrush(QBrush(wb));
    this->Squares->at(7).at(5)->setBrush(QBrush(wb));

    //King          //
    QImage wk(":/BeadPics/whiteking.jpg");
    QImage bk(":/BeadPics/blackking.jpg");

    wk = wk.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);
    bk = bk.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);

    this->Squares->at(0).at(3)->setBrush(QBrush(bk));
    this->Squares->at(7).at(3)->setBrush(QBrush(wk));

    //Queen         //
    QImage bq(":/BeadPics/blackqueen.jpg");
    QImage wq(":/BeadPics/whitequeen.jpg");

    bq = bq.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);
    wq = wq.scaled(90,90,Qt::KeepAspectRatio,Qt::FastTransformation);

    this->Squares->at(0).at(4)->setBrush(QBrush(bq));
    this->Squares->at(7).at(4)->setBrush(QBrush(wq));

}

void GameWindow::MoveBead()
{
//    QGraphicsRectItem * s = (QGraphicsRectItem * )this->GameScene->selectedItems().first();
    BoardPosition s2;

    //The nagative y border in GraphicsScene starts from top !...//


    //      testing             //
//    QGraphicsRectItem * s = new QGraphicsRectItem(-225,150,75,75);
    QGraphicsRectItem * s = new QGraphicsRectItem(-225,225,75,75);
    //      =======             //

    //          converting to BoardPosition coordination    //
    s2.setColumn(((s->rect().x() + 300) / 75) + 65);
    s2.setRow(((s->rect().y() + 300) / 75) + 1);
    //          ==========================                  //


    //          debugging      //
    BoardPosition * se = this->ChessGame->FindPosition(s2);
    this->FirstMoveLevel(se);
    BoardPosition b;
    b.setRow(6);
    b.setColumn('C');
    BoardPosition * selected = this->ChessGame->FindPosition(b);
    this->SecondMoveLevel(selected);

    BoardPosition deb;
    deb.setRow(2);
    deb.setColumn('B');

    this->FirstMoveLevel(ChessGame->FindPosition(deb));
    BoardPosition d2;
    d2.setRow(4);
    d2.setColumn('B');
    this->SecondMoveLevel(ChessGame->FindPosition(d2));

    this->FirstMoveLevel(ChessGame->FindPosition(b));
    this->SecondMoveLevel(ChessGame->FindPosition(deb));

    //          =============       //

//    BoardPosition * selected = this->ChessGame->FindPosition(s2);

    if(!selected->IsFull() && ChessGame->NextMovesIsEmpty())
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
        this->TurnLabel->setStyleSheet("color: red;background-color: white;");
    }
    else
    {
        this->TurnLabel->setText("Turn : White");
        this->TurnLabel->setStyleSheet("color: red;background-color: white;");
    }
}
