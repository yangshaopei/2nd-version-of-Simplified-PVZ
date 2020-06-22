#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "lawn.h"
#include <QWidget>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include "config.h"
#include <QIcon>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPaintEvent>
#include "bullet_basic.h"
#include <QTimer>
#include "tower_basic.h"
#include "markof_column.h"
#include "markof_row.h"
#include "tower_double.h"
#include "tower_3dimensional.h"
#include "tower_slowing.h"
#include "enemy_basic.h"
#include <ctime>
#include "enemy_stronger.h"
#include "enemy_summoner.h"
class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //background part
    void updateGame();
    void initScene();
    void updatePosition();
    QTimer timer;

    //enemy part
    enemy_basic enemy1[enemy_basic_Total];
    enemy_stronger enemy2[enemy_stronger_Total];
    enemy_summoner enemy3[enemy_summoner_Total];
    void produceEnemy();

    //map part
    markof_column columnmark;
    markof_row rowmark;
    lawn map[5][5];
    int Xof_basin,Yof_basin;
    void getSequence_ofbasin(int x, int y);

    //tower part
    tower_basic tower1[tower_Total];
    int sequenceof_tower1=0;
    tower_double tower2[tower_Total];
    int sequenceof_tower2=0;
    tower_3dimensional tower3[tower_Total];
    int sequenceof_tower3=0;
    tower_slowing tower4[tower_Total];
    int sequenceof_tower4=0;

    //key and mouse part
    void mouseMoveEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *event);
    int key;
    int xof_mouse,yof_mouse;


    //drawing part
    void paintEvent(QPaintEvent *);

    //collision part
    void collisionCheck();
};





#endif // MAINSCENE_H
