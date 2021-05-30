#ifndef ANIMATION_H
#define ANIMATION_H
#include <QGraphicsPixmapItem>
#include <QObject>

/**
 * @class animation
 * Klasa odpowiedzialna za animacje
 */

class Animation: public QGraphicsPixmapItem
{
public:
    Animation(int width, int height, QPixmap maps[], int sizemap);
    Animation();
    ~Animation();
    void start();
    void stop();
    void updater();
    void setLifeSpan(int lifespan);
protected:
    int cyclecounter = 0; /**< Licznik cykli*/
    int interval; /**< Przerwa pomiedzy klatkami */
    int mapsize = -1; /**< Rozmiar tablicy z animacjami */
    int currentindex = 0; /**< Aktualny indeks*/
    int lifespan; /**< jeżeli animacja ma zniknąć, ta zmienna będzie zawierała ilość cykli życia animacji*/
    bool islifespan; /**< jeżeli animacja ma zniknąć po jakimś czasie ustawiamy true*/
    QPixmap *map = NULL; /**< Wskaźnik na QPixmap*/
    void init(int width, int height, QPixmap maps[], int sizemap); /** <Metoda inicjująca animacje */
    void init(int width, int height, QPixmap maps[], int sizemap, int intervalcycle);  /** <Metoda inicjująca animacje  */
    void reupdater(); /**< Metoda sprawdzająca czy jest możliwość usunięcia animacji*/
};

#endif // ANIMATION_H
