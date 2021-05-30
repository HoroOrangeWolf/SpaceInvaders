#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <gamescene.h>
#include <QTimer>
#include <bulletcontainer.h>
#include <enemycontainer.h>
#include <ship.h>
#include <score.h>
#include <health.h>
#include <animationcontainer.h>
#include <pixmapcontainer.h>
#include <list>
#include <ContainerElement.h>
#include <gamesettings.h>
#include <QMediaPlaylist>
#include <QMediaPlayer>

/**
 * @class Game
 * Klasa odpowiedzialna za główne czynności związane z grą
 */

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    Game(GameSettings &settings);
    ~Game();
    GameScene *returnGameScene();
    void startUpdater(int ms);
    void initShip();
    void loseGoBackMenu();
    void winGoBackMenu();
private:
    GameScene *scene = NULL;/**< Wskaźnik na scene gry. */
    Ship *ship = NULL; /**< Wskaźnik na statek gracza. */
    QTimer *sc = NULL; /**< Wskaźnik na timer. */
    Score *score = NULL; /**< Wskaźnik na Score. */
    Health * hp = NULL; /**< Wskaźnik na Health. */
    void initUpdater(); /**< Inicjuje timer. */
    PixmapContainer pixmapcontainer; /**< Zawiera wszystkie grafiki potrzebne do danej rozgrywki. */
    std::list<ContainerElement *> element; /**< Lista klas które zarządzają innymi klasami. */
    QMediaPlaylist *player = NULL; /**< Wskaźnik na QmediaPlayList. */
    QMediaPlayer *media = NULL; /**< Wskaźnik na qmediaplayer. */
public slots:
    void updater();/**< Aktualizauje klasy zawarte w liście element. */
};

#endif // GAME_H
