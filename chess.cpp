#include "chess.h"

Chess::Chess(QObject *parent) :
    QObject(parent) , turn(WHITE_P),winner(WHITEPLAYER),ischecked(false)
{
//    this->connect(this,SIGNAL(KingIsChecked(int,BoardPosition,BoardPosition)),this,SLOT(ExamineCheck(int,BoardPosition,BoardPosition)));
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

BoardPosition *Chess::FindPosition(BoardPosition &f)
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

    this->TurnChanged();
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
    BoardPosition *f = this->FindPosition(currpos);

    return this->FilterChoices(f->getBead()->NextChoices(*f),f);
}

bool Chess::Move(Movement &m)
{
    BoardPosition * f = m.getCurrentPos();
    BoardPosition * l = m.getNextPos();
    BoardPosition kingPos;

    //          moving the bead to distination in board.     //
    this->ChessBoard.Transfer(f,l);

    //      changing the boardposition of king when it moves in chessboard  //
    if(l->getBead()->getId() == 1)
    {
        //            int trn = 1;
        this->ChessBoard.setKingPos(l,turn);
        return false;
    }

    //     < Examining check operation >      //

    //      selecting the kingpos according to turn     //
    if(this->turn == BLACK_P)
    {
        kingPos = *(ChessBoard.getBlackKingPos());
    }
    else
    {
        kingPos = *(ChessBoard.getWhiteKingPos());
    }

    //              king :: check() ==> king :: isInCheckDanger()
    if(l->getBead()->Check(kingPos,*l))
    {
//        this->KingIsChecked(l->getBead()->getId(),kingPos,*l);
        return this->ExamineCheck(l->getBead()->getId(),kingPos,*l);
    }

    return false;
}

void Chess::AddToLastMoves(Movement &m)
{
    if(this->turn == WHITE_P)
    {
        this->WhitePlayerLastMoves.push_back(m);
    }
    else if(this->turn == BLACK_P)
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

void Chess::CleanExtraPos(QList<BoardPosition> &n,BoardPosition *s, BoardPosition willremove)
{
    if(!s->IsFull())
    {
        return;
    }

    //          uncomplete ... it must write for other kind of beads    //


    //  out of range positions will remove from nextchoices list.    //
    //    while(B.InRange())
    //    {
    //        n.removeOne(B);
    //        B = B.IncreaseCol(1).IncreaseRow(1);
    //    }

    //    pawn editing      //
    //    if(s->getBead()->getId() == 3)
    //    {

    //    }


}

QList<BoardPosition> Chess::FilterChoices(QList<BoardPosition> np,BoardPosition *F)
{
    QList<BoardPosition>::iterator ritr;

    for(ritr = np.begin() ; ritr != np.end() ; ++ritr)
    {
        if(!ritr->InRange())
        {
            np.removeOne(*ritr);
        }
    }

    this->EditChoices(np,F);

    return np;
}

void Chess::EditChoices(QList<BoardPosition> &n, BoardPosition *curp)
{
//    QList<BoardPosition> ::iterator itr;
    BoardPosition *p(nullptr) ,*B(nullptr),*C(nullptr);

//    for(itr = n.begin() ; itr != n.end() && curp->getBead()->getId() != 3 ; ++itr)
//    {
//        // error is here..!
//        p = this->FindPosition(*itr);

//        if(!p->IsFull())
//        {
//            continue;
//        }

//        ++itr;
//        curp->getBead()->DeletePoses(n,p,curp);
//    }

    for(BoardPosition target: n)
    {
        if(!target.InRange())
        {
            break;
        }
        p = this->FindPosition(target);

        if(p->IsFull())
        {
            curp->getBead()->DeletePoses(n,p,curp);
        }
    }

    if(curp->getBead()->getId() == 3)
    {
        BoardPosition b(*curp),c(*curp);
        BoardPosition *u(nullptr);

        for(BoardPosition r : n)
        {
            u = this->FindPosition(r);

            if(u->IsFull())
            {
                n.removeOne(r);
            }
        }

        if(curp->getBead()->getBeadColor() == Bead ::WHITE)
        {
            b = b.DecreaseRow(1).IncreaseCol(1);
            c = c.DecreaseRow(1).DecreaseCol(1);
        }
        else if(curp->getBead()->getBeadColor() == Bead::BLACK)
        {
            b = b.IncreaseRow(1).DecreaseCol(1);
            c = c.IncreaseRow(1).IncreaseCol(1);
        }

        B = this->FindPosition(b);
        C = this->FindPosition(c);

        if(B->IsFull() && B->getBead()->getBeadColor() != curp->getBead()->getBeadColor())
        {
            n.push_back(b);
        }
        if(C->IsFull() && C->getBead()->getBeadColor() != curp->getBead()->getBeadColor())
        {
            n.push_back(c);
        }
    }
}

bool Chess::ExamineCheck(int Id, BoardPosition kingpos, BoardPosition current)
{
    if(Id == 3 || Id == 6)
    {
        return true;
    }
    return this->ChessBoard.SurveyForCheck(Id,kingpos,current);
}

bool Chess::IsInCheckDir(BoardPosition &trg)
{
    return this->checkDir.contains(trg);
}

bool Chess::CheckDirIsEmpty()
{
    return this->checkDir.isEmpty();
}

void Chess::ClearCheckDir()
{
    this->checkDir.clear();
}

void Chess::AddToCheckDir(BoardPosition &trg)
{
    this->checkDir.push_back(trg);
}

void Chess::MakeCheckDir(BoardPosition kp, BoardPosition &dist)
{
    QPair<int,int> dir;
    int div1(1),div2(1);

    div1 = abs(dist.getRow() - kp.getRow());
    div2 = abs(dist.getColumn() - kp.getColumn());

    if(div1 != 0)
    {
        div1 /= div1;
        div2 /= div2;
    }
    else if(div2 != 0)
    {
        div1 /= div2;
        div2 /= div2;
    }

    dir.first = div1;
    dir.second = div2;

    while(kp.InRange() && kp != dist)
    {
        kp = kp + dir;
        this->AddToCheckDir(kp);
    }
}

Board Chess::getChessBoard() const
{
    return ChessBoard;
}

void Chess::setChessBoard(const Board &value)
{
    ChessBoard = value;
}

void Chess::setCheckDir(QList<BoardPosition> &l)
{
    this->checkDir = l;
}

QList<BoardPosition> Chess::getCheckDir()
{
    return this->checkDir;
}

void Chess::setIsChecked(bool ic)
{
    this->ischecked = ic;
}

bool Chess::getIsChecked()
{
    return this->ischecked;
}
