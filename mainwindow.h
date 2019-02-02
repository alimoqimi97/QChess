#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamewindow.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QMainWindow>
#include <QLineEdit>
#include <QFormLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QGridLayout * MainLayout;
    QWidget * MainWidget;
    QPushButton * Start;
    QPushButton * Quit;
    GameWindow * ChessWindow;
    QLabel *WhiteName;
    QLabel *BlackName;
    QLineEdit *WhiteLine;
    QLineEdit *BlackLine;
    QFormLayout *form;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //       get and set methods        //
    void setMainLayout(QGridLayout * mn);
    QGridLayout * getMainLayout();

    void setmainWidget(QWidget * mw);
    QWidget * getMwidget();

    void setChessWindow(GameWindow * cw);
    GameWindow * getChessWindow();

    void setStart(QPushButton * st);
    QPushButton * getStart();

    void setQuit(QPushButton * qu);
    QPushButton *getQuit();

signals:


public slots:
    void  OpenGameWindow();

};

#endif // MAINWINDOW_H
