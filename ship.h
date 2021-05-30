#ifndef SHIP_H
#define SHIP_H
#include <QGraphicsPixmapItem>
#include <QVector2D>
#include <bullet.h>
#include <animation.h>
#include <canshoot.h>
/**
 * @file bullet.h
 * Plik nagłówkowy klasy Bullet odpowiedzialnej za tworzenie pocisków gracza.
 */
/**
 * @file animation.h
 * Plik nagłówkowy klasy Animation odpowiedzialnej za odtwarzanie animacji w programie.
 */
/**
 * @file canshoot.h
 * Plik nagłówkowy klasy CanShoot decydującej o możliwości strzelania przez gracza.
 */
/**
 * @class Ship
 * Klasa reprezentująca statek gracza.
 */

class Ship:public Animation, CanShoot{
public:
    Ship();
    ~Ship();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void updatePos();
    void die();
    void updater();
    static Ship *getShip();

    double getX1() const;
    double getY1() const;

    void setup();
private:
    QVector2D directionvector; /**< Wektor poruszania się gracza. */
    double x1 ,y1; /**< Wspolrzedne statku gracza. */
    CanShoot ismortal; /**< Zmienna decydująca o możliwości strzelania przez gracza. */
    static Ship *ship; /**< Obiekt reprezentujący statek gracza, inicjalizowany początkowo jako NULL. */
};


#endif // SHIP_H
