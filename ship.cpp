#include "ship.h"
#include <QPoint>
#include <QVector2D>
#include <QGraphicsWidget>
#include <QRect>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <enemy.h>
#include <health.h>
#include <bullet.h>
#include <pixmapcontainer.h>
/**
 * @file ship.h
 * Plik nagłówkowy klasy Ship reprezentującej obiekt gracza.
 */
/**
 * @file enemy.h
 * Plik nagłówkowy klasy Enemy reprezentującej obiekt przeciwnika.
 */
/**
 * @file health.h
 * Plik nagłówkowy klasy Health przechowującej informacje o zdrowiu gracza.
 */
/**
 * @file bullet.h
 * Plik nagłówkowy klasy Bullet odpowiedzialnej za tworzenie pocisków.
 */
/**
 * @file pixmapcontainer.h
 * Plik nagłówkowy klasy PixmapContainer przechowującej elementy graficzne gry.
 */

/**
 * @brief Ship::Ship
 * Konstruktor klasy Ship. Tworzy obiekt gracza oraz jego graficzną reprezentację, ustawia jego współrzędne oraz
 * wektor poruszania się, a także decyduje o możliwości strzelania gracza.
 * @see PixmapContainer::getPixmapData()
 * @see Animation::init()
 * @see Animation::start()
 * @see CanShoot::CanShoot()
 */

Ship::Ship():CanShoot(200)
{
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->ship = this;
    PixmapData data = PixmapContainer::getPixmapData(SHIP1);

    this->setPixmap(data.pix[0]);

    this->directionvector = QVector2D(0, 0);
    this->x1 = this->y1 = 0;

    this->init(80, 80, data.pix, data.size, 2);
    this->start();

    this->ismortal = CanShoot(5000);
}
/**
 * @brief Ship::~Ship
 * Destruktor klasy Ship. Usuwa obiekt ze sceny gry i przypisuje mu wartość NULL.
 */

Ship::~Ship()
{
    this->ship = NULL;
    this->scene()->removeItem(this);
}
/**
 * @brief Ship::keyPressEvent
 * Obsługa zdarzenia naciśnięcia klawisza. Rozpoznaje naciśnięty klawisz i wykonuje odpowiednie operacje.
 * W przypadku klawisza strzałki następuje przemieszczenie obiektu, a w przypadku naciśnięcia Spacji - strzelania przez obiekt.
 * @param event Obiekt zdarzenia.
 * @see CanShoot::isCanShoot()
 * @see CanShoot::updateTime()
 * @see Bullet::Bullet()
 */


void Ship::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        this->directionvector.setX(-400.0f);
       /* if((this->pos().x() - 10) < -10)
        {
            return;
        }
        int number = 0;
        if(this->pos().x() - 10  < 0)
        {
            number = (this->pos().x() - 10) * (-1);
            this->setPos(QPoint(this->pos().x() - number, this->pos().y()));
            return;
        }

        this->setPos(QPoint(this->pos().x() - 10, this->pos().y()));

        */
    }
    else if(event->key() == Qt::Key_Right)
    {
        this->directionvector.setX(400.0f);
        /*
        if((this->pos().x() + this->pixmap().width() + 10) < this->scene()->width())
        {
            this->setPos(QPoint(this->pos().x() + 10, this->pos().y()));
        }
        */
    }
    else if(event->key() == Qt::Key_Up)
    {
        this->directionvector.setY(-400.0f);
        /*
        if((this->pos().y() - 10) > 0)
        {
            this->setPos(QPoint(this->pos().x(), this->pos().y() - 10));
        }
        */
    }
    else if(event->key() == Qt::Key_Down)
    {
        this->directionvector.setY(400.0f);
        /*
        if((this->pos().y() + this->pixmap().height() + 10) < this->scene()->height())
        {
            this->setPos(QPoint(this->pos().x(), this->pos().y() + 10));
        }
        */
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(this->isCanShoot())
            this->updateTime();
        else
            return;

        new Bullet(this->scene(), this->pos().x() + 20, this->pos().y() - this->pixmap().height()/2 + 5);
        new Bullet(this->scene(), this->pos().x() + 50, this->pos().y() - this->pixmap().height()/2 + 5);
        QMediaPlayer *strzal = new QMediaPlayer();
        strzal->setMedia(QUrl("qrc:/sounds/strzal.mp3"));
        strzal->setVolume(20);
        strzal->play();
    }
}
/**
 * @brief Ship::keyReleaseEvent
 * Obsługa zdarzenia zwolnienia klawisza.
 * @param event Obiekt zdarzenia.
 */

