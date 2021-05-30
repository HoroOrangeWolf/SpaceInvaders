#ifndef ENEMYDATA_H
#define ENEMYDATA_H
#include <pixmapcontainer.h>


/**
 * @class EnemyData
 * Klasa odpowiedzialna za statystyki przeciników
 */

class EnemyData
{
public:
    EnemyData(EntityTypes type, int delay, int width = 80, int height = 80, int health = 1,int delayshoot = 2000);
    EntityTypes types;  /**< Rodzaj przeciwnika */
    int delaycountercycle; /**< Cykle opoznienia przeciwnika */
    int delayshoot; /**< Opoznienie strzału*/
    int health; /**< Zdrowie */
    int width; /**< Szerokość */
    int height; /**< Wysokość */
};

#endif // ENEMYDATA_H
