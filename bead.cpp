#include "bead.h"

//Bead::Bead(QObject *parent) :
//    QObject(parent)
//{
//}

Bead ::MyColor Bead::getBeadColor() const
{
    return BeadColor;
}

void Bead::setBeadColor(const int &value)
{
    BeadColor = (MyColor)value;
}

QList<BoardPosition> Bead::NextChoices(BoardPosition &CurPos)
{

}

bool Bead::Check(const BoardPosition &kingpos, const BoardPosition &curpos)
{

}

void Bead::setId(const int i)
{
    this->id = i;
}

int Bead::getId() const
{
    return this->id;
}
