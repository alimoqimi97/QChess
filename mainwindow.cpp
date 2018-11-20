#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->MainWidget = new QWidget(this);
    this->MainLayout = new QGridLayout(this);
    this->Start = new QPushButton("Start",this);
    this->Quit = new QPushButton("Quit",this);
    this->ChessWindow = new GameWindow();

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

void MainWindow::OpenGameWindow()
{
    this->ChessWindow->showMaximized();
//    this->ChessWindow->show();
}
