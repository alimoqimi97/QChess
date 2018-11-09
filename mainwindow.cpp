#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->MainWidget = new QWidget(this);
    this->MainLayout = new QGridLayout(this);
    this->Start = new QPushButton("Start",this);
    this->GameWindow = new QMainWindow(this);

    this->GameWindow->resize(400,350);


    this->connect(Start,SIGNAL(pressed()),this,SLOT(OpenGameWindow()));

    this->MainLayout->addWidget(Start);
    this->MainWidget->setLayout(MainLayout);
    this->setCentralWidget(MainWidget);

}

MainWindow::~MainWindow()
{

}

void MainWindow::OpenGameWindow()
{
    this->GameWindow->show();
}
