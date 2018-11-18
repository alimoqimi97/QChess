#include "bishop.h"

Bishop::Bishop(QObject *parent) :
    QObject(parent)
{
}

Bishop::Bishop()
{
    this->id = 4;
}

QList<BoardPosition> Bishop::NextChoices(BoardPosition &CurPos, Board &cboard)
{
    QList<BoardPosition> np;
    BoardPosition a,b,scale(CurPos);
    bool control,AEmpty = true,BEmpty = true;

    for(int i = 1 ; i < 9 ; i++)
    {
        scale = scale.IncreaseCol(1);
        a = scale.IncreaseRow(i);
        b = scale.DecreaseRow(i);

        control = a.InRange() & AEmpty;

        if(control)
        {
            np.push_back(a);
        }

        AEmpty = !cboard.FindPos(a)->IsFull();

        control = b.InRange() & BEmpty;

        if(control)
        {
            np.push_back(b);
        }

        BEmpty = !cboard.FindPos(b)->IsFull();
    }

    return np;


}
