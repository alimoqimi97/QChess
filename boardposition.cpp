#include "boardposition.h"

//BoardPosition::BoardPosition(QObject *parent) :
//    QObject(parent)
//{
//}

//BoardPosition::BoardPosition(const BoardPosition &other)
//{
//    this->Column = other.getColumn();
//    this->Row = other.getRow();
//    this->B = other.getBead();
//    this->Full = other.getFull();
//}



void BoardPosition::setColumn(char col)
{
    this->Column = col;
}

char BoardPosition::getColumn() const
{
    return this->Column;
}

void BoardPosition::setRow(int row)
{
    this->Row = row;
}

int BoardPosition::getRow() const
{
    return this->Row;
}

void BoardPosition::setBead(Bead *b)
{
    this->B = b;
}

Bead *BoardPosition::getBead()
{
    return this->B;
}

void BoardPosition::setFull(bool full)
{
    this->Full = full;
}

bool BoardPosition::getFull()
{
    return this->Full;
}

bool BoardPosition::IsFull()
{
    return this->Full;
}

bool BoardPosition::InRange()
{
    if(this->Row > 0 & this->Row < 9 & this->Column >= 'A'&this->Column <= 'H')
    {
        return true;
    }
    return false;
}

void BoardPosition::DeleteBead()
{
    delete this->B;
}

BoardPosition BoardPosition::IncreaseRow(int r)
{
    BoardPosition b;

    b.setRow(this->Row + r);
    b.setColumn(this->Column);
    b.setBead(this->B);
    b.setFull(this->Full);

    return b;
}

BoardPosition BoardPosition::DecreaseRow(int r)
{
    BoardPosition b;

    b.setRow(this->Row - r);
    b.setColumn(this->Column);
    b.setBead(this->B);
    b.setFull(this->Full);

    return b;

//    return BoardPosition(this->Row - r,this->Column,this);
}

BoardPosition BoardPosition::IncreaseCol(int c)
{
    BoardPosition b;

    b.setRow(this->Row);
    b.setColumn(this->Column + c);
    b.setBead(this->B);
    b.setFull(this->Full);

    return b;
}

BoardPosition BoardPosition::DecreaseCol(int c)
{
    BoardPosition b;

    b.setRow(this->Row);
    b.setColumn(this->Column - c);
    b.setBead(this->B);
    b.setFull(this->Full);

    return b;
}

//QGraphicsRectItem BoardPosition::toRect(QGraphicsRectItem & r)
//{
//    QGraphicsRectItem r(this->Column - 365,this->Row - 301,75,75);
//}

//BoardPosition BoardPosition::operator=(const BoardPosition &other)
//{
//    this->Column = other.getColumn();
//    this->Row = other.getRow();
//    this->B = other.getBead();
//    this->Full = other.getFull();

//    return *this;
//}

bool BoardPosition::operator==(const BoardPosition &other)
{
    if(this->Row == other.getRow() && this->Column == other.getColumn())
    {
        return true;
    }
    return false;
}
