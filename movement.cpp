#include "movement.h"

Movement::Movement(QObject *parent) :
    QObject(parent)
{
}

Movement::Movement(const Movement &other)
{
    this->bead = other.getbead();
    this->CurrentPos = other.getCurrentPos();
    this->NextPos = other.getNextPos();
}

void Movement::setbead(const int b)
{
    this->bead = b;
}

int Movement::getbead() const
{
    return this->bead;
}

void Movement::setCurrentPos(const BoardPosition *current)
{
    this->CurrentPos = current;
}

BoardPosition *Movement::getCurrentPos() const
{
    return this->CurrentPos;
}

void Movement::setNextPos(const BoardPosition *next)
{
    this->NextPos = next;
}

BoardPosition *Movement::getNextPos() const
{
    return this->NextPos;
}

Movement Movement::operator=(const Movement &other)
{
    this->bead = other.getbead();
    this->CurrentPos = other.getCurrentPos();
    this->NextPos = other.getNextPos();

    return *this;
}
