#include "game.h"
#include <QRect>
#include <ship.h>
#include <score.h>
#include "health.h"
#include <QTimer>
#include <enemyspawner.h>
#include <QMediaPlayer>
#include <mainwindow.h>
#include <QGraphicsView>

/**
 * @file game.h
 * Plik nagłówkowy klasy Game odpowiedzialnej za przebieg rozgrywki.
 */

/**
 * @file ship.h
 * Plik nagłówkowy klasy Ship tworzącej i obsługującej statek gracza.
 */

/**
  * @file score.h
  * Plik nagłówkowy klasy Score, przechowującej informacje o liczbie punktów gracza.
  */

/**
  * @file health.h
  * Plik nagłówkowy klasy Health,przechowującej informacje o liczbie zdrowia gracza.
  */

/**
  * @file enemyspawner
  * Plik nagłówkowy klasy enemtspawner , zajmujący się przeciwnikami.
  */


/**
 * @file mainwindow.h
 * Plik nagłówkowy klasy MainWindow.
 */


/**
 * @brief Game::Game
 * Konstruktor dodajacy wszystkie elementy gry
 */
Game::Game()
{
    this->scene = new GameScene();
    this->initUpdater();
    score =new Score();

    this->scene->addItem(score);
    score->moveBy(25,25);

    hp = new Health();

    this->scene->addItem(hp);
    hp->moveBy(25,50);

    this->element.push_front((ContainerElement *)new BulletContainer());
    this->element.push_front((ContainerElement *)new EnemyContainer());
    this->element.push_front((ContainerElement *)new AnimationContainer());

    EnemySpawner *spawner = new EnemySpawner(scene);

    spawner->addEnemyToSpawn(ENEMY1, 100);
    spawner->addEnemyToSpawn(ENEMY1, 30);
    spawner->addEnemyToSpawn(ENEMY1, 10);
    spawner->addEnemyToSpawn(ENEMY1, 60);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);
    spawner->addEnemyToSpawn(ENEMY1, 200);

    this->element.push_front((ContainerElement *)spawner);
}

/**
 * @brief Game::Game
 * Konstruktor ustawiajacy wszystkie elementy gry
 *
 * @param settings Obiekt klasy settings w ktorym zawieraja sie ustawienia rozgrywki
 */

Game::Game(GameSettings &settings)
{
    this->scene = new GameScene();
    this->initUpdater();

    this->score = new Score();
    this->hp = new Health();

    this->scene->addItem(this->hp);
    this->scene->addItem(this->score);

    this->hp->moveBy(25, 50);
    this->score->moveBy(25, 25);

    this->element.push_front((ContainerElement *)new BulletContainer());
    this->element.push_front((ContainerElement *)new AnimationContainer());
    this->element.push_front((ContainerElement *)new EnemyContainer());

    EnemySpawner *spawner = new EnemySpawner(this->scene);

    std::list<EnemyData> data = settings.getEnemydata();

    for(EnemyData buff : data)
        spawner->addEnemyToSpawn(buff);

    this->element.push_front((ContainerElement *)spawner);

    if(!settings.getBackgroundSound().isEmpty())
    {
        this->media = new QMediaPlayer();

        this->media->setMedia(settings.getBackgroundSound());

        this->player = new QMediaPlaylist(this->media);

        this->player->setCurrentIndex(0);

        this->player->setPlaybackMode(QMediaPlaylist::Loop);

        this->media->setVolume(20);

        this->media->play();
    }
}

/**
 * @brief Game::~Game
 * Destruktor usuwający wszystkie elementy gry
 */
Game::~Game()
{
    if(this->media != NULL)
    {
        this->media->stop();
        this->player->clear();
        delete player;
        delete media;
    }
    this->sc->stop();
    delete sc;
    delete ship;
    delete score;
    delete hp;

    for(std::list<ContainerElement *>::iterator buff = this->element.begin(); buff != this->element.end(); ++buff)
        delete (*buff);

    this->element.clear();
    this->scene->clear();
    delete (this->scene);
}

/**
 * @brief Game::returnGameScene
 * Metoda zwracajaca wskaznik na scene
 * @return wskaznik na scene
 */

GameScene *Game::returnGameScene()
{
    return this->scene;
}

/**
 * @brief Game::updater
 * Metoda aktualizujaca gre i jej elementy
 */

void Game::updater()
{
    if(EnemySpawner::getIsempty() == true && EnemyContainer::isEmpty())
    {
        if(Score::getScores()->getScore())
            this->loseGoBackMenu();
        else
            this->winGoBackMenu();
        return;
    }

    this->ship->updater();

    for(std::list<ContainerElement *>::iterator iter = this->element.begin(); iter != this->element.end(); ++iter)
    {
        (*iter)->updater();

        if(Health::getHeal()->getHealth() <= 0)
        {
            this->loseGoBackMenu();
            return;
        }
    }

}
/**
 * @brief Game::initShip
 * Metoda inicjalizująca i dodająca do sceny statek
 */

void Game::initShip()
{
    Ship *ship = new Ship();

    this->ship = ship;

    this->scene->addItem(ship);


    ship->updatePos();

    ship->setFocus();

    ship->setup();
}

/**
 * @brief Game::loseGoBackMenu
 * Metoda wywolujaca sie po przegraniu poziomu
 */
void Game::loseGoBackMenu()
{
    MainWindow::getWindows()->restartGame(5, this->score->getScore());
}

/**
 * @brief Game::winGoBackMenu
 * Metoda wywolujaca sie po wygraniu poziomu
 */

void Game::winGoBackMenu()
{
    MainWindow::getWindows()->restartGame(6, this->score->getScore());
}

/**
 * @brief Game::initUpdater
 *  Metoda inicjalizujaca updater
 *
 */

void Game::initUpdater()
{
    if(sc != NULL)
        throw "Error!";

    this->sc = new QTimer();
    connect(this->sc, SIGNAL(timeout()), this, SLOT(updater()));
}

/**
 * @brief
 *  Metoda startujaca updater
 * @param ms czas podany w milisekundach
 */

void Game::startUpdater(int ms)
{
    this->sc->start(ms);
}
