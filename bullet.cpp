#include "bullet.h"
#include "enemy.h"
#include <bulletcontainer.h>
#include "score.h"
#include "health.h"
#include <math.h>
#include "ship.h"
#include <pixmapcontainer.h>

/**
 * @file bullet.h
 * Plik nagłówkowy klasy Bullet odpowiedzialnej za tworzenie pocisków.
 */

/**
 * @file enemy.h
 * Plik nagłówkowy klasy Enemy reprezentującej obiekt przeciwnika.
 */

/**
 * @file bulletcontainer.h
 * Plik nagłówkowy klasy Bulletcontainer przechowującej pociski
 */

/**
  * @file score.h
  * Plik nagłówkowy klasy Score, przechowującej informacje o liczbie punktów gracza.
  */
/**
  * @file health.h
  * Plik nagłówkowy klasy Health.
  */

/**
 * @file ship.h
 * Plik nagłówkowy klasy Ship reprezentującej obiekt gracza.
 */

/**
 * @file pixmapcontiner.h
 * Plik nagłówkowy klasy PixmapContainer odpowiedzialnej za elementy graficzne.
 */

/**
 * @brief Bullet::Bullet
 * Konstruktor tworzacy pocisk
 * @param scene Wskaznik na scene
 * @param posx Pozycja poczatkowa x
 * @param posy Pozycja poczatkowa y
 */

Bullet::Bullet(QGraphicsScene *scene, int posx, int posy)
{
    this->directionvector.setY(-400.0f);
    this->directionvector.setX(0);

    PixmapData data = PixmapContainer::getPixmapData(BULLETDEFAULT);

    QPixmap pic = data.pix[0];

    this->from = SHIP;

    QTransform tr;
    tr.rotate(-90.0f);

    pic = pic.transformed(tr);

    this->setPixmap(pic);

    BulletContainer::addBullet(this);

    scene->addItem(this);

    this->x1 = posx;
    this->y1 = posy;

    this->setPos(QPoint(posx, posy));
}
/**
 * @brief Bullet::Bullet
 * Konstruktor tworzacy pocisk
 * @param scene Wskaznik na scene
 * @param posx Pozycja poczatkowa x
 * @param posy Pozycja poczatkowa y
 * @param xvector Kierunek poruszania sie pocisku po osi x
 * @param yvector Kierunek poruszania sie pocisku po osi y
 * @param from Od kogo pochodzi pocisk
 */
Bullet::Bullet(QGraphicsScene *scene, int posx, int posy, double xvector, double yvector, Types from)
{
    this->directionvector.setY(yvector);
    this->directionvector.setX(xvector);

    PixmapData data = PixmapContainer::getPixmapData(BULLETDEFAULT);

    QPixmap pic = data.pix[0];

    this->from = from;

    QTransform tr;

    tr.rotate(std::atan2(yvector, xvector)*180.0f/3.14f);

    pic = pic.transformed(tr);

    this->setPixmap(pic);

    BulletContainer::addBullet(this);

    scene->addItem(this);

    this->x1 = posx;
    this->y1 = posy;

    this->setPos(QPoint(posx, posy));

}
/**
 * @brief Bullet::~Bullet
 * Destruktor usuwujacy pocisk
 */
Bullet::~Bullet()
{
    if(this->scene() != NULL)
        this->scene()->removeItem(this);

    BulletContainer::deleteBullet(this);
}

/**
 * @brief Bullet::isCanDestroy
 * Metoda sprawdzajaca czy pocisk moze zniszczyc przeciwnika lub statek
 * @param from Skad pocisk zostal wystrzelony statek/przeciwnik
 * @return
 */

bool Bullet::isCanDestroy(Types from)
{
    return from != (this->from);
}

/**
 * @brief Bullet::updater
 * Metoda aktualizujaca polozenia pocisku i sprawdzajaca czy pocisk natrafil na przeciwnika lub statek
 */
void Bullet::updater()
{
    QList<QGraphicsItem *> colliding_items=collidingItems();

    for(int i=0,n=colliding_items.size();i<n;++i)
    {
        if(typeid (*colliding_items[i]) == typeid(Enemy) && this->isCanDestroy(ENEMY))
        {
            PixmapData data = PixmapContainer::getPixmapData(EXPLOSIONGIF);
            Enemy *enemy = (Enemy*)colliding_items[i];

            if(enemy->getHealth() <= 1)
            {
                Animation *an = new Animation(80, 80, data.pix, data.size);
                an->setLifeSpan(50);
                this->scene()->addItem(an);
                an->moveBy(enemy->x(), enemy->y());
                an->start();
                Score::getScores()->increase();

                delete enemy;
                delete this;
                return;
            }
            else
                enemy->doDamage(1);

            Animation *an = new Animation(80, 80, data.pix, data.size);
            an->setLifeSpan(50);
            this->scene()->addItem(an);
            an->moveBy(enemy->x(), enemy->y());
            an->start();
            Score::getScores()->increase();

            delete this;
            return;
        }
        if(typeid(*colliding_items[i]) == typeid (Ship) && this->isCanDestroy(SHIP))
        {
            Ship *ship = (Ship *)colliding_items[i];

            PixmapData data = PixmapContainer::getPixmapData(EXPLOSIONGIF);

            Animation *an = new Animation(80, 80, data.pix, data.size);

            an->setLifeSpan(50);
            an->moveBy(ship->x(), ship->y());
            ship->scene()->addItem(an);

            an->start();
            ship->die();

            delete this;
            return;
        }
    }





    double buffx = this->x1 + (this->directionvector.x()/60);
    double buffy = this->y1 + (this->directionvector.y()/60);

    if( ( buffx  + this->pixmap().width() >= 0 ) && ((buffx <= this->scene()->width())))
        this->x1 = buffx;
    else
    {
        delete this;
        return;
    }


    if(buffy + this->pixmap().height() >= 0 && (buffy - this->pixmap().height() <= this->scene()->height()))
        this->y1 = buffy;
    else
    {
        delete this;
        return;
    }


    this->setPos(QPoint(this->x1,this->y1));
}
