#include "enemy_stronger.h"

enemy_stronger::enemy_stronger()
{
    picture.load(enemy_stronger_Path);
    rect.setWidth(picture.width());
    rect.setHeight(picture.height());
    rect.moveTo(X,Y);
    life=enemy_stronger_Life;
}

void enemy_stronger::updateposition(){
    if(Free){
        return;
    }
    else{
        X=X-speed;
        rect.moveTo(X,Y);
        if(X<=0) exit(0);
    }
}
