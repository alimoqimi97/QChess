#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->MainWidget = new QWidget();
    this->MainLayout = new QGridLayout();
    this->Start = new QPushButton("Start",this);
    this->Quit = new QPushButton("Quit",this);
    this->ChessWindow = new GameWindow();
    this->WhiteName = new QLabel("WhitePlayerName: ");
    this->BlackName = new QLabel("BlackPlayerName: ");
    this->WhiteLine = new QLineEdit(this);
    this->BlackLine = new QLineEdit(this);
    this->form = new QFormLayout();

    this->WhiteName->setStyleSheet("color: white;font-family: MV Boli;font-weight: 500;font-size: 15px;border-width: 3px;border-style: solid;border-radius: 10px;border-color: white;padding: 4px;");
    this->BlackName->setStyleSheet("color: white;font-family: MV Boli;font-weight: 500;font-size: 15px;border-width: 3px;border-style: solid;border-radius: 10px;border-color: white;padding: 4px;");

    this->WhiteLine->setStyleSheet("font-family: MV Boli;border-color: white;border-width: 3px;border-radius: 10px;border-style: solid;padding: 4px;color: lightblue;font-size: 15px;font-weight: 500;");
    this->BlackLine->setStyleSheet("font-family: MV Boli;border-color: white;border-width: 3px;border-radius: 10px;border-style: solid;padding: 4px;color: lightblue;font-size: 15px;font-weight: 500;");


    this->form->addRow(WhiteName,this->WhiteLine);
    this->form->addRow(this->BlackName,this->BlackLine);

    Start->setStyleSheet("color: white;background-color: green;font-family: MV Boli;border-width: 3px;border-radius: 10px;border-style: solid;border-color: green;padding: 2px;font-size: 15px;font-weight: 500;");
    Quit->setStyleSheet("color: white;font-family: MV Boli;padding: 2px;border-width: 3px;border-color: red;border-style: solid;border-radius: 10px;background-color: red;font-size: 15px;font-weight: 500;");

    this->connect(Start,SIGNAL(pressed()),this,SLOT(OpenGameWindow()));
    this->connect(Quit,SIGNAL(pressed()),this,SLOT(close()));

    this->MainLayout->addWidget(Start,10,10,15,10);
    this->MainLayout->addWidget(Quit,10,20,15,10);
    this->MainLayout->addLayout(this->form,8,10,20,20);
    this->MainWidget->setLayout(MainLayout);
    this->setCentralWidget(MainWidget);
}

MainWindow::~MainWindow()
{
    delete this->MainLayout;
    delete this->MainWidget;
    delete this->Start;
    delete this->Quit;
    delete this->ChessWindow;
    delete this->WhiteName;
    delete this->BlackName;
    delete this->WhiteLine;
    delete this->BlackLine;
    delete this->form;
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
//    this->ChessWindow->ChessGame->setBlackPlayerName(this->BlackLine->text());
//    this->ChessWindow->ChessGame->setWhitePlayerName(this->WhiteLine->text());
    this->ChessWindow->showMaximized();
    //    this->ChessWindow->show();
}
