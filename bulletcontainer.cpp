#include "bulletcontainer.h"


/**
  * @file bulletcontainer
  * Plik nagłówkowy klasy bulletcontainer zarządzającej pociskami
  */


/**
 * @brief BulletContainer::BulletContainer
 * Konstruktor tworzacy liste pociskow
 */

BulletContainer::BulletContainer()
{
    bulletlist = new std::list<Bullet*>();
}

/**
 * @brief BulletContainer::~BulletContainer
 * Destruktor usuwajacy liste pociskow i resetujacy zmienne statyczne
 */

BulletContainer::~BulletContainer()
{
    std::list<Bullet*> *listbuff = bulletlist;
    bulletlist = NULL;

    for(std::list<Bullet*>::iterator buff = listbuff->begin(); buff != listbuff->end(); ++buff)
        delete *buff;

    listbuff->clear();
    delete  listbuff;
}


/**
 * @brief BulletContainer::addBullet
 * Metoda dodajaca pocisk do listy
 * @param bullet Pocisk do dodania
 */
void BulletContainer::addBullet(Bullet *bullet)
{
    bulletlist->push_front(bullet);
}

/**
 * @brief BulletContainer::updater
 * Metoda aktualizujaca pociski
 */

void BulletContainer::updater()
{
    for(std::list<Bullet*>::iterator iter = bulletlist->begin(); iter != bulletlist->end(); ++iter)
        (*iter)->updater();
}

/**
 * @brief BulletContainer::deleteBullet
 * Metoda usuwajaca pocisk z listy pocisków
 * @param bullet Pocisk
 */

void BulletContainer::deleteBullet(Bullet *bullet)
{
    if( bulletlist != NULL)
        bulletlist->remove(bullet);
}

std::list<Bullet*> *BulletContainer::bulletlist = NULL;

