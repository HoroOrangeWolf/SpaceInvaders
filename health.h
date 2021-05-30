#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

/**
 * @class Health
 * Klasa zawierająca informacje o życiu gracza.
 */

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem *parent=0);
    void decrease();
    int getHealth();
    void setHealth(int hp);
    static Health * getHeal();
private:
    int hp; /**< Zdrowie gracza jako liczba całkowita. */
    static Health *heal; /**< Obiekt przechowujący reprezentację zdrowia gracza, początkowo zainicjalizowany jako NULL. */
};




#endif // HEALTH_H
