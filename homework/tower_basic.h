#ifndef TOWER_BASIC_H
#define TOWER_BASIC_H
#include "tower.h"

class tower_basic:public tower
{
public:
    tower_basic();
    void shoot();
    bullet_basic bullets[bullet_Total];
};


#endif // TOWER_BASIC_H
