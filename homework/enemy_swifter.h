#ifndef ENEMY_SWIFTER_H
#define ENEMY_SWIFTER_H
#include "enemy.h"

class enemy_swifter:public enemy
{
public:
    enemy_swifter();
    void updateposition();
    static int record_of_Interval;
};

#endif // ENEMY_SWIFTER_H
