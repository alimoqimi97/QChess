#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(500,450);
    w.setWindowTitle("Start page");
    w.show();

    //          debugging           //
//    w.getChessWindow()->MoveBead();
    //          =========           //

    return a.exec();
}
