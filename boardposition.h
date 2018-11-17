#ifndef BOARDPOSITION_H
#define BOARDPOSITION_H

#include "bead.h"
#include <QObject>
#include <QGraphicsRectItem>

class BoardPosition : public QObject
{
    Q_OBJECT

private:
    char Column;
    int Row;
    Bead * B;
    bool Full;

public:
    explicit BoardPosition(QObject *parent = 0);

    BoardPosition(const BoardPosition & other);

    //          get and set methods         //
    void setColumn(char col);
    char getColumn();

    void setRow(int row);
    int getRow();

    void setBead(Bead const * b);
    Bead * getBead() const;

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


    QGraphicsRectItem toRect();

    BoardPosition operator=(const BoardPosition & other);
    bool operator==(const BoardPosition & other);

signals:

public slots:

};


#endif // BOARDPOSITION_H
