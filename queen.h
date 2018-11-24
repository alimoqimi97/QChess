#ifndef QUEEN_H
#define QUEEN_H


#include "bead.h"
#include "boardposition.h"

//      Under testing part...       //
#include "rook.h"
#include "bishop.h"
//#include <QObject>

class Board;

class Queen : public Bead
{
//    Q_OBJECT
public:
//    explicit Queen(QObject *parent = 0);
    Queen();
    Queen(int c);

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos)
    {

    }
    virtual bool Check(BoardPosition &kingpos,BoardPosition &curpos);

//signals:

//public slots:

};

#endif // QUEEN_H
