#ifndef ENEMYCONTAINER_H
#define ENEMYCONTAINER_H

#include <QWidget>
#include <list>
#include <enemy.h>
#include <ContainerElement.h>


/**
 * @class EnemyContainer
 * Klasa odpowiedzialna za tworzenie i przechowywanie przeciwników
 */

class EnemyContainer:public QObject, ContainerElement
{
    Q_OBJECT
public:
    EnemyContainer();
    ~EnemyContainer();
    void updater();
    static void addEnemy(Enemy *enemy);
    static void removeEnemy(Enemy *enemy);
    static bool isEmpty();
    void makeEnemyShoot();
private:
    static std::list<Enemy*> *enemylist; /**< Lista służaca do przechowywania przeciwników */
    short int cycle = 0; /**< Liczba cykli */
};

#endif // ENEMYCONTAINER_H
