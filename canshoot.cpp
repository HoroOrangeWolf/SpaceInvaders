#include "canshoot.h"
/**
  * @file canshoot.h
  * Plik nagłówkowy klasy canshoot zajmujacej sie opoznieniem w strzelaniu statku
  */

/**
 * @brief CanShoot::CanShoot
 * Konstruktor ustawiajacy opoznienie dla strzalu statku
 */

CanShoot::CanShoot()
{
    this->delay = 500;
}

/**
 * @brief CanShoot::CanShoot
 * Konstruktor ustawiajaca opoznienie podane w argumencie delay
 * @param delay Opoznienie
 */


CanShoot::CanShoot(int delay)
{
    this->delay = delay;
}

/**
 * @brief CanShoot::isCanShoot
 * Metoda sprawdzajaca czy mozna strzelac
 */


bool CanShoot::isCanShoot()
{
    using namespace std::chrono;

    auto now = system_clock::now();

    auto ms = time_point_cast<milliseconds>(now);

    auto value = ms.time_since_epoch();

    long long buff = value.count();

    return buff > (this->delay + this->lastshoot);
}

/**
 * @brief CanShoot::updateTime
 * Metoda aktualizujaca czas
 */


void CanShoot::updateTime()
{
    using namespace std::chrono;

    auto now = system_clock::now();

    auto ms = time_point_cast<milliseconds>(now);

    auto value = ms.time_since_epoch();

    this->lastshoot = value.count();

}

/**
 * @brief CanShoot::setDelay
 * Metoda ustawiajaca opoznienie dla strzalu
 * @param delay Opoznienie
 */

void CanShoot::setDelay(int c)
{
    this->delay = c;
}
