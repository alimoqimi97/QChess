#include "bead.h"

Bead::Bead(QObject *parent) :
    QObject(parent)
{
}

Bead ::MyColor Bead::getBeadColor() const
{
    return BeadColor;
}

void Bead::setBeadColor(const MyColor &value)
{
    BeadColor = value;
}

void Bead::setId(const int i)
{
    this->id = i;
}

int Bead::getId() const
{
    return this->id;
}
