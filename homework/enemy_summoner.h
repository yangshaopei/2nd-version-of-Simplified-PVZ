#ifndef ENEMY_SUMMONER_H
#define ENEMY_SUMMONER_H
#include "enemy.h"
#include "enemy_swifter.h"

class enemy_summoner:public enemy
{
public:
    enemy_summoner();
    void updateposition();
    static int record_of_Interval;
    int record_of_summon_Interval;
    void summon();
    enemy_swifter footmen[enemy_swifter_Total];
    bool firsttime=true;
};

#endif // ENEMY_SUMMONER_H
