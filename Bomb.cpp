//
// Created by 熊志耀 on 2022/1/9.
//

#include "Bomb.h"
#include "QString"
Bomb::Bomb() {
    //初始化爆炸组
    for(int i = 1; i<=BOMB_NUM;i++){
        QString str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }
    m_X = 0;
    m_Y = 0;
    m_Free = true;
    m_index = 0;
    m_Recoder = 0;
}
void Bomb::updateInfo() {
    if(m_Free){
        return;
    }
    m_Recoder ++;
    if(m_Recoder < BOMB_INTERVAL)
    {
        return;
    }
    m_Recoder = 0;
    m_index ++;
    if(m_index > BOMB_MAX -1)
    {
        m_index = 0;
        m_Free = true;
    }
}