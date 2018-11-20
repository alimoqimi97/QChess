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
        b = CurPos.IncreaseRow(1).IncreaseCol(1);
        c = CurPos.IncreaseRow(1).DecreaseCol(1);
    }
    else
    {
        b = CurPos.DecreaseRow(1).IncreaseCol(1);
        c = CurPos.DecreaseRow(1).DecreaseCol(1);
    }

//    if(this->ControlBead(cboard,b))
//    {
        np.push_back(b);
//    }

//    if(this->ControlBead(cboard,c))
//    {
        np.push_back(c);
//    }

    return np;
}
