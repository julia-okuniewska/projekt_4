#ifndef KINEMATYKA_H
#define KINEMATYKA_H

#include <QtCore>

class kinematyka
{
public:
    kinematyka(uint16_t l1, uint16_t l2, QPoint poczatek);
    QPoint przelicz(QPoint punkt );

private:
    QPoint poczatek;
    uint16_t l1, l2;
};

#endif // KINEMATYKA_H
