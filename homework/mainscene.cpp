#include "mainscene.h"
#include <math.h>

//initializing static members
int enemy_basic::record_of_Interval=0;
int enemy_stronger::record_of_Interval=0;
int enemy_summoner::record_of_Interval=0;

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
    updateGame();
}

MainScene::~MainScene()
{
}

void MainScene::initScene(){
    setFixedSize(game_Width,game_Height);
    setWindowTitle(game_Title);
    setWindowIcon(QIcon(game_Iconpath));
    timer.setInterval(game_Rate);
    srand( (unsigned int) time(NULL));
}

void MainScene::paintEvent(QPaintEvent *){
    QPainter painter(this);
    int i,j;
    //paint map
    for(i=1;i<=4;i++){
        for(j=1;j<=4;j++){
            painter.drawPixmap(100+200*(i-1),100+200*(j-1),map[i][j].picture);
        }
    }
    painter.drawPixmap(100+200*(columnmark.x-1),0,columnmark.picture);
    painter.drawPixmap(0,100+200*(rowmark.y-1),rowmark.picture);

    //paint tower and bullet
    for(int k=0;k<tower_Total;k++){
        if(tower1[k].inuse) {
            painter.drawPixmap(100+200*(tower1[k].column-1),100+200*(tower1[k].row-1),tower1[k].picture);
            for(int j=0;j<bullet_Total;j++){
                if(tower1[k].bullets[j].Free==false){
                    painter.drawPixmap(tower1[k].bullets[j].X,tower1[k].bullets[j].Y,tower1[k].bullets[j].picture);
                    }
    }
        }
        }
    for(int k=0;k<tower_Total;k++){
        if(tower2[k].inuse) {
            painter.drawPixmap(100+200*(tower2[k].column-1),100+200*(tower2[k].row-1),tower2[k].picture);
            for(int j=0;j<bullet_Total;j++){
                if(tower2[k].bullets[j].Free==false){
                    painter.drawPixmap(tower2[k].bullets[j].X,tower2[k].bullets[j].Y,tower2[k].bullets[j].picture);
                    }
    }
    }
    }
    for(int k=0;k<tower_Total;k++){
        if(tower3[k].inuse) {
            painter.drawPixmap(100+200*(tower3[k].column-1),100+200*(tower3[k].row-1),tower3[k].picture);
            for(int j=0;j<bullet_Total;j++){
                if(tower3[k].bullets[j].Free==false){
                    painter.drawPixmap(tower3[k].bullets[j].X,tower3[k].bullets[j].Y,tower3[k].bullets[j].picture);
                    }
    }
    }
    }
    for(int k=0;k<tower_Total;k++){
        if(tower4[k].inuse) {
            painter.drawPixmap(100+200*(tower4[k].column-1),100+200*(tower4[k].row-1),tower4[k].picture);
            for(int j=0;j<bullet_Total;j++){
                if(tower4[k].bullets[j].Free==false){
                    painter.drawPixmap(tower4[k].bullets[j].X,tower4[k].bullets[j].Y,tower4[k].bullets[j].picture);
                    }
    }
    }
    }

    //paint enemy
    for(int k=0;k<enemy_basic_Total;k++){
        if(enemy1[k].Free==false){
            painter.drawPixmap(enemy1[k].X,enemy1[k].Y,enemy1[k].picture);
        }
    }
    for(int k=0;k<enemy_stronger_Total;k++){
        if(enemy2[k].Free==false){
            painter.drawPixmap(enemy2[k].X,enemy2[k].Y,enemy2[k].picture);
        }
    }
    for(int k=0;k<enemy_summoner_Total;k++){
        for(int c=0;c<enemy_swifter_Total;c++){
            if(enemy3[k].footmen[c].Free==false){
                painter.drawPixmap(enemy3[k].footmen[c].X,enemy3[k].footmen[c].Y,enemy3[k].footmen[c].picture);
            }
        }
        if(enemy3[k].Free==false){
            painter.drawPixmap(enemy3[k].X,enemy3[k].Y,enemy3[k].picture);

        }
    }
};

