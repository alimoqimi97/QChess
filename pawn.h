#ifndef PAWN_H
#define PAWN_H

#include "bead.h"
#include "boardposition.h"
//#include "board.h"
//#include <QObject>

class Board;

class Pawn : public Bead
{
private:

public:
    //    explicit Pawn(QObject *parent = 0);
    Pawn();
    Pawn(int c);

    bool ControlBead(Board & cboard,BoardPosition & bp);

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);
    virtual bool Check(BoardPosition &kingpos, BoardPosition &curpos);

    virtual void DeletePoses(QList<BoardPosition> &N, BoardPosition *nextchoice, BoardPosition *current);
};


#endif // PAWN_H
