#ifndef BULLETCONTAINER_H
#define BULLETCONTAINER_H

#include <QObject>
#include <list>
#include <bullet.h>
#include <ContainerElement.h>


/**
 * @class BulletContainer
 * Klasa przechowująca pociski
 */

class BulletContainer: public QObject, ContainerElement
{
    Q_OBJECT
public:
    BulletContainer();
    ~BulletContainer();
    static void addBullet(Bullet *bullet);
    void updater();
    void static deleteBullet(Bullet *bullet);
private:
    static std::list<Bullet*> *bulletlist; /**< Lista przechowująca pociski*/
};

#endif // BULLETCONTAINER_H
