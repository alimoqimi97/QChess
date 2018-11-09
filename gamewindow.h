#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>

class GameWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGridLayout * GLayout;
    QWidget * GWidget;
    QPushButton * GClose;

public:
    explicit GameWindow(QWidget *parent = 0);

signals:

public slots:

};

#endif // GAMEWINDOW_H
