#include "king.h"

//King::King(QObject *parent) :
//    QObject(parent)
//{
//}

King::King()
{
    this->id = 1;
}

King::King(int c)
{
    this->id = 1;
    this->setBeadColor(c);
}

//void King::FilterChoices(QList<BoardPosition> &n)
//{
//    for(BoardPosition b : n)
//    {
//        if(this->IsInCheckDanger(b))
//        {
//            n.removeOne(b);
//        }
//    }
//}

QList<BoardPosition> King::NextChoices(BoardPosition &CurPos)
{
    QList<BoardPosition> np;

    np.push_back(CurPos.IncreaseCol(1));
    np.push_back(CurPos.IncreaseRow(1));
    np.push_back(CurPos.DecreaseCol(1));
    np.push_back(CurPos.DecreaseRow(1));
    np.push_back(CurPos.IncreaseRow(1).IncreaseCol(1));
    np.push_back(CurPos.IncreaseCol(1).DecreaseRow(1));
    np.push_back(CurPos.DecreaseCol(1).DecreaseRow(1));
    np.push_back(CurPos.DecreaseCol(1).IncreaseRow(1));

//    this->FilterChoices(np);

    return np;
}
