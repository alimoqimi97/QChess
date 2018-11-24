#include "bishop.h"

//Bishop::Bishop(QObject *parent) :
//    QObject(parent)
//{
//}

Bishop::Bishop()
{
    this->id = 4;
}

Bishop::Bishop(int c)
{
    this->id = 4;
    this->setBeadColor(c);
}

bool Bishop::ExaminePath(int row, int col, BoardPosition kp, BoardPosition cp)
{
    QPair<int,int> p;
    bool control = true;

    p.first = row;
    p.second = col;

    while(cp.InRange() & control)
    {
        cp = cp + p;
        control = (cp != kp);
    }

    return !control;
}

QList<BoardPosition> Bishop::NextChoices(BoardPosition &CurPos)
{
    QList<BoardPosition> np;
    BoardPosition a,b,scale(CurPos);
    bool control,AEmpty = true,BEmpty = true;

    for(int i = 1 ; i < 9 ; i++)
    {
        scale = scale.IncreaseCol(1);
        a = scale.IncreaseRow(i);
        b = scale.DecreaseRow(i);

        control = a.InRange();

        if(control)
        {
            np.push_back(a);
        }

//        AEmpty = !cboard.FindPos(a)->IsFull();

        control = b.InRange() ;

        if(control)
        {
            np.push_back(b);
        }

//        BEmpty = !cboard.FindPos(b)->IsFull();
    }

    return np;


}

bool Bishop::Check(BoardPosition &kingpos, BoardPosition &curpos)
{
    return (this->ExaminePath(1,1,kingpos,curpos) | ExaminePath(1,-1,kingpos,curpos)
            | ExaminePath(-1,1,kingpos,curpos) | ExaminePath(-1,-1,kingpos,curpos));
}
