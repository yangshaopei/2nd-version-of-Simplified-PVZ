#ifndef TOWER_3DIMENSIONAL_H
#define TOWER_3DIMENSIONAL_H
#include "tower.h"

class tower_3dimensional:public tower
{
public:
    tower_3dimensional();
    void shoot();
    bullet_basic bullets[bullet_Total];
};

#endif // TOWER_3DIMENSIONAL_H
