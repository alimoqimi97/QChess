#include "queen.h"

//Queen::Queen(QObject *parent) :
//    QObject(parent)
//{
//}

Queen::Queen()
{
    this->id = 2;
}

Queen::Queen(int c)
{
    this->id = 2;
    this->setBeadColor(c);
}

QList<BoardPosition> Queen::NextChoices(BoardPosition &CurPos)
{
    Rook r;
    Bishop b;

    return r.NextChoices(CurPos) + b.NextChoices(CurPos);
}

bool Queen::Check(BoardPosition &kingpos, BoardPosition &curpos)
{
    Rook r;
    Bishop b;

    return (r.Check(kingpos,curpos) | b.Check(kingpos,curpos));
}

void Queen::DeletePoses(QList<BoardPosition> &N, BoardPosition *nextchoice, BoardPosition *current)
{
    Bishop b;
    Rook r;

    if((nextchoice->getRow() ==  current->getRow()) || (nextchoice->getColumn() == current->getColumn()))
    {
        r.DeletePoses(N,nextchoice,current);
    }
    else
    {
        b.DeletePoses(N,nextchoice,current);
    }
}
