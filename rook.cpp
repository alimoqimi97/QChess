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

    a = CurPos;
    b = CurPos;

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

void Rook::DeletePoses(QList<BoardPosition> &N, BoardPosition *nextchoice, BoardPosition *current)
{
    BoardPosition temp;
    QPair<int,int> result;
    int div = 1;

    temp.setRow(nextchoice->getRow());
    temp.setColumn(nextchoice->getColumn());

    result.first = (nextchoice->getRow() - current->getRow());
    result.second = nextchoice->getColumn() - current->getColumn();

    if(result.first != 0)
    {
        div = abs(result.first);
    }
    else if(result.second != 0)
    {
        div = abs(result.second);
    }

    result.first = result.first / div;
    result.second = result.second / div;

    if(current->getBead()->getBeadColor() == nextchoice->getBead()->getBeadColor())
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
