#ifndef ROOK_H
#define ROOK_H

#include "bead.h"
#include "boardposition.h"

//#include "board.h"
//#include <QObject>

class Board;

class Rook : public Bead
{
//    Q_OBJECT
public:
//    explicit Rook(QObject *parent = 0);
    Rook();
    Rook(int c);

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);
    virtual bool Check(BoardPosition &kingpos,BoardPosition &curpos);

    virtual void DeletePoses(QList<BoardPosition> &N, BoardPosition *nextchoice, BoardPosition *current);

//signals:

//public slots:

};

#endif // ROOK_H
