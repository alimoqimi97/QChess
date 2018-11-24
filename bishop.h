#ifndef BISHOP_H
#define BISHOP_H

#include "bead.h"
#include "boardposition.h"
#include <QPair>

//#include "board.h"
//#include <QObject>

class Board;

class Bishop : public Bead
{
//    Q_OBJECT
public:
//    explicit Bishop(QObject *parent = 0);
    Bishop();
    Bishop(int c);

    bool ExaminePath(int row,int col,BoardPosition kp,BoardPosition cp);

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);
    virtual bool Check( BoardPosition &kingpos,  BoardPosition &curpos);

//signals:

//public slots:

};

#endif // BISHOP_H
