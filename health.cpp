#include "health.h"
/**
  * @file health.h
  * Plik nagłówkowy klasy Health.
  */
#include <QFont>
#include <QFontDatabase>

/**
 * @brief Health::Health
 * Konstruktor klasy Health. Ustawia wartość "zdrowia" gracza oraz sposób jego wyświetlania.
 * @param parent Obiekt QGraphicsItem do wyświetlenia zdrowia.
 * @see Health::getHealth()
 */
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{

    hp=3;
    int id = QFontDatabase::addApplicationFont(":/fonts/font1.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont monospace(family);
    monospace.setPixelSize(30);
    setFont(monospace);
    int c = Health::getHealth();
    QString strin("");
    for(int i = 0; i < c; ++i)
        {
            strin += QString(" *");
        };
    setPlainText(QString("Health: ")+strin);

    setDefaultTextColor(Qt::red);


    heal = this;
}
/**
 * @brief Health::decrease
 * Użycie w przypadku zmniejszenia życia gracza.
 * @see Health::getHealth()
 */


void Health::decrease()
{
    hp--;
    int c = Health::getHealth();
    QString strin("");
    for(int i = 0; i < c; ++i)
        {
            strin += QString(" *");
        };
    setPlainText(QString("Health: ")+strin);

}

/**
 * @brief Health::getHealth
 * Pobranie wartości zmiennej hp - informacja o zdrowiu gracza.
 * @return Liczba całkowita - zdrowie gracza.
 */

int Health::getHealth()
{
    return hp;
}
/**
 * @brief Health::setHealth
 * Ustawienie wartości zmiennej hp - zdrowia gracza.
 * @param hp Liczba typu integer - zdrowie gracza.
 */

void Health::setHealth(int hp)
{
    this->hp = hp;
}
/**
 * @brief Health::getHeal
 * Pobranie obiektu klasy Health - zdrowia gracza.
 * @return Obiekt klasy Health.
 */


Health *Health::getHeal()
{
    return heal;
}

Health * Health::heal=NULL;
