#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(500,450);
    w.setWindowTitle("Start page");
    w.show();

    //          debugging movebead()...            //
//    w.ChessWindow->GameScene->selectionChanged();
    //          ============            //

    return a.exec();
}
