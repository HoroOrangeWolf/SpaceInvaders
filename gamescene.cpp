#include "gamescene.h"
/**
  * @file gamescene.h
  * Plik nagłówkowy klasy GameScene.
  */
/**
 * @brief GameScene::GameScene
 * Kontruktor klasy GameScene.
 */
GameScene::GameScene()
{
}
/**
 * @brief GameScene::resizeGameScene
 * Funkcja tworzy prostokąt o podanych wymiarach, który stanowić będzie pole gry.
 * @param w Szerokość obszaru.
 * @param h Wysokość obszaru.
 */

void GameScene::resizeGameScene(int w, int h)
{
    this->setSceneRect(QRect(0, 0, w + 1, h + 1));
}



