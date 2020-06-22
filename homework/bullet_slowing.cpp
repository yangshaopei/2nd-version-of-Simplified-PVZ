#include "bullet_slowing.h"

bullet_slowing::bullet_slowing()
{
    picture.load(slowingbullet_Path);
    Free=true;
    speed=bullet_Speed;
    rect.setWidth(picture.width());
    rect.setHeight(picture.height());
    rect.moveTo(X,Y);
}

void bullet_slowing::updateposition(){
   if(Free) {

   }
   else {
       X=X+speed;
       rect.moveTo(X,Y);
   }

   if(X>game_Width) Free=true;
}
