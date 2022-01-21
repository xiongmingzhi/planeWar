//
// Created by 熊志耀 on 2022/1/9.
//

#include "HeroPlane.h"
#include "config.h"
HeroPlane::HeroPlane() {
    m_Plane.load(HERO_PATH);
    m_X = GAME_WIDTH*0.5 - m_Plane.width()*0.5;
    m_Y = GAME_HEIGHT - m_Plane.height();

    //初始化边框
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X, m_Y);

    m_recoder = 0;
}

void HeroPlane::setPosition(int x, int y) {
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X, m_Y);
}


void HeroPlane::shoot() {
    //累加时间间隔记录变量
    m_recoder++;
    //如果记录的数字未达到发射间隔，直接return
    if(m_recoder < BULLET_INTERVAL)
    {
        return;
    }
    //到达法身事件，重制发射记录
    m_recoder= 0;
    for(int i=0; i<BULLET_NUM;i++)
    {
        if(m_bullets[i].m_Free){
            //将子弹空闲改为假
            m_bullets[i].m_Free = false;
            m_bullets[i].m_X = m_X + m_Rect.width()*0.5-10;
            m_bullets[i].m_Y = m_Y -25;
            break;
        }
    }
}