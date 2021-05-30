#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include <pixmapcontainer.h>
#include <ContainerElement.h>
#include <list>
#include <QGraphicsScene>
#include <enemydata.h>


/**
 * @class EnemyData
 * Klasa odpowiedzialna za obsługe/spawnowanie przeciwników
 */

class EnemySpawner: public ContainerElement
{
public:
    EnemySpawner(QGraphicsScene *scene);
    void updater();
    void addEnemyToSpawn(EnemyData &data);
    void addEnemyToSpawn(EntityTypes types, int delay);
    static bool getIsempty();

private:
    std::list<EnemyData> listelements; /**< Lista przeciwników. */
    QGraphicsScene *scene = NULL;  /**< Wskaźnik na scene */
    static bool isempty;  /**< Zmienna logiczna sprawdzajaca czy spawner jest pusty */
};

#endif // ENEMYSPAWNER_H
