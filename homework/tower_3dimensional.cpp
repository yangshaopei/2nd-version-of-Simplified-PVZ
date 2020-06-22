#include "tower_3dimensional.h"

tower_3dimensional::tower_3dimensional()
{
   picture.load(tower_3dimensional_Path);
}

void tower_3dimensional::shoot(){
    record_of_Interval++;
    if(record_of_Interval<bullet_Interval){
        return;
    }
    else{
        record_of_Interval=0;
        for(int i=0;i<bullet_Total;i++){
            if(bullets[i].Free&&bullets[i+1].Free&&bullets[i+2].Free){
                bullets[i].Free=false;
                bullets[i].X=100+200*(column-1)+picture.width();
                bullets[i].Y=100+200*(row-1)-150;
                bullets[i+1].Free=false;
                bullets[i+1].X=100+200*(column-1)+picture.width();
                bullets[i+1].Y=100+200*(row-1);
                bullets[i+2].Free=false;
                bullets[i+2].X=100+200*(column-1)+picture.width();
                bullets[i+2].Y=100+200*(row-1)+250;
                return;
            }
        }
    }
}
