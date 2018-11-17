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
    gamewindow.cpp \
    chess.cpp \
    board.cpp \
    bead.cpp \
    movement.cpp \
    boardposition.cpp \
    pawn.cpp \
    knight.cpp \
    rook.cpp \
    bishop.cpp \
    king.cpp \
    queen.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    chess.h \
    board.h \
    bead.h \
    movement.h \
    boardposition.h \
    pawn.h \
    knight.h \
    rook.h \
    bishop.h \
    king.h \
    queen.h

RESOURCES += \
    BeadPics.qrc
