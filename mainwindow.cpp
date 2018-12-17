#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->MainWidget = new QWidget();
    this->MainLayout = new QGridLayout();
    this->Start = new QPushButton("Start",this);
    this->Quit = new QPushButton("Quit",this);
    this->ChessWindow = new GameWindow();


//    this->ChessWindow->setStyleSheet("background-color: white;");
    Start->setStyleSheet("color: white;background-color: green;font-family: arial;");
    Quit->setStyleSheet("color: white;background-color: red;font-family: Bold arial;");
//    this->ChessWindow->resize(600,450);

    this->connect(Start,SIGNAL(pressed()),this,SLOT(OpenGameWindow()));
    this->connect(Quit,SIGNAL(pressed()),this,SLOT(close()));

    this->MainLayout->addWidget(Start,10,10);
    this->MainLayout->addWidget(Quit,10,20);
    this->MainWidget->setLayout(MainLayout);
    this->setCentralWidget(MainWidget);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setMainLayout(QGridLayout *mn)
{
    this->MainLayout = mn;
}

QGridLayout *MainWindow::getMainLayout()
{
    return this->MainLayout;
}

void MainWindow::setmainWidget(QWidget *mw)
{
    this->MainWidget = mw;
}

QWidget *MainWindow::getMwidget()
{
    return this->MainWidget;
}

void MainWindow::setChessWindow(GameWindow *cw)
{
    this->ChessWindow = cw;
}

GameWindow *MainWindow::getChessWindow()
{
    return this->ChessWindow;
}

void MainWindow::setStart(QPushButton *st)
{
    this->Start = st;
}

QPushButton *MainWindow::getStart()
{
    return this->Start;
}

void MainWindow::setQuit(QPushButton *qu)
{
    this->Quit = qu;
}

QPushButton *MainWindow::getQuit()
{
    return this->Quit;
}

void MainWindow::OpenGameWindow()
{
    this->ChessWindow->showMaximized();
    //    this->ChessWindow->show();
}
