#ifndef KING_H
#define KING_H

#include "bead.h"
#include <QObject>

class King : public QObject,Bead
{
    Q_OBJECT
public:
    explicit King(QObject *parent = 0);
    King();

signals:

public slots:

};

#endif // KING_H
