#ifndef BEAD_H
#define BEAD_H

//#include "board.h"
//#include <QObject>
//#include "boardposition.h"
#include <QList>

class BoardPosition;
class Board;


class Bead
{

protected:
    int id;

public:
    enum MyColor{WHITE = 1,BLACK};

    Bead();

    //          get and set methods         //
    void setId(int const i);
    int getId()const;

    MyColor getBeadColor() const;
    void setBeadColor(const int &value);

    //          ===================         //

    virtual QList<BoardPosition> NextChoices(BoardPosition & CurPos);

    virtual bool Check(BoardPosition & kingpos,
                       BoardPosition & curpos) ;
    virtual ~Bead()
    {

    }

private:
    MyColor BeadColor;
};

#endif // BEAD_H
