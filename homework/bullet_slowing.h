#ifndef BULLET_SLOWING_H
#define BULLET_SLOWING_H
#include "config.h"
#include <QPixmap>
#include <QRect>

class bullet_slowing
{
public:
    bullet_slowing();
    void updateposition();
    QPixmap picture;
    int X;
    int Y;
    int speed;
    bool Free;
    QRect rect;
};

#endif // BULLET_SLOWING_H
