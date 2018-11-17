#ifndef PAWN_H
#define PAWN_H

#include "bead.h"
#include <QObject>

class Pawn : public QObject,Bead
{
    Q_OBJECT

private:

public:
    explicit Pawn(QObject *parent = 0);
    Pawn();

    bool ControlBead(Board & cboard,BoardPosition & bp);

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos, Board &cboard);

signals:

public slots:

};

#endif // PAWN_H
