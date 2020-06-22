#ifndef BULLET_H
#define BULLET_H
#include "config.h"
#include <QPixmap>
#include <QRect>

class bullet_basic
{
public:
    bullet_basic();
    void updateposition();
    QPixmap picture;
    int X;
    int Y;
    int speed;
    bool Free;
    QRect rect;
};

#endif // BULLET_H
