#-------------------------------------------------
#
# Project created by QtCreator 2018-11-09T19:06:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QChess
TEMPLATE = app

CONFIG  += C++11


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewindow.cpp

HEADERS  += mainwindow.h \
    gamewindow.h

RESOURCES += \
    BeadPics.qrc
