#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(500,450);
    w.setWindowTitle("Start page");
//    w.setStyleSheet("background-color: gray;");
    w.setStyleSheet("background-image:url(:/BeadPics/CI3.jpg);background-position: center;");


    w.show();

    //          debugging          //
    w.getChessWindow()->MoveBead();
//    w.getChessWindow()->MoveBead();
    //          =========           //

    return a.exec();
}
