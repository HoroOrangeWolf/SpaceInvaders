#include "enemyspawner.h"
#include <enemy.h>


/**
  * @file enemyspawner.h
  * Plik nagłówkowy klasy enemyspawner , zajmujący się przeciwnikami.
  */

/**
 * @file enemy.h
 * Plik nagłówkowy klasy Enemy reprezentującej obiekt przeciwnika.
 */


/**
 * @brief EnemySpawner::EnemySpawner
 * Konstruktor klasy EnemySpawner
 * @param scene Wskaznik na obiekt klasy QGraphicsScene
 */

EnemySpawner::EnemySpawner(QGraphicsScene *scene)
{
    this->scene = scene;
    isempty = false;
}

/**
 * @brief EnemySpawner::updater
 * Metoda  spawnujaca przeciwnika po okreslonej ilosci cykli
 */

void EnemySpawner::updater()
{
    if(this->listelements.begin() != this->listelements.end())
    {
        if((*this->listelements.begin()).delaycountercycle > 0)
            (*this->listelements.begin()).delaycountercycle--;
        else
        {
            new Enemy(this->scene, *(this->listelements.begin()));
            this->listelements.pop_front();
        }
        isempty = false;
    }
    else
        isempty = true;
}
/**
 * @brief EnemySpawner::addEnemyToSpawn
 * Metoda dodajaca przeciwnikow do klasy ktora bedzie ich spawnowala
 * @param data Informacje o przeciwniku
 */

void EnemySpawner::addEnemyToSpawn(EnemyData &data)
{
    this->listelements.push_back(data);
}

/**
 * @brief EnemySpawner::addEnemyToSpawn
 * Metoda dodajaca przeciwnikow do klasy ktora bedzie ich spawnowala
 * @param types Rodzaj przeciwnika
 * @param delay Opoznienie przed pojawieniem sie przeciwnika
 */

void EnemySpawner::addEnemyToSpawn(EntityTypes types, int delay)
{
    this->listelements.push_back(EnemyData(types, delay));
}

/**
 * @brief EnemySpawner::getIsempty
 * Metoda typu bool zwracajaca czy spawner jest pusty
 * @return zmienna sprawdzajaca czy spawner jest pusty
 */

bool EnemySpawner::getIsempty()
{
    return isempty;
}

bool EnemySpawner::isempty = false;
