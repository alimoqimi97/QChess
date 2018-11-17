#ifndef KNIGHT_H
#define KNIGHT_H

#include "bead.h"
#include <QObject>

class Knight : public QObject,Bead
{
    Q_OBJECT
public:
    explicit Knight(QObject *parent = 0);
    Knight();


    bool ControlBead(Board & b,BoardPosition bp);

    BoardPosition MakePos(int row,int col,BoardPosition cp);

    void  InsertInList(int r,int col,QList<BoardPosition> & n,BoardPosition &c,Board & B);

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos, Board &cboard);

signals:

public slots:

};

#endif // KNIGHT_H
