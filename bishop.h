#ifndef BISHOP_H
#define BISHOP_H

#include "bead.h"
#include <QObject>

class Bishop : public QObject,Bead
{
    Q_OBJECT
public:
    explicit Bishop(QObject *parent = 0);
    Bishop();

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos, Board &cboard);

signals:

public slots:

};

#endif // BISHOP_H
