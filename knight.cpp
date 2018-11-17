#include "knight.h"

Knight::Knight(QObject *parent) :
    QObject(parent)
{
}

Knight::Knight()
{
    this->id = 6;
}

bool Knight::ControlBead(Board &b, BoardPosition bp)
{
    //          the curpos color (bp color) is remained in it...        //
    BoardPosition * f = b.FindPos(bp);

    return (!f->IsFull()) | (f->IsFull() & f->getBead()->getBeadColor()
                             != bp.getBead()->getBeadColor());
}

BoardPosition Knight::MakePos(int row, int col, BoardPosition cp)
{
    BoardPosition p;

    p.setRow(cp.getRow() + row);
    p.setColumn(cp.getColumn() + col);

    if(p.InRange())
    {
        return p;
    }

    return cp;
}

void Knight::InsertInList(int r, int col, QList<BoardPosition> &n, BoardPosition &c, Board &B)
{
    BoardPosition t = this->MakePos(r,col,c);

    if(t.InRange() & this->ControlBead(B,t))
    {
        n.push_back(t);
    }
}

QList<BoardPosition> Knight::NextChoices(BoardPosition &CurPos, Board &cboard)
{
    QList<BoardPosition> np;
    int num[16] = {1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};


    for(int i = 0 ; i < 15 ; i += 2)
    {
        this->InsertInList(num[i],num[i + 1],np,CurPos,cboard);
    }

    return np;
}
