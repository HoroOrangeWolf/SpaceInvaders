#include "enemycontainer.h"
#include <time.h>
#include <QDebug>
#include <QGraphicsScene>
#include <QVector2D>

/**
  * @file enemycontainer.h
  * Plik nagłówkowy klasy odpowiedzialnej za przechowywanie przeciwników
  */



/**
 * @brief EnemyContainer::EnemyContainer
 * Konstruktor tworzacy liste przeciwnikow
 */



EnemyContainer::EnemyContainer()
{
    if(enemylist != NULL)
        throw "Error";

    enemylist = new std::list<Enemy*>();
    srand(time(NULL));

}

/**
 * @brief EnemyContainer::~EnemyContainer
 * Destruktor  usuwajacy liste przeciwnikow i resetujacy zmienne statyczne
 */

EnemyContainer::~EnemyContainer()
{
    std::list<Enemy*> *listbuff = enemylist;

    enemylist = NULL;

    std::list<Enemy*>::iterator buff = listbuff->begin();

    for(; buff != listbuff->end(); ++buff)
        delete *buff;

    listbuff->clear();
    delete  listbuff;
}

/**
 * @brief EnemyContainer::updater
 * Metoda aktualizująca przeciwnikow
 */

void EnemyContainer::updater()
{
    for(std::list<Enemy*>::iterator iterator = enemylist->begin(); iterator != enemylist->end(); ++iterator)
        (*iterator)->updater();

    this->makeEnemyShoot();
}

/**
 * @brief EnemyContainer::addEnemy
 * Metoda dodajaca przeciwnika
 * @param enemy Obiekt klasy enemy - przeciwnik
 */

void EnemyContainer::addEnemy(Enemy *enemy)
{
    enemylist->push_front(enemy);
}

/**
 * @brief EnemyContainer::removeEnemy
 * Metoda usuwajaca przeciwnika
 * @param enemy Obiekt klasy enemy - przeciwnik
 */


void EnemyContainer::removeEnemy(Enemy *enemy)
{
    if(enemylist != NULL)
        enemylist->remove(enemy);
}

/**
 * @brief EnemyContainer::isEmpty
 * Metoda sprawdzajaca czy lista przeciwnikow jest pusta
 * @return Zwraca czy lista jest pusta
 */

bool EnemyContainer::isEmpty()
{
    return enemylist->empty();
}

/**
 * @brief EnemyContainer::makeEnemyShoot
 * Metoda sprawiajaca że przeciwnik strzela w zaleznosci od cykli
 */

void EnemyContainer::makeEnemyShoot()
{
    if(enemylist->size() == 0)
        return;

    if(this->cycle < 15)
    {
        this->cycle++;
        return;
    }
    else
        this->cycle = 0;

    std::list<Enemy*>::iterator iterator = enemylist->begin();

    for(int i = 0, counter = 0; iterator != enemylist->end(); ++iterator, ++i)
        if((*iterator)->isShouldShoot() && (*iterator)->isCanShoot())
        {
            if(counter < 5)
               counter++;
            else
                break;

            (*iterator)->shoot(QVector2D(250.0f, 400.0f));
            (*iterator)->shoot(QVector2D(0.0f, 400.0f));
            (*iterator)->shoot(QVector2D(-250.0f, 400.0f));
            (*iterator)->updateTime();
        }
}

std::list<Enemy*> *EnemyContainer::enemylist = NULL;

