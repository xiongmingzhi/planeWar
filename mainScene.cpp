// mainwindow.cpp
#include "mainScene.h"
#include "config.h"
#include "QPainter"
#include "ctime"
#include "QSound"

MainScene::MainScene(QWidget *parent) :
        QMainWindow(parent) {
    initScene();
    playGame();
}

void MainScene::initScene() {
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    //设置图标资源
    setWindowIcon(QIcon( GAME_ICON));  //加头文件 #include <QIcon>
    m_Timer.setInterval(GAME_RATE);
    srand((unsigned int) time(NULL));
    m_recoder = 0;

}

void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();
    QSound::play(SOUND_BACKGROUND);
    //监听定时器
    connect(&m_Timer,&QTimer::timeout,[=](){
        //更新游戏中元素的坐标
        updatePosition();
        //敌机出场
        enemyToScene();
        //重新绘制图片
        update();
        //碰撞检测
        collisionDetection();
    });
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();
    temp_bullet.m_Free = false;
    temp_bullet.updatePosition();
    m_hero.shoot();
    for(int i = 0; i < BULLET_NUM; i++)
    {
        if ( !m_hero.m_bullets[i].m_Free)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }
    for (int i = 0; i < ENEMY_NUM; ++i) {
        if (m_enemys[i].m_Free == false)
        {
            m_enemys[i].updatePosition();
        }
    }
    for (int i = 0; i < BOMB_NUM; ++i) {
        if(m_bombs[i].m_Free == false)
        {
            m_bombs[i].updateInfo();
        }
    }
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);

    //绘制英雄
    painter.drawPixmap(m_hero.m_X, m_hero.m_Y, m_hero.m_Plane);
    painter.drawPixmap(temp_bullet.m_X, temp_bullet.m_Y, temp_bullet.m_Bullet);
    for(int i = 0; i<BULLET_NUM; i++)
    {
        if(!m_hero.m_bullets[i].m_Free)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X, m_hero.m_bullets[i].m_Y, m_hero.m_bullets[i].m_Bullet);
        }
    }
    for(int i=0; i<ENEMY_NUM; i++){
        if (m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X, m_enemys[i].m_Y, m_enemys[i].m_enemy);
        }
    }
    for (int i = 0; i < BOMB_NUM; ++i) {
        if(m_bombs[i].m_Free == false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event) {
    int x = event->x() - m_hero.m_Rect.width()*0.5;
    int y = event->y() - m_hero.m_Rect.height()*0.5;

    //边界检测
    if(x <= 0)
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <=0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y =  GAME_HEIGHT - m_hero.m_Rect.height();
    }
    m_hero.setPosition(x, y);
}

void MainScene::enemyToScene() {
    m_recoder ++;
    if(m_recoder < ENEMY_INTERVAL)
    {
        return;
    }
    m_recoder = 0;
    for (int i = 0; i < ENEMY_NUM; ++i) {
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free = false;
            //设置坐标
            m_enemys[i].m_X = rand() % (GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection() {
    for(int i =0; i<ENEMY_NUM; i++)
    {
        if(m_enemys[i].m_Free){
            continue;
        }
        //遍历子弹
        for(int j = 0; j < BULLET_NUM; j++)
        {
            if(m_hero.m_bullets[j].m_Free){
                continue;
            }
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;
                QSound::play(SOUND_BOMB);
                for(int k = 0; k<BOMB_NUM; k++){
                    if(m_bombs[k].m_Free)
                    {
                        m_bombs[k].m_Free = false;
                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }
    }
}


MainScene::~MainScene() {

}


