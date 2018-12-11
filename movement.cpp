#include "movement.h"

//Movement::Movement(QObject *parent) :
//    QObject(parent)
//{
//}

//Movement::Movement(const Movement &other)
//{
//    this->bead = other.getbead();
//    this->CurrentPos = other.getCurrentPos();
//    this->NextPos = other.getNextPos();
//}

Movement::Movement() : bead(0) , CurrentPos(nullptr),NextPos(nullptr)
{

}

void Movement::setbead(int b)
{
    this->bead = b;
}

int Movement::getbead()
{
    return this->bead;
}

void Movement::setCurrentPos( BoardPosition *current)
{
    this->CurrentPos = current;
}

BoardPosition *Movement::getCurrentPos()
{
    return this->CurrentPos;
}

void Movement::setNextPos(BoardPosition *next)
{
    this->NextPos = next;
}

BoardPosition *Movement::getNextPos()
{
    return this->NextPos;
}

//Movement Movement::operator=(const Movement &other)
//{
//    this->bead = other.getbead();
//    this->CurrentPos = other.getCurrentPos();
//    this->NextPos = other.getNextPos();

//    return *this;
//}
