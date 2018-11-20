#include "chess.h"

Chess::Chess(QObject *parent) :
    QObject(parent)
{
}

Turn Chess::getTurn() const
{
    return turn;
}

void Chess::setTurn(const Turn &value)
{
    turn = value;
}

QList<Movement> Chess::getBlackLastMoves() const
{
    return BlackPlayerLastMoves;
}

void Chess::setBlackLastMoves(const QList<Movement> &value)
{
    BlackPlayerLastMoves = value;
}

QList<Movement> Chess::getWhitePlayerLastMoves() const
{
    return WhitePlayerLastMoves;
}

void Chess::setWhitePlayerLastMoves(const QList<Movement> &value)
{
    WhitePlayerLastMoves = value;
}

QString Chess::getWhitePlayerName() const
{
    return WhitePlayerName;
}

void Chess::setWhitePlayerName(const QString &value)
{
    WhitePlayerName = value;
}

QString Chess::getBlackPlayerName() const
{
    return BlackPlayerName;
}

void Chess::setBlackPlayerName(const QString &value)
{
    BlackPlayerName = value;
}

QList<BoardPosition> Chess::getNextMoves() const
{
    return NextMoves;
}

void Chess::setNextMoves(const QList<BoardPosition> &value)
{
    NextMoves = value;
}

BoardPosition *Chess::FindPos(BoardPosition &f)
{
    return this->ChessBoard.FindPos(f);
}

bool Chess::NextMovesIsEmpty()
{
    return this->NextMoves.isEmpty();
}

bool Chess::NextMovesContains(BoardPosition *b)
{
    return this->NextMoves.contains(*b);
}

void Chess::ClearNextMoves()
{
    this->NextMoves.clear();
}

void Chess::ChangeTurn()
{
    if(this->turn == BLACK_P)
    {
        this->turn = WHITE_P;
    }
    else
    {
        this->turn = BLACK_P;
    }
}

bool Chess::WhoseTurnIsIt(BoardPosition &selectedpos)
{
    Bead ::MyColor c;

    if(this->turn == BLACK_P)
    {
        c = Bead ::BLACK;
    }
    else
    {
        c = Bead ::WHITE;
    }

    return this->ChessBoard.PositionMatches(selectedpos,c);
}

QList<BoardPosition> Chess::nextChoices(BoardPosition &currpos)
{
    BoardPosition * f = this->FindPos(currpos);

    return this->FilterChoices(f->getBead()->NextChoices(*f));
}

void Chess::Move(Movement &m)
{
    BoardPosition * f = m.getCurrentPos();
    BoardPosition * l = m.getNextPos();
    BoardPosition kingPos;

    this->ChessBoard.Transfer(f,l);

    if(l->getBead()->getId() == 1)
    {
        //            int trn = 1;

        this->ChessBoard.setKingPos(l,turn);
        return;
    }

    if(this->turn == BLACK_P)
    {
        kingPos = *(ChessBoard.getBlackKingPos());
    }
    else
    {
        kingPos = *(ChessBoard.getWhiteKingPos());
    }

    if(l->getBead()->Check(kingPos,*l) & kingPos.getBead()->Check(kingPos,*l))
    {
        this->KingIsChecked();
    }
}

void Chess::AddToLastMoves(Movement &m)
{
    if(this->turn == WHITE_P)
    {
        this->WhitePlayerLastMoves.push_back(m);
    }
    else
    {
        this->BlackPlayerLastMoves.push_back(m);
    }
}

void Chess::AddToNextMoves(QList<BoardPosition> &nm)
{
    for(BoardPosition p : nm)
    {
        this->NextMoves.push_back(p);
    }
}

Movement &Chess::LastMove()
{
    if(this->turn == BLACK_P)
    {
        return this->BlackPlayerLastMoves.back();
    }
    else
    {
        return this->WhitePlayerLastMoves.back();
    }
}

void Chess::CleanExtraPos(QList<BoardPosition> &n, bool isfull, BoardPosition B)
{
    if(!isfull)
    {
        return;
    }

    while(B.InRange())
    {
        n.removeOne(B);
        B = B.IncreaseCol(1).IncreaseRow(1);
    }
}

QList<BoardPosition> &Chess::FilterChoices(QList<BoardPosition> np)
{
    BoardPosition * p;

    for(BoardPosition b : np)
    {
        p = this->ChessBoard.FindPos(b);
        this->CleanExtraPos(np,p->IsFull(),b);
    }

    return np;
}

Board Chess::getChessBoard() const
{
    return ChessBoard;
}

void Chess::setChessBoard(const Board &value)
{
    ChessBoard = value;
}
