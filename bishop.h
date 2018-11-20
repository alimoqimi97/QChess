#ifndef BISHOP_H
#define BISHOP_H

#include "bead.h"
#include "board.h"
//#include <QObject>

class Bishop : public Bead
{
//    Q_OBJECT
public:
//    explicit Bishop(QObject *parent = 0);
    Bishop();

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);

//signals:

//public slots:

};

#endif // BISHOP_H
