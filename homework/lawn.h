#ifndef LAWN_H
#define LAWN_H
#include <QPixmap>

class lawn
{
public:
    lawn();
    double xn,yn;
    bool inuse=false;
    QPixmap picture;
};

#endif // LAWN_H
