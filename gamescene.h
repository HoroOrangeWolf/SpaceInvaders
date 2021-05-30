#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QGraphicsScene>

/**
 * @class GameScene
 * Klasa odpowiadająca za utworzenie sceny gry.
 */
class GameScene:public QGraphicsScene
{
public:
    GameScene();
    void resizeGameScene(int w, int h);
};

#endif // GAMESCENE_H
