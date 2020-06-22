#include "bullet_basic.h"

bullet_basic::bullet_basic()
{
   picture.load(basicbullet_Path);
   Free=true;
   speed=bullet_Speed;
   rect.setWidth(picture.width());
   rect.setHeight(picture.height());
   rect.moveTo(X,Y);
}

void bullet_basic::updateposition(){
   if(Free) {

   }
   else {
       X=X+speed;
       rect.moveTo(X,Y);
   }

   if(X>game_Width) Free=true;
}
