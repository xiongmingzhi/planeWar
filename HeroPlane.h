//
// Created by 熊志耀 on 2022/1/9.
//

#ifndef MAIN_HEROPLANE_H
#define MAIN_HEROPLANE_H
#include "QPixmap"
#include "QRect"
#include "Bullet.h"
#include "config.h"

class HeroPlane {
public:
    HeroPlane();
    void shoot();
    void setPosition(int x ,int y);

public:
    QPixmap m_Plane;
    int m_X;
    int m_Y;
    QRect m_Rect;
    Bullet m_bullets[BULLET_NUM];
    int m_recoder;
};


#endif //MAIN_HEROPLANE_H
