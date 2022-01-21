//
// Created by 熊志耀 on 2022/1/9.
//

#ifndef MAIN_ENEMYPLANE_H
#define MAIN_ENEMYPLANE_H
#include "QPixmap"
#include "QRect"
class EnemyPlane {
public:
    EnemyPlane();
    void updatePosition();

public:
    QPixmap m_enemy;
    int m_X;
    int m_Y;

    QRect m_Rect;
    bool m_Free;
    int m_Speed;

};


#endif //MAIN_ENEMYPLANE_H
