#ifndef ENEMY_BASIC_H
#define ENEMY_BASIC_H
#include "config.h"
#include "enemy.h"

class enemy_basic:public enemy
{
public:
    enemy_basic();
    void updateposition();
    static int record_of_Interval;
};

#endif // ENEMY_BASIC_H
