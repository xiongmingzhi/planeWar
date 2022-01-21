//
// Created by 熊志耀 on 2022/1/7.
//

#include "Map.h"
#include "config.h"

Map::Map() {
    //初始化对象
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //设置地图坐标
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;
    m_scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition() {
    m_map1_posY += MAP_SCROLL_SPEED;
    if(m_map1_posY >=0 )
    {
        m_map1_posY = -GAME_HEIGHT;
    }
    m_map2_posY += MAP_SCROLL_SPEED;
    if(m_map2_posY >= GAME_HEIGHT)
    {
        m_map2_posY = 0;
    }
}