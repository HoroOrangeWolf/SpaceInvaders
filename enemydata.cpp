#include "enemydata.h"

/**
  * @file enemydata.h
  * Plik nagłówkowy klasy enemydata, przechowujacej informacje o przeciwniku.
  */

/**
 * @brief EnemyData::EnemyData
 * Konstruktor ustawiajacy informacje o przeciwniku
 * @param type Typ przeciwnika
 * @param delay  Opoznienie przed pojawieniem sie
 * @param width   Szerokosc
 * @param height   Wysokosc
 * @param health   Ilosc zdrowia
 * @param delayshoot Opoznienie pomiedzy strzalami
 */


EnemyData::EnemyData(EntityTypes type, int delay, int width, int height, int health, int delayshoot)
{
    this->types = type;
    this->delaycountercycle = delay;
    this->health = health;
    this->width = width;
    this->height = height;
    this->delayshoot = delayshoot;
}
