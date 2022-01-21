//
// Created by 熊志耀 on 2022/1/7.
//

#ifndef MAIN_CONFIG_H
#define MAIN_CONFIG_H
#define GAME_WIDTH 512
#define GAME_HEIGHT 768
#define GAME_TITLE "飞机大战 v1.0"
#define GAME_ICON ":/res/app.ico"
#define GAME_RES_PATH "../plane.rcc"
#define GAME_ICON  ":/res/app.ico"
#define MAP_PATH  ":/res/img_bg_level_1.jpg" //地图图片路径
#define MAP_SCROLL_SPEED 2  //地图滚动速度
#define GAME_RATE  10   //刷新间隔，帧率 单位毫秒

//英雄飞机
#define HERO_PATH ":/res/hero2.png"
#define BULLET_PATH ":/res/bullet_11.png"
#define BULLET_SPEED 5
#define BULLET_NUM 30
#define BULLET_INTERVAL 20

//敌机
#define ENEMY_PATH ":/res/img-plane_5.png"
#define ENEMY_SPEED 5
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 30

//爆炸组
#define BOMB_PATH ":/res/bomb-%1.png"
#define BOMB_NUM 20
#define BOMB_MAX 7
#define BOMB_INTERVAL 20
#define SOUND_BACKGROUND ":/res/bg.wav"
#define SOUND_BOMB ":/res/bomb.wav"

#endif //MAIN_CONFIG_H
