// mainwindow.h
#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include "Map.h"
#include "HeroPlane.h"
#include "QMouseEvent"
#include "Bullet.h"
#include "EnemyPlane.h"
#include "Bomb.h"

class MainScene : public QMainWindow {
Q_OBJECT
public:
    explicit MainScene(QWidget *parent = 0);
    void initScene();
    void playGame();
    void updatePosition();
    void paintEvent(QPaintEvent *event);

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    //敌机
    void enemyToScene();
    void collisionDetection();

public:
    Map m_map;
    QTimer m_Timer;
    HeroPlane m_hero;
    Bullet temp_bullet;
    EnemyPlane m_enemys[ENEMY_NUM];
    int m_recoder;
    Bomb m_bombs[BOMB_NUM];
    ~MainScene();
};
