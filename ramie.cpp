#include "ramie.h"

ramie::ramie(int l1, int l2, QPoint poczatek)
{
    k = new kinematyka(l1, l2, poczatek);
    p0 = poczatek;
}

ramie::~ramie()
{
    delete k;
}

void ramie::ustaw(QPoint p)
{
    p1 = k->przelicz(p);

    if( p1.isNull() ) return;

    p1.setX( p1.x() + p0.x() );
    p1.setY( p0.y() - p1.y() );


    emit rysuj(p0, p1, p);
}
