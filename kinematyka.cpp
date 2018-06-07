#include "kinematyka.h"

kinematyka::kinematyka( uint16_t l1, uint16_t l2, QPoint poczatek )
{
    this->l1 = l1;
    this->l2 = l2;

    this->poczatek = poczatek;
}

QPoint kinematyka::przelicz(QPoint punkt)
{
    int x = punkt.x();
    int y = punkt.y();

    x -= poczatek.x();
    y = poczatek.y()-y;

    double d = sqrt( x*x+y*y);

    if( d > l1+l2 || (x==0 && y==0) ) return QPoint(0,0);

    double A = (l1*l1+l2*l2-d*d)/(2*l1*l2);

    double fi1 = atan2( sqrt(1-A*A), A);

    double beta = atan2(y, x);

    double B = l1*sin(fi1)/d;
    double gamma = asin(B);

    double fi2 = beta+gamma;

    return QPoint( l1*cos(fi2), l1*sin(fi2) );
}