void Ship::keyReleaseEvent(QKeyEvent *event)
{
    if((event->key() == Qt::Key_Down && this->directionvector.y() != -400.0f ) || (event->key() == Qt::Key_Up && this->directionvector.y() != 400.0f))
        this->directionvector.setY(0.0f);
    else if((event->key() == Qt::Key_Right && this->directionvector.x() != -400.0f ) || (event->key() == Qt::Key_Left && this->directionvector.x() != 400.0f))
        this->directionvector.setX(0.0f);
}
/**
 * @brief Ship::updatePos
 * Ustawienie aktualnych współrzędnych położenia gracza.
 */
void Ship::updatePos()
{
    this->x1 = this->pos().x();
    this->y1 = this->pos().y();
}
/**
 * @brief Ship::die
 * Obsługa sytuacji, w której gracz traci życie.
 * @see CanShoot::isCanShoot()
 * @see CanShoot::updateTime()
 * @see Health::getHeal()
 * @see Health::decrease()
 */

void Ship::die()
{
    if(ismortal.isCanShoot())
        ismortal.updateTime();
    else
        return;

     Health::getHeal()->decrease();
     this->x1=this->scene()->width() / 2;
     this->y1=this->scene()->height()-ship->pixmap().height();
     QMediaPlayer * sound = new QMediaPlayer();
     sound->setMedia(QUrl("qrc:/sounds/death.mp3"));
     sound->setVolume(20);
     sound->play();
}
/**
 * @brief Ship::updater
 * (???)
 * @see CanShoot::isCanShoot()
 * @see die()
 */

void Ship::updater()
{
    double buffx = this->x1 + (this->directionvector.x()/60);
    double buffy = this->y1 + (this->directionvector.y()/60);

    if(buffx >= 0 && ((buffx + this->pixmap().width() <= this->scene()->width())))
        this->x1 = buffx;

    if(buffy >= 0 && (buffy + this->pixmap().height() <= this->scene()->height()))
        this->y1 = buffy;

    this->setPos(QPoint(this->x1,this->y1));

    QList<QGraphicsItem *> colliding_items=collidingItems();

    for(int i=0, n=colliding_items.size(); i<n; ++i)
    {
        if(typeid (*colliding_items[i]) == typeid(Enemy) && ismortal.isCanShoot())
        {
            Enemy *enemy= (Enemy *)colliding_items[i];
            delete enemy;
            this->die();
            return;
        }
    }
}
/**
 * @brief Ship::getShip
 * Pobranie obiektu statku gracza.
 * @return Obiekt Ship - statek gracza.
 */

Ship *Ship::getShip()
{
    return ship;
}
/**
 * @brief Ship::getX1
 * Pobranie współrzędnej x położenia gracza.
 * @return Współrzędna x położenia statku.
 */

double Ship::getX1() const
{
    return x1;
}
/**
 * @brief Ship::getY1
 * Pobranie współrzędnej y położenia gracza.
 * @return Współrzędna y położenia statku.
 */

double Ship::getY1() const
{
    return y1;
}
/**
 * @brief Ship::setup
 * Ustawienie początkowego położenia gracza w oknie.
 */

void Ship::setup()
{
    this->x1 = this->scene()->width()/2;
    this->y1 = this->scene()->height() - this->pixmap().height();
}

Ship *Ship::ship = NULL;
