#include "board.h"

Board::Board(QObject *parent) :
    QObject(parent)
{
}

Board::Board(const Board &other) :QObject(this)
{
    //          how to assign an array to another array ?   //
//    this->CBoard = other.CBoard;
    this->BlackKingPos = other.getBlackKingPos();
    this->WhiteKingPos = other.getWhiteKingPos();
}

bool Board::PositionIsEmpty(BoardPosition &selectedpos)
{
    return !(FindPos(selectedpos)->IsFull());
}

bool Board::PositionMatches(BoardPosition &pos, Bead::MyColor bc)
{
    return (this->FindPos(pos)->getBead()->getBeadColor() == bc);
}

void Board::Transfer(BoardPosition *F, BoardPosition *L)
{
    if(L->IsFull())
    {
        L->DeleteBead();
    }

    L->setBead(F->getBead());
    F->setBead(nullptr);
    F->setFull(false);
}

BoardPosition *Board::FindPos(BoardPosition &target)
{
    int row = target.getRow() - 1;
    int coln = target.getColumn() - 65;

    return (*(CBoard + row) + coln);
}

void Board::setKingPos(BoardPosition *kp, int t)
{
    if(t == 1)
    {
        this->WhiteKingPos = kp;
    }
    else
    {
        this->BlackKingPos = kp;
    }
}

Board Board::operator=(const Board &other)
{
    //      how to assign an array to another array ?   //
//    this->CBoard = other.CBoard;
    this->BlackKingPos = other.getBlackKingPos();
    this->WhiteKingPos = other.getWhiteKingPos();

    return *this;
}

BoardPosition *Board::getBlackKingPos() const
{
    return BlackKingPos;
}

void Board::setBlackKingPos(BoardPosition *value)
{
    BlackKingPos = value;
}

BoardPosition *Board::getWhiteKingPos() const
{
    return WhiteKingPos;
}

void Board::setWhiteKingPos(BoardPosition *value)
{
    WhiteKingPos = value;
}
