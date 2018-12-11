#ifndef CHESS_H
#define CHESS_H

#include "board.h"
#include <QObject>
#include <QString>

enum Turn{WHITE_P = 1,BLACK_P};
enum Winner{WHITEPLAYER,BLACKPLAYER};

class Chess : public QObject
{
    Q_OBJECT
private:

    Turn turn;
    Winner winner;
    Board ChessBoard;
    QString WhitePlayerName,BlackPlayerName;
    QList<Movement> BlackPlayerLastMoves,WhitePlayerLastMoves;
    QList<BoardPosition> NextMoves;

public:
    explicit Chess(QObject *parent = 0);


    //          get and set methods         //


    Board getChessBoard() const;
    void setChessBoard(const Board &value);

    QList<BoardPosition> getNextMoves() const;
    void setNextMoves(const QList<BoardPosition> &value);

    QString getWhitePlayerName() const;
    void setWhitePlayerName(const QString &value);

    QString getBlackPlayerName() const;
    void setBlackPlayerName(const QString &value);

    QList<Movement> getBlackLastMoves() const;
    void setBlackLastMoves(const QList<Movement> &value);

    QList<Movement> getWhitePlayerLastMoves() const;
    void setWhitePlayerLastMoves(const QList<Movement> &value);

    Turn getTurn() const;
    void setTurn(const Turn &value);
    //          =================          //

    //          public functions...           //

    BoardPosition * FindPosition(BoardPosition & f);
    bool NextMovesIsEmpty();
    bool NextMovesContains(BoardPosition * b);
    void ClearNextMoves();

    void ChangeTurn();

    bool WhoseTurnIsIt(BoardPosition & selectedpos);

    QList<BoardPosition> nextChoices(BoardPosition  & currpos);

    void Move(Movement & m);

    void AddToLastMoves(Movement & m);

    void AddToNextMoves(QList<BoardPosition> & nm);

    Movement &LastMove();

    void CleanExtraPos(QList<BoardPosition> & n,bool isfull,BoardPosition B);

    QList<BoardPosition> FilterChoices(QList<BoardPosition> np);

signals:

    void GameOver();
    void KingIsChecked();
    void TurnChanged();

public slots:

};

#endif // CHESS_H
