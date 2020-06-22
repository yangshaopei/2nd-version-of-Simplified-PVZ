#include "enemy_summoner.h"

enemy_summoner::enemy_summoner()
{
    picture.load(enemy_summoner_Path);
    rect.setWidth(picture.width());
    rect.setHeight(picture.height());
    rect.moveTo(X,Y);
    life=enemy_summoner_Life;
}

void enemy_summoner::updateposition(){
    if(Free){
        return;
    }
    else{
        X=X-speed;
        rect.moveTo(X,Y);
        if(X<=0) exit(0);
    }
}

void enemy_summoner::summon(){
    if(firsttime){
    record_of_summon_Interval++;
    if(record_of_summon_Interval<enemy_summoner_Interval){

    }
    else{
        firsttime=false;
        record_of_summon_Interval=0;
        if(Y==300||Y==500){
        for(int i=0;i<12;i++){
            if(footmen[i].Free==true&&footmen[i+1].Free==true&&footmen[i+2].Free==true&&footmen[i+3].Free==true){
                footmen[i].Free=false;
                footmen[i].X=X-200;
                footmen[i].Y=Y;
                footmen[i+1].Free=false;
                footmen[i+1].X=X+200;
                footmen[i+1].Y=Y;
                footmen[i+2].Free=false;
                footmen[i+2].X=X;
                footmen[i+2].Y=Y-200;
                footmen[i+3].Free=false;
                footmen[i+3].X=X;
                footmen[i+3].Y=Y+200;
                return;
            }
            }
        }
        else{
            for(int i=0;i<12;i++){
                if(footmen[i].Free==true&&footmen[i+1].Free==true){
                    footmen[i].Free=false;
                    footmen[i].X=X-200;
                    footmen[i].Y=Y;
                    footmen[i+1].Free=false;
                    footmen[i+1].X=X+200;
                    footmen[i+1].Y=Y;
                    return;
        }
    }
}
}
}

}
