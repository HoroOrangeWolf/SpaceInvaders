#include "enemy.h"
#include <enemycontainer.h>
#include <QGraphicsScene>
#include <math.h>
#include <bullet.h>
#include <pixmapcontainer.h>
#include <ship.h>
#include <score.h>


/**
 * @file enemy.h
 * Plik nagłówkowy klasy Enemy reprezentującej obiekt przeciwnika.
 */

/**
  * @file enemycontainer.h
  * Plik nagłówkowy klasy odpowiedzialnej za przechowywanie przeciwników
  */

/**
 * @file bullet.h
 * Plik nagłówkowy klasy Bullet odpowiedzialnej za tworzenie pocisków.
 */

/**
 * @file pixmapcontiner.h
 * Plik nagłówkowy klasy PixmapContainer odpowiedzialnej za elementy graficzne.
 */

/**
 * @file ship.h
 * Plik nagłówkowy klasy Ship reprezentującej obiekt gracza.
 */

/**
  * @file score.h
  * Plik nagłówkowy klasy Score, przechowującej informacje o liczbie punktów gracza.
  */

/**
 * @brief Enemy::Enemy
 * Konstruktor domyślnie ustawiajacy przeciwnika w okreslonym miejscu i  ustawia interwal strzalu na 2s
 * @param scene Wskaznik na scene
 */

Enemy::Enemy(QGraphicsScene *scene):CanShoot(2000)
{   
    PixmapData data = PixmapContainer::getPixmapData(ENEMYGIF2);
    QPixmap pix[data.size];

    for(int i = 0; i < data.size; ++i)
        pix[i] = data.pix[i];

    scene->addItem(this);
    this->moveBy( 0, 0);
    this->vector.setX(0);
    this->vector.setY(30);
    this->x1 = 0;
    this->y1 = 0;

    EnemyContainer::addEnemy(this);
    this->init(80, 80, pix, data.size, 8);
    this->start();
}

/**
 * @brief Enemy::Enemy
 * Konstruktor inicjalizujacy przeciwnika na podstawie parametru enemydata
 * @param scene Wskaznik na scene
 * @param enemydata Obiekt klasy inicjalizacji przeciwnika
 */
Enemy::Enemy(QGraphicsScene *scene, EnemyData enemydata)
{
    this->setDelay(enemydata.delayshoot);

    PixmapData data = PixmapContainer::getPixmapData(enemydata.types);
    QPixmap pix[data.size];

    for(int i = 0; i < data.size; ++i)
        pix[i] = data.pix[i];

    scene->addItem(this);
    this->moveBy( 0, 0);
    this->vector.setX(0);
    this->vector.setY(30);
    this->x1 = 0;
    this->y1 = 0;

    this->health = enemydata.health;

    this->init(enemydata.width, enemydata.height, pix, data.size, 8);

    EnemyContainer::addEnemy(this);

    this->start();
}

/**
 * @brief Enemy::~Enemy
 * Destruktor usuwający przeciwnika
 */

Enemy::~Enemy()
{
    if(this->scene() != NULL)
        this->scene()->removeItem(this);

    EnemyContainer::removeEnemy(this);
}
/**
 * @brief Enemy::updater
 * Metoda aktualizująca informacje o przeciwniku takie jak pozycja i kara punktowa za opuszczenie mapy przez przeciwnika
 */

void Enemy::updater()
{
    int dziel = this->scene()->width()/2;
    this->y1 = this->y1 + ( this->vector.y()/60);

    this->x1 = dziel*std::sin(y1/70) + dziel;

    if(this->y1 > this->scene()->height() + 30)
    {
        Score::getScores()->setScore(Score::getScores()->getScore() - 10);
        delete this;
        return;
    }


    this->setPos(this->x1, this->y1);
    
}

/**
 * @brief Enemy::shoot
 * Metoda tworzaca pocisk
 */

void Enemy::shoot()
{
    new Bullet(this->scene(), this->pos().x() + this->pixmap().width()/2, this->pos().y() + this->pixmap().height(), 0.0f, 250.0f, ENEMY);
}
/**
 * @brief Enemy::isShouldShoot
 * Metoda sprawdzajaca czy przeciwnik powinien strzelić w zależności od pozycji statku gracza
 * @return  Zwraca true jezeli statek znajduje się w okreslonej przestrzeni / false analogicznie jeżeli nie znajduje się
 */

bool Enemy::isShouldShoot()
{
    Ship *ship = Ship::getShip();

    return ((this->x1 - 50 <= ship->getX1()) && (this->x1 + 50 + this->pixmap().width() >= ship->getX1()));
}

/**
 * @brief Enemy::getHealth
 * Metoda zwracajaca zdrowie przeciwnika
 * @return zdrowie przeciwnika
 */

int Enemy::getHealth()
{
    return this->health;
}
/**
 * @brief Enemy::doDamage
 * Metoda zadajaca obrażenia(damage) przeciwnikowi
 * @param damage Obrażenia(damage)
 */

void Enemy::doDamage(int damage)
{
    this->health -= damage;
}

/**
 * @brief Enemy::shoot
 * Metoda tworzaca pocisk
 * @param val Kierunek poruszania sie przeciwników
 */
void Enemy::shoot(QVector2D val)
{
    new Bullet(this->scene(), this->pos().x() + this->pixmap().width()/2, this->pos().y() + this->pixmap().height(), val.x(), val.y(), ENEMY);
}

