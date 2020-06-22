#ifndef TOWER_H
#define TOWER_H
#include <QPixmap>
#include "config.h"
#include "bullet_basic.h"

class tower
{
public:
    tower();
    virtual void shoot()=0;
    bool inuse=false;
    int row,column;
    QPixmap picture;
    int record_of_Interval=0;
};

#endif // TOWER_H
