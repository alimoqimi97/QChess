#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "boardposition.h"
#include <QObject>

class Movement : public QObject
{
    Q_OBJECT

private:
    int bead;
    BoardPosition * CurrentPos;
    BoardPosition * NextPos;

public:
    explicit Movement(QObject *parent = 0);

    Movement(const Movement & other);

    //          get and set methods     //
    void setbead(const int b);
    int getbead()const;

    void setCurrentPos(BoardPosition const * current);
    BoardPosition *getCurrentPos() const;

    void setNextPos(BoardPosition const * next);
    BoardPosition * getNextPos() const;

    //          ==================      //


    //          public functions        //

    Movement operator=(const Movement & other);

signals:

public slots:

};

#endif // MOVEMENT_H
