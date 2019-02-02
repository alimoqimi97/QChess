#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "chess.h"
#include <iostream>
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
#include <QHBoxLayout>
#include <QFont>
#include <QLabel>
using namespace std;


typedef QVector<QVector<QGraphicsRectItem * >> VOV;

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGridLayout * GLayout;
    QHBoxLayout * TurnLayout;
    QLabel * TurnLabel;
    QFont * TurnFont;
    QWidget * GWidget;
    QPushButton * GClose;
    QGraphicsView * GameView;
    QGraphicsScene * GameScene;
    Chess * ChessGame;
    QVector<QVector<QGraphicsRectItem *>> * Squares;

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

    //          get and set methods         //
    void setSquares(VOV * sq);
    VOV * getSquares();

    void CreateBoard();
    void CreateRow(QBrush first,QBrush last,int y);

    void FirstMoveLevel(BoardPosition * sel);
    void SecondMoveLevel(BoardPosition * sel);

    void MovePicture(Movement & mv);

    void ShowSuggestedPos(QList<BoardPosition> & sl, Qt::GlobalColor c);
    void RestoreSuggestedPos(QList<BoardPosition> sl);

    void RestoreCurrentPosBrush(Movement & m);

    void InsertBeadPictures();


signals:

public slots:

    void MoveBead();
    void ResolveCheck();
    void ModifyTurn();
};

#endif // GAMEWINDOW_H
