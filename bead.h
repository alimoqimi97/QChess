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
//    Q_OBJECT

protected:
    int id;

public:
//    explicit Bead(QObject *parent = 0);

    enum MyColor{WHITE = 1,BLACK};

    //          get and set methods         //
    void setId(int const i);
    int getId()const;

    MyColor getBeadColor() const;
    void setBeadColor(const int &value);

    //          ===================         //

    virtual QList<BoardPosition> NextChoices(BoardPosition & CurPos);

    virtual bool Check(BoardPosition const & kingpos,
                       BoardPosition const & curpos) ;
//signals:
//public slots:
private:
    MyColor BeadColor;
};

#endif // BEAD_H
