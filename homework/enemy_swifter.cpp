#include "enemy_swifter.h"

enemy_swifter::enemy_swifter()
{
    picture.load(enemy_swifter_Path);
    rect.setWidth(picture.width());
    rect.setHeight(picture.height());
    rect.moveTo(X,Y);
    speed=enemy_Swifterspeed;
    life=enemy_swifter_Life;
}

void enemy_swifter::updateposition(){
    if(Free){
        return;
    }
    else{
        X=X-speed;
        rect.moveTo(X,Y);
        if(X<=0) exit(0);
    }
}
