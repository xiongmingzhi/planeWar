//
// Created by 熊志耀 on 2022/1/7.
//

#ifndef MAIN_MAP_H
#define MAIN_MAP_H
#include <QPixmap>

class Map {
public:
    Map();
    void mapPosition();

public:
    QPixmap m_map1;
    QPixmap m_map2;

    int m_map1_posY;
    int m_map2_posY;

    int m_scroll_speed;

};


#endif //MAIN_MAP_H
