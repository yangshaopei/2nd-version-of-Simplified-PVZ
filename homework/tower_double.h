#ifndef TOWER_DOUBLE_H
#define TOWER_DOUBLE_H
#include "tower.h"

class tower_double:public tower
{
public:
    tower_double();
    void shoot();
    bullet_basic bullets[bullet_Total];
};

#endif // TOWER_DOUBLE_H
