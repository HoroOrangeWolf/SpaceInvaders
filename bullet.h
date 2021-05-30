#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QVector2D>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTransform>
#include <animation.h>

enum Types { ENEMY, SHIP };

/**
 * @class BulletContainer
 * Klasa odpowiedzialna za pociski
 */

class Bullet:public Animation
{
public:
    Bullet(QGraphicsScene *scene, int posx, int posy);
    Bullet(QGraphicsScene *scene, int posx, int posy, double xvector, double yvector, Types from);
    ~Bullet();
    bool isCanDestroy(Types from);
    void updater();
private:
    QVector2D directionvector; /**< Kierunki określone przez wektor*/
    Types from; /**< Wyliczeniowy typ danych mówiący czy wybraliśmy przeciwnika czy statek */
    double x1, y1; /**< Zmienne osi poziomej i pionowej*/
};

#endif // BULLET_H
