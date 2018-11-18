#include "rook.h"

Rook::Rook(QObject *parent) :
    QObject(parent)
{
}

Rook::Rook()
{
    this->id = 5;
}

QList<BoardPosition> Rook::NextChoices(BoardPosition &CurPos, Board &cboard)
{
    QList<BoardPosition> np;
    bool control , AEmpty = true,BEmpty = true;
    BoardPosition b(CurPos),a(CurPos);

    for(int r = 1; r < 9 ; r++)
    {
        a = a.IncreaseCol(1);

        if(a.InRange() & AEmpty)
        {
            np.push_back(a);
        }

        AEmpty = !cboard.FindPos(a)->IsFull();

        b = b.DecreaseCol(1);

        if(b.InRange() & BEmpty)
        {
            np.push_back(b);
        }

        BEmpty = !cboard.FindPos(b)->IsFull();
    }

    AEmpty = true;
    BEmpty = true;

    for(int j = 1 ; j < 9 ; j++)
    {
        a = a.IncreaseRow(1);
        b = b.DecreaseRow(1);

        if(a.InRange() & AEmpty)
        {
            np.push_back(a);
        }

        AEmpty = !cboard.FindPos(a)->IsFull();

        if(b.InRange() & BEmpty)
        {
            np.push_back(b);
        }

        BEmpty = !cboard.FindPos(b)->IsFull();
    }

    return np;


}
