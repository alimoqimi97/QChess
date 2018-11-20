#ifndef KING_H
#define KING_H

#include "bead.h"
#include "boardposition.h"
//#include <QObject>

class King : public Bead
{
//    Q_OBJECT
public:
//    explicit King(QObject *parent = 0);
    King();

//    bool isInCheckDanger(BoardPosition & target)
//    {
////        return (this->RightDiagonal(b) | ...
//    }

//    void FilterChoices(QList<BoardPosition> & n);
    virtual QList<BoardPosition> NextChoices(BoardPosition &CurPos);


//signals:

//public slots:

};

#endif // KING_H
