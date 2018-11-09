#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->GLayout = new QGridLayout(this);
    this->GWidget = new QWidget(this);
    this->GClose = new QPushButton("Close");



    this->connect(this->GClose,SIGNAL(pressed()),this,SLOT(close()));

    this->GLayout->addWidget(GClose);
    this->GWidget->setLayout(GLayout);
    this->setCentralWidget(GWidget);

}


