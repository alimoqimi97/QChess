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
    BoardPosition a,b,scale;
    bool control;
//    bool  AEmpty = true,BEmpty = true;

    scale.setRow(CurPos.getRow());
    scale.setColumn(CurPos.getColumn());
    scale.setBead(CurPos.getBead());

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

        control = b.InRange() ;

        if(control)
        {
            np.push_back(b);
        }

    }

//    scale = CurPos;
    scale.setRow(CurPos.getRow());
    scale.setColumn(CurPos.getColumn());
    scale.setBead(CurPos.getBead());

    for(int j = 1 ; j < 9 ; j++)
    {
        scale = scale.DecreaseCol(1);
        a = scale.IncreaseRow(j);
        b = scale.DecreaseRow(j);

        control = a.InRange();

        if(control)
        {
            np.push_back(a);
        }

        control = b.InRange();

        if(control)
        {
            np.push_back(b);
        }
    }

    return np;
}

bool Bishop::Check(BoardPosition &kingpos, BoardPosition &curpos)
{
    QPair<int,int> dif;

    dif.first = curpos.getRow() - kingpos.getRow();
    dif.second = curpos.getColumn() - kingpos.getColumn();

    return (abs(dif.first) == abs(dif.second));
}

//bool Bishop::Check(BoardPosition &kingpos, BoardPosition &curpos)
//{
//    return (this->ExaminePath(1,1,kingpos,curpos) | ExaminePath(1,-1,kingpos,curpos)
//            | ExaminePath(-1,1,kingpos,curpos) | ExaminePath(-1,-1,kingpos,curpos));
//}

void Bishop::DeletePoses(QList<BoardPosition> &N, BoardPosition *nextchoice, BoardPosition *current)
{
    QPair<int,int> result;
    BoardPosition temp;

    temp.setRow(nextchoice->getRow());
    temp.setColumn(nextchoice->getColumn());

    result.first = (nextchoice->getRow() - current->getRow()) / abs(nextchoice->getRow() - current->getRow());
    result.second = (nextchoice->getColumn() - current->getColumn()) / abs(nextchoice->getColumn() - current->getColumn());

    if(nextchoice->getBead()->getBeadColor() == current->getBead()->getBeadColor())
    {
        N.removeOne(temp);
    }

    temp = temp + result;

    while(temp.InRange())
    {
        N.removeOne(temp);
        temp = temp + result;
    }

}
