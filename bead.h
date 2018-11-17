#ifndef BEAD_H
#define BEAD_H

#include "board.h"
#include <QObject>

class BoardPosition;

enum Color{WHITE,BLACK};

class Bead : public QObject
{
    Q_OBJECT

private:
    Color BeadColor;

protected:
    int id;

public:
    explicit Bead(QObject *parent = 0);

    //          get and set methods         //
    void setId(int const i);
    int getId()const;

    Color getBeadColor() const;
    void setBeadColor(const Color &value);

    //          ===================         //

    virtual QList<BoardPosition> NextChoices(BoardPosition & CurPos,Board & cboard) = 0;
    virtual bool Check(BoardPosition const & kingpos,
                       BoardPosition const & curpos) = 0;


signals:

public slots:

};

#endif // BEAD_H
