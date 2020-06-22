#ifndef TOWER_SLOWING_H
#define TOWER_SLOWING_H
#include "tower.h"
#include "bullet_slowing.h"

class tower_slowing:public tower
{
public:
    tower_slowing();
    void shoot();
    bullet_slowing bullets[bullet_Total];
};

#endif // TOWER_SLOWING_H
