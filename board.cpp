#include "board.h"

Board::Board(QObject *parent) :
    QObject(parent),BlackKingPos(nullptr),WhiteKingPos(nullptr)
{
    this->InitializeBoard();
    this->MakeChessPieces();
}

Board::Board(const Board &other) :QObject(this)
{
    //          how to assign an array to another array ?   //
//    this->CBoard = other.CBoard;
    this->BlackKingPos = other.getBlackKingPos();
    this->WhiteKingPos = other.getWhiteKingPos();
}

void Board::InitializeBoard()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            this->CBoard[i][j].setRow(i + 1);
            this->CBoard[i][j].setColumn(j + 65);
        }
    }
}

bool Board::PositionIsEmpty(BoardPosition &selectedpos)
{
    return !(FindPos(selectedpos)->IsFull());
}

bool Board::PositionMatches(BoardPosition &pos, int bc)
{
    return (this->FindPos(pos)->getBead()->getBeadColor() == bc);
}

void Board::Transfer(BoardPosition *F, BoardPosition *L)
{
    if(L->IsFull())
    {
        L->DeleteBead();
        L->setFull(false);
    }

    L->setBead(F->getBead());
    L->setFull(true);
    F->setBead(nullptr);
    F->setFull(false);
}

void Board::CreatePawns()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        this->CBoard[1][i].setBead(new Pawn(2));
        this->CBoard[1][i].setFull(true);
        this->CBoard[6][i].setBead(new Pawn(1));
        this->CBoard[6][i].setFull(true);
    }
}

void Board::CreateRooks()
{
    CBoard[0][0].setBead(new Rook(2));
    CBoard[0][0].setFull(true);

    CBoard[0][7].setBead(new Rook(2));
    CBoard[0][7].setFull(true);

    CBoard[7][0].setBead(new Rook(1));
    CBoard[7][0].setFull(true);

    CBoard[7][7].setBead(new Rook(1));
    CBoard[7][7].setFull(true);
}

void Board::CreateKnights()
{
    this->CBoard[0][1].setBead(new Knight(2));
    this->CBoard[0][1].setFull(true);

    this->CBoard[0][6].setBead(new Knight(2));
    this->CBoard[0][6].setFull(true);

    this->CBoard[7][1].setBead(new Knight(1));
    this->CBoard[7][1].setFull(true);

    this->CBoard[7][6].setBead(new Knight(1));
    this->CBoard[7][6].setFull(true);
}

void Board::CreateBishops()
{
    this->CBoard[0][2].setBead(new Bishop(2));
    this->CBoard[0][2].setFull(true);

    this->CBoard[0][5].setBead(new Bishop(2));
    this->CBoard[0][5].setFull(true);

    this->CBoard[7][2].setBead(new Bishop(1));
    this->CBoard[7][2].setFull(true);

    this->CBoard[7][5].setBead(new Bishop(1));
    this->CBoard[7][5].setFull(true);
}

void Board::CreateKings()
{
    this->CBoard[0][3].setBead(new King(2));
    this->CBoard[0][3].setFull(true);

    this->CBoard[7][3].setBead(new King(1));
    this->CBoard[7][3].setFull(true);

    this->BlackKingPos = *(CBoard + 0) + 3;
    this->WhiteKingPos = *(CBoard + 7) + 3;
}

void Board::CreateQueens()
{
    this->CBoard[0][4].setBead(new Queen(2));
    this->CBoard[0][4].setFull(true);

    this->CBoard[7][4].setBead(new Queen(1));
    this->CBoard[7][4].setFull(true);
}

void Board::MakeChessPieces()
{
    //Pawn...
    this->CreatePawns();

    //Rook...
    this->CreateRooks();

    //Knight...
    this->CreateKnights();

    //Bishop...
    this->CreateBishops();

    //King...
    this->CreateKings();

    //Queen...
    this->CreateQueens();

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

bool Board::SurveyForCheck(int beadId, BoardPosition kp, BoardPosition current)
{
    bool result = true;

    result = this->SeeDirections(beadId,kp,current);

    return result;
}

bool Board::SeeDirections(int bi, BoardPosition &kp, BoardPosition cur)
{
    QPair<int,int> direct;
    BoardPosition *p;
    bool res = true;
    BoardPosition temp = cur;
    int div1 = 1,div2 = 1;

    div1 = cur.getRow() - kp.getRow();
    div2 = cur.getColumn() - kp.getColumn();

    if(div1 != 0)
    {
        div1 /= abs(div1);
        div2 /= abs(div2);
    }
    else if(div2 != 0)
    {
        div1 /= abs(div2);
        div2 /= abs(div2);
    }


    direct.first = div1;
    direct.second = div2;

    p = this->FindPos(kp);

    while(*p != cur && res)
    {
        temp = temp + direct;
        p = this->FindPos(temp);

        res &= !p->IsFull();
    }

    return !res;
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
