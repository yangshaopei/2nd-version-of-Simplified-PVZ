#include "enemy_basic.h"

enemy_basic::enemy_basic()
{
  picture.load(enemy_basic_Path);
  rect.setWidth(picture.width());
  rect.setHeight(picture.height());
  rect.moveTo(X,Y);
  life=enemy_basic_Life;
}

void enemy_basic::updateposition(){
    if(Free){
        return;
    }
    else{
        X=X-speed;
        rect.moveTo(X,Y);
        if(X<=0) exit(0);
    }
}
