#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QVector2D>
#include <list>
#include <enemydata.h>
#include <animation.h>
#include <canshoot.h>



/**
 * @class Enemy
 * Klasa odpowiedzialna za podstawowe czynności związane z przeciwnikiem
 */

class Enemy:public Animation,public CanShoot
{
public:
    Enemy(QGraphicsScene *scene);
    Enemy(QGraphicsScene *scene, EnemyData data);
    ~Enemy();
    void updater();
    void shoot();
    bool isShouldShoot();
    int getHealth();
    void doDamage(int damage);
    void shoot(QVector2D val);
private:
    QVector2D vector;  /**< Wektor poruszania się */
    double x1,y1; /**< Zmienne osi poziomej i pionowej*/
    int health = 1; /**< Zdrowie */
};

#endif // ENEMY_H
