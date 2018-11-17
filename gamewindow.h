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
#include <vector>
using namespace std;

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGridLayout * GLayout;
    QWidget * GWidget;
    QPushButton * GClose;
    QGraphicsView * GameView;
    QGraphicsScene * GameScene;
    Chess * ChessGame;
//    vector<vector<QGraphicsRectItem *>> *Squares;


public:
    explicit GameWindow(QWidget *parent = 0);

    void CreateBoard();
    void CreateRow(QBrush first,QBrush last,int y);

    void FirstMoveLevel(BoardPosition * sel);
    void SecondMoveLevel(BoardPosition * sel);

    bool MovePicture(Movement & mv)
    {
        //          implementation...       //
    }

    void ShowSuggestedPos(QList<BoardPosition> & sl)
    {
        //          implementation...      //
    }

signals:

public slots:

    void MoveBead();
    void ResolveCheck();
};

#endif // GAMEWINDOW_H
