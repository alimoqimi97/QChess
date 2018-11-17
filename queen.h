#ifndef QUEEN_H
#define QUEEN_H


#include "bead.h"
#include <QObject>

class Queen : public QObject,Bead
{
    Q_OBJECT
public:
    explicit Queen(QObject *parent = 0);
    Queen();


signals:

public slots:

};

#endif // QUEEN_H
