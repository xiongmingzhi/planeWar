//
// Created by 熊志耀 on 2022/1/9.
//

#ifndef MAIN_BULLET_H
#define MAIN_BULLET_H
#include "QPixmap"
#include "QRect"

class Bullet {
public:
    Bullet();
    void updatePosition();

public:
    QPixmap m_Bullet;
    int m_X;
    int m_Y;
    int m_Speed;
    bool m_Free;
    QRect m_Rect;

};


#endif //MAIN_BULLET_H
