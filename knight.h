#ifndef KNIGHT_H
#define KNIGHT_H

#include "bead.h"
#include "boardposition.h"

//#include "board.h"
//#include <QObject>

class Board;

class Knight : public Bead
{
//    Q_OBJECT
public:
//    explicit Knight(QObject *parent = 0);
    Knight();
    Knight(int c);


//    bool ControlBead(Board & b,BoardPosition bp);

    BoardPosition MakePos(int row,int col,BoardPosition cp);

    void  InsertInList(int r, int col, QList<BoardPosition> & n, BoardPosition &c);

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);
    virtual bool Check( BoardPosition &kingpos, BoardPosition &curpos);

//signals:

//public slots:

};

#endif // KNIGHT_H
