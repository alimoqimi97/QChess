#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QGridLayout * MainLayout;
    QWidget * MainWidget;
    QPushButton * Start;
    QMainWindow * GameWindow;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:


public slots:
    void  OpenGameWindow();

};

#endif // MAINWINDOW_H
