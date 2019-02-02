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
    bool ischecked;
    QList<BoardPosition> checkDir;

public:
    explicit Chess(QObject *parent = 0);


    //          get and set methods         //

    Board getChessBoard() const;
    void setChessBoard(const Board &value);

    void setCheckDir(QList<BoardPosition> &l);
    QList<BoardPosition> getCheckDir();

    void setIsChecked(bool ic);
    bool getIsChecked();

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

    bool Move(Movement & m);

    void AddToLastMoves(Movement & m);

    void AddToNextMoves(QList<BoardPosition> & nm);

    Movement &LastMove();

    void CleanExtraPos(QList<BoardPosition> & n, BoardPosition *s, BoardPosition willremove);

    QList<BoardPosition> FilterChoices(QList<BoardPosition> np, BoardPosition *F);

    void EditChoices(QList<BoardPosition> &n,BoardPosition *curp);
    bool ExamineCheck(int Id,BoardPosition kingpos,BoardPosition current);

    bool IsInCheckDir(BoardPosition &trg);
    bool CheckDirIsEmpty();
    void ClearCheckDir();
    void AddToCheckDir(BoardPosition &trg);
    void MakeCheckDir(BoardPosition kp,BoardPosition &dist);

signals:

    void GameOver();
//    void KingIsChecked(int id,BoardPosition kp,BoardPosition current);
    void TurnChanged();

public slots:

};

#endif // CHESS_H
