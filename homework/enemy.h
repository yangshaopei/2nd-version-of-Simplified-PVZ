#ifndef ENEMY_H
#define ENEMY_H
#include <QPixmap>
#include "config.h"
#include <QRect>

class enemy
{
public:
    enemy();
    virtual void updateposition()=0;
    int X,Y;
    bool Free=true;
    QPixmap picture;
    QRect rect;
    double speed=enemy_Normalspeed;
    int life;
};

#endif // ENEMY_H
