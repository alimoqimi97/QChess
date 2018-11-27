#ifndef BOARDPOSITION_H
#define BOARDPOSITION_H

#include "bead.h"
//#include <QObject>
#include <QGraphicsRectItem>

class Bead;

class BoardPosition
{
//    Q_OBJECT

private:
    char Column;
    int Row;
    Bead * B;
    bool Full;

public:
    BoardPosition();

//    explicit BoardPosition(QObject *parent = 0);

//    BoardPosition(const BoardPosition &other);

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

//    QGraphicsRectItem toRect(QGraphicsRectItem &r);

//    BoardPosition operator=(const BoardPosition & other);
    bool operator==(const BoardPosition & other);

//signals:

//public slots:

};


#endif // BOARDPOSITION_H
