#include "pawn.h"

//Pawn::Pawn(QObject *parent) :
//    QObject(parent)
//{
//}

Pawn::Pawn() : Bead()
{
    this->id = 3;
}

Pawn::Pawn(int c)
{
    this->id = 3;
    this->setBeadColor(c);
}

//bool Pawn::ControlBead(Board &cboard, BoardPosition &bp)
//{
//    BoardPosition * f = cboard.FindPos(bp);
//    return (!f->IsFull()) | ((f->IsFull() & f->getBead()->getBeadColor())
//                             != (bp.getBead()->getBeadColor()));
//}

QList<BoardPosition> Pawn::NextChoices(BoardPosition &CurPos)
{
    //          CurPos is finded from board...          //

    QList<BoardPosition> np;
    BoardPosition b,c;

    if(CurPos.getBead()->getBeadColor() == BLACK)
    {
        b = CurPos.IncreaseRow(1);
        c = CurPos.IncreaseRow(2);
    }
    else
    {
        b = CurPos.DecreaseRow(1);
        c = CurPos.DecreaseRow(2);
    }
        np.push_back(b);
        np.push_back(c);

    return np;
}

bool Pawn::Check(BoardPosition &kingpos, BoardPosition &curpos)
{
    BoardPosition a,b;

    if(this->getBeadColor() == BLACK)
    {
        a = a.IncreaseRow(1).IncreaseCol(1);
        b = b.IncreaseRow(1).DecreaseCol(1);
    }
    else
    {
        a = a.DecreaseRow(1).IncreaseCol(1);
        b = b.DecreaseRow(1).DecreaseCol(1);
    }

    return (a == kingpos) | (b == kingpos);
}