void MainScene::mouseMoveEvent(QMouseEvent *event){
    setMouseTracking(true);
    getSequence_ofbasin(event->x(),event->y());
    columnmark.x =Xof_basin;
    rowmark.y=Yof_basin;

}

void MainScene::mousePressEvent(QMouseEvent *event){
    //plant tower
    if(event->button() == Qt::LeftButton&&key==Qt::Key_1&&sequenceof_tower1<5&&map[Xof_basin][Yof_basin].inuse==false&&Xof_basin<5&&Yof_basin<5){
        tower1[sequenceof_tower1].inuse=true;
        map[Xof_basin][Yof_basin].inuse=true;
        tower1[sequenceof_tower1].row=Yof_basin;
        tower1[sequenceof_tower1].column=Xof_basin;
        sequenceof_tower1++;
    }
    if(event->button() == Qt::LeftButton&&key==Qt::Key_2&&sequenceof_tower2<5&&map[Xof_basin][Yof_basin].inuse==false&&Xof_basin<5&&Yof_basin<5){
        tower2[sequenceof_tower2].inuse=true;
        map[Xof_basin][Yof_basin].inuse=true;
        tower2[sequenceof_tower2].row=Yof_basin;
        tower2[sequenceof_tower2].column=Xof_basin;
        sequenceof_tower2++;
    }
    if(event->button() == Qt::LeftButton&&key==Qt::Key_3&&sequenceof_tower3<5&&map[Xof_basin][Yof_basin].inuse==false&&Xof_basin<5&&Yof_basin<5){
        tower3[sequenceof_tower3].inuse=true;
        map[Xof_basin][Yof_basin].inuse=true;
        tower3[sequenceof_tower3].row=Yof_basin;
        tower3[sequenceof_tower3].column=Xof_basin;
        sequenceof_tower3++;
    }
    if(event->button() == Qt::LeftButton&&key==Qt::Key_4&&sequenceof_tower4<5&&map[Xof_basin][Yof_basin].inuse==false&&Xof_basin<5&&Yof_basin<5){
        tower4[sequenceof_tower4].inuse=true;
        map[Xof_basin][Yof_basin].inuse=true;
        tower4[sequenceof_tower4].row=Yof_basin;
        tower4[sequenceof_tower4].column=Xof_basin;
        sequenceof_tower4++;
    }
}

void MainScene::keyPressEvent(QKeyEvent *event){
     key=event->key();
}

void MainScene::getSequence_ofbasin(int x, int y){
    int _x, _y;
    _x=floor(x/100);
    _y=floor(y/100);
    if(_x==1||_x==2) Xof_basin=1;
    else if(_x==3||_x==4) Xof_basin=2;
    else if(_x==5||_x==6) Xof_basin=3;
    else if(_x==7||_x==8) Xof_basin=4;
    else Xof_basin=5;
    if(_y==1||_y==2) Yof_basin=1;
    else if(_y==3||_y==4) Yof_basin=2;
    else if(_y==5||_y==6) Yof_basin=3;
    else if(_y==7||_y==8) Yof_basin=4;
    else Yof_basin=5;
}

void MainScene::updatePosition(){
   int i;
   //update tower's position
   for(i=0;i<6;i++){
       if(tower1[i].inuse) {tower1[i].shoot();
       for(int j=0;j<bullet_Total;j++){
           if(tower1[i].bullets[j].Free==false){
               tower1[i].bullets[j].updateposition();
           }
       }
   }
   }
   for(i=0;i<6;i++){
       if(tower2[i].inuse) {tower2[i].shoot();
       for(int j=0;j<bullet_Total;j++){
           if(tower2[i].bullets[j].Free==false){
               tower2[i].bullets[j].updateposition();
           }
       }
   }
   }
   for(i=0;i<6;i++){
       if(tower3[i].inuse) {tower3[i].shoot();
       for(int j=0;j<bullet_Total;j++){
           if(tower3[i].bullets[j].Free==false){
               tower3[i].bullets[j].updateposition();
           }
       }
   }
   }
   for(i=0;i<6;i++){
       if(tower4[i].inuse) {tower4[i].shoot();
       for(int j=0;j<bullet_Total;j++){
           if(tower4[i].bullets[j].Free==false){
               tower4[i].bullets[j].updateposition();
           }
       }
   }
   }

   //update enemy's position
   for(i=0;i<enemy_basic_Total;i++){
       if(enemy1[i].Free==false){
           enemy1[i].updateposition();
       }
   }
   for(i=0;i<enemy_stronger_Total;i++){
       if(enemy2[i].Free==false){
           enemy2[i].updateposition();
       }
   }
   for(i=0;i<enemy_summoner_Total;i++){
       for(int c=0;c<enemy_swifter_Total;c++){
           if(enemy3[i].footmen[c].Free==false){
               enemy3[i].footmen[c].updateposition();
           }
       }
       if(enemy3[i].Free==false){enemy3[i].summon();
           enemy3[i].updateposition();

       }
   }
}

