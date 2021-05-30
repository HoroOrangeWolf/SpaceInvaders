#include "animation.h"
#include <animationcontainer.h>
#include <QGraphicsScene>

/**
 * @file animation.h
 * Plik nagłówkowy klasy Animation odpowiedzialnej za animacje
 */


/**
 * @brief Animation::Animation
 * Konstruktor klasy ładujący odpowiednie obrazy oraz przeskalowujący je na odpowiednie wymiary
 * @param width Szerokość
 * @param height Wysokość
 * @param maps Klatki animacji
 * @param sizemap Rozmiar tablicy
 */

Animation::Animation(const int width,const int height, QPixmap maps[],const int sizemap)
{
    this->map = new QPixmap[sizemap];

    for(int i = 0; i < sizemap; ++i)
        if(maps[i].width() == width && maps[i].height() == height)
            *(this->map + i) = maps[i];
        else
            *(this->map + i) = maps[i].scaled(width, height);

    this->interval = 60/sizemap;
    this->mapsize = sizemap;
    this->setPixmap(this->map[0]);
    this->islifespan = false;
}

/**
 * @brief Animation::Animation
 * Domyślny konstruktor klasy
 */

Animation::Animation()
{
    this->islifespan = false;
}
/**
 * @brief Animation::~Animation
 * Destruktor zwalniający pamięć przeznaczoną na klatki animacji oraz usuwający sam z siebie z klasy Animation
 */
Animation::~Animation()
{
    delete [] (this->map);

    AnimationContainer::removeAnimation(this);
}

/**
 * @brief Animation::updater
 * Metoda klasy animation sterująca działaniem klasy , zmienia ona klatki animacji
 */
void Animation::updater()
{
    this->cyclecounter++;

    if(this->cyclecounter == this->interval)
    {
        this->cyclecounter = 0;
        this->currentindex++;
    }
    if(this->currentindex > (this->mapsize - 1))
        this->currentindex = 0;

    this->setPixmap(this->map[this->currentindex]);

    if(this->islifespan)
        this->reupdater();
}

/**
 * @brief Animation::setLifeSpan
 * Metoda ustawiajaca
 * @param lifespan
 */

void Animation::setLifeSpan(int lifespan)
{
    this->islifespan = true;
    this->lifespan = lifespan;
}
/**
 * @brief Animation::start
 * Metoda dodająca/startująca animacje
 */

void Animation::start()
{
    AnimationContainer::addAnimation(this);
}
/**
 * @brief Animation::stop
 * Metoda usuwająca/stopująca animacje
 */

void Animation::stop()
{
    AnimationContainer::removeAnimation(this);
}

/**
 * @brief Animation::init
 * Metoda dodająca klatki animacji
 * @param width Szerokość
 * @param height Długość
 * @param maps Klatki animacji
 * @param sizemap Rozmiar tablicy
 */
void Animation::init(int width, int height, QPixmap maps[], int sizemap)
{
    this->map = new QPixmap[sizemap];

    for(int i = 0; i < sizemap; ++i)
        if(maps[i].width() == width && maps[i].height() == height)
            *(this->map + i) = maps[i];
        else
            *(this->map + i) = maps[i].scaled(width, height);

    this->interval = 60/sizemap;
    this->mapsize = sizemap;

    this->setPixmap(this->map[0]);
}
/**
 * @brief Animation::init
 * Metoda dodająca klatki animacji z dodatkiem przerwy pomiędzy klatkami
 * @param width Szerokość
 * @param height Długość
 * @param maps Klatki animacji
 * @param sizemap Rozmiar tablicy
 * @param intervalcycle Przerwa pomiędzy klatkami animacji
 */

void Animation::init(int width, int height, QPixmap maps[], int sizemap, int intervalcycle)
{
    this->map = new QPixmap[sizemap];

    for(int i = 0; i < sizemap; ++i)
        if(maps[i].width() == width && maps[i].height() == height)
            *(this->map + i) = maps[i];
        else
            *(this->map + i) = maps[i].scaled(width, height);

    this->interval = intervalcycle;
    this->mapsize = sizemap;

    this->setPixmap(this->map[0]);
}
/**
 * @brief Animation::reupdater
 * Metoda sprawdzająca czy jest możliwość usunięcia animacji
 */

void Animation::reupdater()
{
    if(this->lifespan>0)
        this->lifespan--;
    else
    {
        if(this->scene() != NULL)
            this->scene()->removeItem(this);
        delete this;
    }
    return;
}
