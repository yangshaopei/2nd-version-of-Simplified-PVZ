#include "tower_double.h"

tower_double::tower_double()
{
  picture.load(tower_double_Path);
}

void tower_double::shoot(){
    record_of_Interval++;
    if(record_of_Interval<bullet_Interval){
        return;
    }
    else{
        record_of_Interval=0;
        for(int i=0;i<bullet_Total;i++){
            if(bullets[i].Free&&bullets[i+1].Free){
                bullets[i].Free=false;
                bullets[i].X=100+200*(column-1)+picture.width();
                bullets[i].Y=100+200*(row-1);
                bullets[i+1].Free=false;
                bullets[i+1].X=200*(column-1)+picture.width();
                bullets[i+1].Y=100+200*(row-1)+50;
                break;
            }
        }
    }
}