void MainScene::updateGame(){
    timer.start();
    connect(&timer, &QTimer::timeout, [=](){
        produceEnemy();
        updatePosition();
        update();
        collisionCheck();
    });
}

void MainScene::produceEnemy(){
    //produce enemy_basic
    enemy_basic::record_of_Interval++;
    if(enemy_basic::record_of_Interval<enemy_basic_Interval){

    }
    else{
       enemy_basic::record_of_Interval=0;
        for(int i=0;i<enemy_basic_Total;i++){
            if(enemy1[i].Free){
                int c=rand() % 4+1;
                enemy1[i].Free=false;
                enemy1[i].X=game_Width;
                if(c==1) enemy1[i].Y=100;
                if(c==2) enemy1[i].Y=300;
                if(c==3) enemy1[i].Y=500;
                if(c==4) enemy1[i].Y=700;
                break;
            }
        }
    }

    //produce enemy_stronger
    enemy_stronger::record_of_Interval++;
    if(enemy_stronger::record_of_Interval<enemy_stronger_Interval){

    }
    else{
       enemy_stronger::record_of_Interval=0;
        for(int i=0;i<enemy_stronger_Total;i++){
            if(enemy2[i].Free){
                int c=rand() % 4+1;
                enemy2[i].Free=false;
                enemy2[i].X=game_Width;
                if(c==1) enemy2[i].Y=100;
                if(c==2) enemy2[i].Y=300;
                if(c==3) enemy2[i].Y=500;
                if(c==4) enemy2[i].Y=700;
                break;
            }
        }
    }
    //produce enemy_summoner
    enemy_summoner::record_of_Interval++;
    if(enemy_summoner::record_of_Interval<enemy_summoner_Interval){

    }
    else{
       enemy_summoner::record_of_Interval=0;
        for(int i=0;i<enemy_summoner_Total;i++){
            if(enemy3[i].Free){
                int c=rand() % 4+1;
                enemy3[i].Free=false;
                enemy3[i].X=game_Width;
                if(c==1) enemy3[i].Y=100;
                if(c==2) enemy3[i].Y=300;
                if(c==3) enemy3[i].Y=500;
                if(c==4) enemy3[i].Y=700;
                break;
            }
        }
    }
}

