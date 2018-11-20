#ifndef ROOK_H
#define ROOK_H

#include "bead.h"
#include "board.h"
//#include <QObject>

class Rook : public Bead
{
//    Q_OBJECT
public:
//    explicit Rook(QObject *parent = 0);
    Rook();

    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);

//signals:

//public slots:

};

#endif // ROOK_H
