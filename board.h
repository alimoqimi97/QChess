#ifndef BOARD_H
#define BOARD_H

#include "movement.h"
#include "boardposition.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include <QObject>

//class Pawn;

class Board : public QObject
{
    Q_OBJECT

private:
    BoardPosition * BlackKingPos,* WhiteKingPos;

public:
    //          public member       //
    BoardPosition CBoard[8][8];
    //          ============        //

    //              public functions        //
    explicit Board(QObject *parent = 0);

    Board(const Board & other);

    void InitializeBoard();

    bool PositionIsEmpty(BoardPosition & selectedpos);
    bool PositionMatches(BoardPosition & pos, int bc);

    void Transfer(BoardPosition * F,BoardPosition * L);

    void CreatePawns();
    void CreateRooks();
    void CreateKnights();
    void CreateBishops();
    void CreateKings();
    void CreateQueens();

    bool MakeChessPieces();

    BoardPosition * FindPos(BoardPosition & target);

    void setKingPos(BoardPosition * kp,int t);

    Board operator=(const Board & other);

    //           get and set methods            //
    BoardPosition *getBlackKingPos() const;
    void setBlackKingPos(BoardPosition *value);

    BoardPosition *getWhiteKingPos() const;
    void setWhiteKingPos(BoardPosition *value);
    //          =====================           //

signals:

public slots:

};

#endif // BOARD_H
