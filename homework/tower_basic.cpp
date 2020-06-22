#include "tower_basic.h"

tower_basic::tower_basic()
{
  picture.load(tower_basic_Path);
}

void tower_basic::shoot(){
   record_of_Interval++;
   if(record_of_Interval<bullet_Interval){
       return;
   }
   else{
       record_of_Interval=0;
       for(int i=0;i<bullet_Total;i++){
           if(bullets[i].Free){
               bullets[i].Free=false;
               bullets[i].X=100+200*(column-1)+picture.width();
               bullets[i].Y=100+200*(row-1);
               return;
           }
       }
   }
}
