//
// Created by 熊志耀 on 2022/1/9.
//

#ifndef MAIN_BOMB_H
#define MAIN_BOMB_H
#include "config.h"
#include "QPixmap"
#include "QRect"
#include "QVector"
class Bomb {
public:
    Bomb();
    void updateInfo();

public:
    //爆炸资源组
    QVector<QPixmap> m_pixArr;
    int m_X;
    int m_Y;
    bool m_Free;
    int m_Recoder;
    int m_index;
};


#endif //MAIN_BOMB_H
