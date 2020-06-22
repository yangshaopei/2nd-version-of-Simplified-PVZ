#ifndef CONFIG_H
#define CONFIG_H

//settings of background information
#define game_Width  188*12
#define game_Height 176*5
#define game_Title "Tower Defense"
#define game_Resourcepath "C:/Qt/files/build-homework-Desktop_Qt_5_14_1_MinGW_64_bit-Debug/qrc_resource"
#define game_Iconpath ":/photos/basin"
#define game_Rate 10 //ms

//settings of bullet's information
#define bullet_Speed 5
#define basicbullet_Path ":/photos/bullet_basic"
#define slowingbullet_Path ":/photos/bullet_slowing"
#define bullet_Total 20
#define bullet_Interval 300
#define slowing_ratio 0

//settings of enemy's information
#define enemy_Normalspeed 0.3
#define enemy_Swifterspeed 0.5
#define enemy_basic_Interval 300
#define enemy_stronger_Interval 400
#define enemy_summoner_Interval 500
#define enemy_basic_Total 20
#define enemy_stronger_Total 20
#define enemy_summoner_Total 20
#define enemy_swifter_Total 20
#define enemy_basic_Path ":/photos/enemy_basic"
#define enemy_footman_Path ":/photos/enemy_footman"
#define enemy_stronger_Path ":/photos/enemy_stronger"
#define enemy_summoner_Path ":/photos/enemy_summoner"
#define enemy_swifter_Path ":/photos/enemy_swifter"
#define enemy_basic_Life 2
#define enemy_stronger_Life 3
#define enemy_summoner_Life 2
#define enemy_swifter_Life 1

//settings of tower's information
#define tower_basic_Path ":/photos/tower_basic"
#define tower_double_Path ":/photos/tower_double"
#define tower_3dimensional_Path ":/photos/tower_3dimensional"
#define tower_slowing_Path ":/photos/tower_slowing"
#define tower_Total 6

//settings of mark's information
#define markof_column_Path ":/photos/markof_column"
#define markof_row_Path ":/photos/markof_row"


#endif // CONFIG_H
