#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "boardposition.h"
//#include <QObject>

class Movement
{
//    Q_OBJECT

private:
    int bead;
    BoardPosition * CurrentPos;
    BoardPosition * NextPos;

public:
//    explicit Movement(QObject *parent = 0);

//    Movement(const Movement & other);

    //          get and set methods     //
    void setbead(int b);
    int getbead();

    void setCurrentPos(BoardPosition *current);
    BoardPosition *getCurrentPos();

    void setNextPos(BoardPosition * next);
    BoardPosition * getNextPos();

    //          ==================      //


    //          public functions        //

//    Movement operator=(const Movement & other);

//signals:

//public slots:

};

#endif // MOVEMENT_H
