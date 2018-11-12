#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

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
    vector<vector<QGraphicsRectItem *>> *Squares;


public:
    explicit GameWindow(QWidget *parent = 0);

    void CreateBoard();
    void CreateRow(QBrush first,QBrush last,int y);

signals:

public slots:

};

#endif // GAMEWINDOW_H
