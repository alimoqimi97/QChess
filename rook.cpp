#include "rook.h"

//Rook::Rook(QObject *parent) :
//    QObject(parent)
//{
//}

Rook::Rook()
{
    this->id = 5;
}

Rook::Rook(int c)
{
    this->id = 5;
    this->setBeadColor(c);
}

QList<BoardPosition> Rook::NextChoices(BoardPosition &CurPos)
{
    QList<BoardPosition> np;
    bool AEmpty = true,BEmpty = true;
    BoardPosition b(CurPos),a(CurPos);

    for(int r = 1; r < 9 ; r++)
    {
        a = a.IncreaseCol(1);

        if(a.InRange() )
        {
            np.push_back(a);
        }

//        AEmpty = !cboard.FindPos(a)->IsFull();

        b = b.DecreaseCol(1);

        if(b.InRange())
        {
            np.push_back(b);
        }

//        BEmpty = !cboard.FindPos(b)->IsFull();
    }

    AEmpty = true;
    BEmpty = true;

    for(int j = 1 ; j < 9 ; j++)
    {
        a = a.IncreaseRow(1);
        b = b.DecreaseRow(1);

        if(a.InRange())
        {
            np.push_back(a);
        }

//        AEmpty = !cboard.FindPos(a)->IsFull();

        if(b.InRange())
        {
            np.push_back(b);
        }

//        BEmpty = !cboard.FindPos(b)->IsFull();
    }

    return np;
}

bool Rook::Check(BoardPosition &kingpos, BoardPosition &curpos)
{
    return (curpos.getColumn() == kingpos.getColumn())
            | (curpos.getRow() == kingpos.getRow());
}
