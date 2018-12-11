#ifndef BOARDPOSITION_H
#define BOARDPOSITION_H

#include "bead.h"
#include <QGraphicsRectItem>

class Bead;

class BoardPosition
{
private:
    char Column;
    int Row;
    Bead * B;
    bool Full;

public:
    BoardPosition();

    //          get and set methods         //
    void setColumn(char col);
    char getColumn() const;

    void setRow(int row);
    int getRow() const;

    void setBead(Bead * b);
    Bead * getBead();

    void setFull(bool full);
    bool getFull();
    //          ==================          //

    bool IsFull();
    bool InRange();

    void DeleteBead();

    BoardPosition IncreaseRow(int r);
    BoardPosition DecreaseRow(int r);

    BoardPosition IncreaseCol(int c);
    BoardPosition DecreaseCol(int c);

    bool operator!=(BoardPosition & other);

    BoardPosition operator+(QPair<int,int> & p);

    bool operator==(const BoardPosition & other);

};


#endif // BOARDPOSITION_H
