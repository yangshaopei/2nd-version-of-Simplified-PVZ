#ifndef ENEMY_STRONGER_H
#define ENEMY_STRONGER_H
#include "enemy.h"
#include "config.h"

class enemy_stronger:public enemy
{
public:
    enemy_stronger();
    void updateposition();
    static int record_of_Interval;
};

#endif // ENEMY_STRONGER_H
