#ifndef KING_H
#define KING_H

#include "bead.h"
#include "boardposition.h"

class Board;

class King : public Bead
{
public:
    King();
    King(int c);

//    bool isInCheckDanger(BoardPosition & target)
//    {
////        return (this->RightDiagonal(b) | ...
//    }

//    void FilterChoices(QList<BoardPosition> & n);
    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);
//    virtual bool Check( BoardPosition &kingpos, BoardPosition &curpos)
//    {

//    }

};

#endif // KING_H
