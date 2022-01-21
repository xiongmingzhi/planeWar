// main.cpp
#include <QApplication>
#include <QDebug>
#include <QResource>
#include "config.h"
#include "mainScene.h"
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QResource::registerResource(GAME_RES_PATH);
    MainScene m;
    m.show();
    return app.exec();
}





