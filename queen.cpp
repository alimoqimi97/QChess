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

bool Queen::Check(BoardPosition &kingpos, BoardPosition &curpos)
{
    Rook r;
    Bishop b;

    return (r.Check(kingpos,curpos) | b.Check(kingpos,curpos));
}
