#ifndef BEAD_H
#define BEAD_H

#include "board.h"
#include <QObject>

class BoardPosition;
class Board;


class Bead : public QObject
{
    Q_OBJECT

protected:
    int id;

public:
    explicit Bead(QObject *parent = 0);

    enum MyColor{WHITE = 1,BLACK};

    //          get and set methods         //
    void setId(int const i);
    int getId()const;

    MyColor getBeadColor() const;
    void setBeadColor(const MyColor &value);

    //          ===================         //

    virtual QList<BoardPosition> NextChoices(BoardPosition & CurPos,Board & cboard) = 0;
    virtual bool Check(BoardPosition const & kingpos,
                       BoardPosition const & curpos) = 0;


signals:

public slots:

private:
    MyColor BeadColor;
};

#endif // BEAD_H