void MainScene::collisionCheck(){
    for(int i=0;i<tower_Total;i++){
        if(tower1[i].inuse==false) continue;
        else{
            for(int j=0;j<bullet_Total;j++){
                if(tower1[i].bullets[j].Free==true) continue;
                else{
                for(int k=0;k<enemy_swifter_Total;k++){
                    if(enemy1[k].Free==true) { }
                    else{
                        if(tower1[i].bullets[j].rect.intersects(enemy1[k].rect)){
                            tower1[i].bullets[j].Free=true;
                            enemy1[k].life--;
                            if(enemy1[k].life==0) {enemy1[k].Free=true;enemy1[k].life=enemy_basic_Life;enemy1[k].speed=enemy_Normalspeed;}
                        }
                    }
                    if(enemy2[k].Free==true) { }
                    else{
                        if(tower1[i].bullets[j].rect.intersects(enemy2[k].rect)){
                            tower1[i].bullets[j].Free=true;
                            enemy2[k].life--;
                            if(enemy2[k].life==0) {enemy2[k].Free=true;enemy2[k].life=enemy_stronger_Life;enemy2[k].speed=enemy_Normalspeed;}
                        }
                    }
                    for(int l=0;l<enemy_basic_Total;l++){
                        if(enemy3[k].footmen[l].Free==true) { }
                        else{
                            if(tower1[i].bullets[j].rect.intersects(enemy3[k].footmen[l].rect)){
                                tower1[i].bullets[j].Free=true;
                                enemy3[k].footmen[l].life--;
                                if(enemy3[k].footmen[l].life==0) {enemy3[k].footmen[l].Free=true;enemy3[k].footmen[j].life=enemy_swifter_Life;enemy3[k].footmen[j].speed=enemy_Swifterspeed;}
                            }
                        }
                    }
                    if(enemy3[k].Free==true) { }
                    else{
                        if(tower1[i].bullets[j].rect.intersects(enemy3[k].rect)){
                            tower1[i].bullets[j].Free=true;
                            enemy3[k].life--;
                            if(enemy3[k].life==0) {enemy3[k].Free=true;enemy3[k].life=enemy_summoner_Life;enemy3[k].speed=enemy_Normalspeed;}
                        }

                    }
                }
                }
            }
        }
    }
    for(int i=0;i<tower_Total;i++){
        if(tower2[i].inuse==false) continue;
        else{
            for(int j=0;j<bullet_Total;j++){
                if(tower2[i].bullets[j].Free==true) continue;
                else{
                for(int k=0;k<enemy_swifter_Total;k++){
                    if(enemy1[k].Free==true) { }
                    else{
                        if(tower2[i].bullets[j].rect.intersects(enemy1[k].rect)){
                            tower2[i].bullets[j].Free=true;
                            enemy1[k].life--;
                            if(enemy1[k].life==0) {enemy1[k].Free=true;enemy1[k].life=enemy_basic_Life;enemy1[k].speed=enemy_Normalspeed;}
                        }
                    }
                    if(enemy2[k].Free==true) { }
                    else{
                        if(tower2[i].bullets[j].rect.intersects(enemy2[k].rect)){
                            tower2[i].bullets[j].Free=true;
                            enemy2[k].life--;
                            if(enemy2[k].life==0) {enemy2[k].Free=true;enemy2[k].life=enemy_stronger_Life;enemy2[k].speed=enemy_Normalspeed;}
                        }
                    }
                    for(int l=0;l<enemy_basic_Total;l++){
                        if(enemy3[k].footmen[l].Free==true) { }
                        else{
                            if(tower2[i].bullets[j].rect.intersects(enemy3[k].footmen[l].rect)){
                                tower2[i].bullets[j].Free=true;
                                enemy3[k].footmen[l].life--;
                                if(enemy3[k].footmen[l].life==0) {enemy3[k].footmen[l].Free=true;enemy3[k].footmen[j].life=enemy_swifter_Life;enemy3[k].footmen[j].speed=enemy_Swifterspeed;}
                            }
                        }
                    }
                    if(enemy3[k].Free==true) { }
                    else{
                        if(tower2[i].bullets[j].rect.intersects(enemy3[k].rect)){
                            tower2[i].bullets[j].Free=true;
                            enemy3[k].life--;
                            if(enemy3[k].life==0) {enemy3[k].Free=true;enemy3[k].life=enemy_summoner_Life;enemy3[k].speed=enemy_Normalspeed;}
                        }

                    }
                }
                }
            }
        }
    }
    for(int i=0;i<tower_Total;i++){
        if(tower3[i].inuse==false) continue;
        else{
            for(int j=0;j<bullet_Total;j++){
                if(tower3[i].bullets[j].Free==true) continue;
                else{
                for(int k=0;k<enemy_swifter_Total;k++){
                    if(enemy1[k].Free==true) { }
                    else{
                        if(tower3[i].bullets[j].rect.intersects(enemy1[k].rect)){
                            tower3[i].bullets[j].Free=true;
                            enemy1[k].life--;
                            if(enemy1[k].life==0) {enemy1[k].Free=true;enemy1[k].life=enemy_basic_Life;enemy1[k].speed=enemy_Normalspeed;}
                        }
                    }
                    if(enemy2[k].Free==true) { }
                    else{
                        if(tower3[i].bullets[j].rect.intersects(enemy2[k].rect)){
                            tower3[i].bullets[j].Free=true;
                            enemy2[k].life--;
                            if(enemy2[k].life==0) {enemy2[k].Free=true;enemy2[k].life=enemy_stronger_Life;enemy2[k].speed=enemy_Normalspeed;}
                        }
                    }
                    for(int l=0;l<enemy_basic_Total;l++){
                        if(enemy3[k].footmen[l].Free==true) { }
                        else{
                            if(tower3[i].bullets[j].rect.intersects(enemy3[k].footmen[l].rect)){
                                tower3[i].bullets[j].Free=true;
                                enemy3[k].footmen[l].life--;
                                if(enemy3[k].footmen[l].life==0) {enemy3[k].footmen[l].Free=true;enemy3[k].footmen[j].life=enemy_swifter_Life;enemy3[k].footmen[j].speed=enemy_Swifterspeed;}
                            }
                        }
                    }
                    if(enemy3[k].Free==true) { }
                    else{
                        if(tower3[i].bullets[j].rect.intersects(enemy3[k].rect)){
                            tower3[i].bullets[j].Free=true;
                            enemy3[k].life--;
                            if(enemy3[k].life==0) {enemy3[k].Free=true;enemy3[k].life=enemy_summoner_Life;enemy3[k].speed=enemy_Normalspeed;}
                        }

                    }
                }
                }
            }
        }
    }
    for(int i=0;i<tower_Total;i++){
        if(tower4[i].inuse==false) continue;
        else{
            for(int j=0;j<bullet_Total;j++){
                if(tower4[i].bullets[j].Free==true) continue;
                else{
                for(int k=0;k<enemy_swifter_Total;k++){
                    if(enemy1[k].Free==true) { }
                    else{
                        if(tower4[i].bullets[j].rect.intersects(enemy1[k].rect)){
                            tower4[i].bullets[j].Free=true;
                            enemy1[k].life--;
                            enemy1[k].speed=enemy_Normalspeed*slowing_ratio;
                            if(enemy1[k].life==0) {enemy1[k].Free=true;enemy1[k].life=enemy_basic_Life;enemy1[k].speed=enemy_Normalspeed;}
                        }
                    }
                    if(enemy2[k].Free==true) { }
                    else{
                        if(tower4[i].bullets[j].rect.intersects(enemy2[k].rect)){
                            tower4[i].bullets[j].Free=true;
                            enemy2[k].life--;
                            enemy2[k].speed=enemy_Normalspeed*slowing_ratio;
                            if(enemy2[k].life==0) {enemy2[k].Free=true;enemy2[k].life=enemy_stronger_Life;enemy2[k].speed=enemy_Normalspeed;}
                        }
                    }
                    for(int l=0;l<enemy_basic_Total;l++){
                        if(enemy3[k].footmen[l].Free==true) { }
                        else{
                            if(tower4[i].bullets[j].rect.intersects(enemy3[k].footmen[l].rect)){
                                tower4[i].bullets[j].Free=true;
                                enemy3[k].footmen[l].life--;
                                enemy3[k].footmen[l].speed=enemy_Swifterspeed*slowing_ratio;
                                if(enemy3[k].footmen[l].life==0) {enemy3[k].footmen[l].Free=true;enemy3[k].footmen[j].life=enemy_swifter_Life;enemy3[k].footmen[j].speed=enemy_Swifterspeed;}
                            }
                        }
                    }
                    if(enemy3[k].Free==true) { }
                    else{
                        if(tower4[i].bullets[j].rect.intersects(enemy3[k].rect)){
                            tower4[i].bullets[j].Free=true;
                            enemy3[k].life--;
                            enemy3[k].speed=enemy_Normalspeed*slowing_ratio;
                            if(enemy3[k].life==0) {enemy3[k].Free=true;enemy3[k].life=enemy_summoner_Life;enemy3[k].speed=enemy_Normalspeed;}
                        }

                    }
                }
                }
            }
        }
    }
}
