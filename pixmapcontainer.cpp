#include "pixmapcontainer.h"
#include <map>
/**
 * @file pixmapcontiner.h
 * Plik nagłówkowy klasy PixmapContainer odpowiedzialnej za elementy graficzne.
 */
/**
 * @brief PixmapContainer::PixmapContainer
 * Konstruktor klasy PixmapContainer, tworzy zbiór elementów graficznych oraz wczytuje je do programu.
 */

PixmapContainer::PixmapContainer()
{
    pixmapcontainer = new std::map<EntityTypes, PixmapData>();

    //Wczytywanie grafik dla bullet
    {
        PixmapData rl;
        rl.size = 1;
        rl.pix = new QPixmap[1];
        QPixmap map1(":/images/pocisk.png");
        *(rl.pix) = map1.scaled(40, 8);
        pixmapcontainer->insert(std::pair<EntityTypes, PixmapData>(BULLETDEFAULT, rl));
    }

    //wczytywanie grafik dla podstawowego przeciwnika
    {
        PixmapData rl;
        rl.size = 2;
        rl.pix = new QPixmap[2];

        QPixmap map1(":/images/enemy1.png"), map2(":/images/enemy2.png");

        *(rl.pix) = map1.scaled(50, 50);
        *(rl.pix + 1) = map2.scaled(50, 50);

        pixmapcontainer->insert(std::pair<EntityTypes, PixmapData>(ENEMY1, rl));
    }
    //wczytywanie grafik dla przeciwnika z gifem
    {
        PixmapData rl;
        rl.size = 36;
        rl.pix = new QPixmap[36];


        *(rl.pix) = QPixmap(":images/res/enemy1-0.png").scaled(80, 80);
        *(rl.pix + 1) = QPixmap(":images/res/enemy1-1.png").scaled(80, 80);
        *(rl.pix + 2) = QPixmap(":images/res/enemy1-2.png").scaled(80, 80);
        *(rl.pix + 3) = QPixmap(":images/res/enemy1-3.png").scaled(80, 80);
        *(rl.pix + 4) = QPixmap(":images/res/enemy1-4.png").scaled(80, 80);
        *(rl.pix + 5) = QPixmap(":images/res/enemy1-5.png").scaled(80, 80);
        *(rl.pix + 6) = QPixmap(":images/res/enemy1-6.png").scaled(80, 80);
        *(rl.pix + 7) = QPixmap(":images/res/enemy1-7.png").scaled(80, 80);
        *(rl.pix + 8) = QPixmap(":images/res/enemy1-8.png").scaled(80, 80);
        *(rl.pix + 9) = QPixmap(":images/res/enemy1-9.png").scaled(80, 80);
        *(rl.pix + 10) = QPixmap(":images/res/enemy1-10.png").scaled(80, 80);
        *(rl.pix + 11) = QPixmap(":images/res/enemy1-11.png").scaled(80, 80);
        *(rl.pix + 12) = QPixmap(":images/res/enemy1-12.png").scaled(80, 80);
        *(rl.pix + 13) = QPixmap(":images/res/enemy1-13.png").scaled(80, 80);
        *(rl.pix + 14) = QPixmap(":images/res/enemy1-14.png").scaled(80, 80);
        *(rl.pix + 15) = QPixmap(":images/res/enemy1-15.png").scaled(80, 80);
        *(rl.pix + 16) = QPixmap(":images/res/enemy1-16.png").scaled(80, 80);
        *(rl.pix + 17) = QPixmap(":images/res/enemy1-17.png").scaled(80, 80);
        *(rl.pix + 18) = QPixmap(":images/res/enemy1-18.png").scaled(80, 80);
        *(rl.pix + 19) = QPixmap(":images/res/enemy1-19.png").scaled(80, 80);
        *(rl.pix + 20) = QPixmap(":images/res/enemy1-20.png").scaled(80, 80);
        *(rl.pix + 21) = QPixmap(":images/res/enemy1-21.png").scaled(80, 80);
        *(rl.pix + 22) = QPixmap(":images/res/enemy1-22.png").scaled(80, 80);
        *(rl.pix + 23) = QPixmap(":images/res/enemy1-23.png").scaled(80, 80);
        *(rl.pix + 24) = QPixmap(":images/res/enemy1-24.png").scaled(80, 80);
        *(rl.pix + 25) = QPixmap(":images/res/enemy1-25.png").scaled(80, 80);
        *(rl.pix + 26) = QPixmap(":images/res/enemy1-26.png").scaled(80, 80);
        *(rl.pix + 27) = QPixmap(":images/res/enemy1-27.png").scaled(80, 80);
        *(rl.pix + 28) = QPixmap(":images/res/enemy1-28.png").scaled(80, 80);
        *(rl.pix + 29) = QPixmap(":images/res/enemy1-29.png").scaled(80, 80);
        *(rl.pix + 30) = QPixmap(":images/res/enemy1-30.png").scaled(80, 80);
        *(rl.pix + 31) = QPixmap(":images/res/enemy1-31.png").scaled(80, 80);
        *(rl.pix + 32) = QPixmap(":images/res/enemy1-32.png").scaled(80, 80);
        *(rl.pix + 33) = QPixmap(":images/res/enemy1-33.png").scaled(80, 80);
        *(rl.pix + 34) = QPixmap(":images/res/enemy1-34.png").scaled(80, 80);
        *(rl.pix + 35) = QPixmap(":images/res/enemy1-35.png").scaled(80, 80);


        pixmapcontainer->insert(std::pair<EntityTypes, PixmapData>(ENEMYGIF2, rl));
    }
    //wczytywanie grafik dla naszego statku

    {
        PixmapData rl;
        rl.size = 2;
        rl.pix = new QPixmap[2];

        QPixmap map1(":/images/res/spaceship1.png"), map2(":/images/res/spaceship2.png");
        *(rl.pix) = map1.scaled(80, 80);
        *(rl.pix + 1) = map2.scaled(80, 80);

        pixmapcontainer->insert(std::pair<EntityTypes, PixmapData>(SHIP1, rl));
    }
    //wczytywanie grafiki wybuchu
    {
        PixmapData rl;
        rl.size = 17;
        rl.pix = new QPixmap[17];
        *(rl.pix) = QPixmap(":images/res/explosion-0.png").scaled(80, 80);
        *(rl.pix + 1) = QPixmap(":images/res/explosion-1.png").scaled(80, 80);
        *(rl.pix + 2) = QPixmap(":images/res/explosion-2.png").scaled(80, 80);
        *(rl.pix + 3) = QPixmap(":images/res/explosion-3.png").scaled(80, 80);
        *(rl.pix + 4) = QPixmap(":images/res/explosion-4.png").scaled(80, 80);
        *(rl.pix + 5) = QPixmap(":images/res/explosion-5.png").scaled(80, 80);
        *(rl.pix + 6) = QPixmap(":images/res/explosion-6.png").scaled(80, 80);
        *(rl.pix + 7) = QPixmap(":images/res/explosion-7.png").scaled(80, 80);
        *(rl.pix + 8) = QPixmap(":images/res/explosion-8.png").scaled(80, 80);
        *(rl.pix + 9) = QPixmap(":images/res/explosion-9.png").scaled(80, 80);
        *(rl.pix + 10) = QPixmap(":images/res/explosion-10.png").scaled(80, 80);
        *(rl.pix + 11) = QPixmap(":images/res/explosion-11.png").scaled(80, 80);
        *(rl.pix + 12) = QPixmap(":images/res/explosion-12.png").scaled(80, 80);
        *(rl.pix + 13) = QPixmap(":images/res/explosion-13.png").scaled(80, 80);
        *(rl.pix + 14) = QPixmap(":images/res/explosion-14.png").scaled(80, 80);
        *(rl.pix + 15) = QPixmap(":images/res/explosion-15.png").scaled(80, 80);
        *(rl.pix + 16) = QPixmap(":images/res/explosion-16.png").scaled(80, 80);

        pixmapcontainer->insert(std::pair<EntityTypes, PixmapData>(EXPLOSIONGIF, rl));
    }
    //wczytywanie grafiki dla bosa
    {
        PixmapData rl;
        rl.size = 29;
        rl.pix = new QPixmap[29];

        *(rl.pix) = QPixmap(":images/res/boos-0.png").scaled(150, 150);
        *(rl.pix + 1) = QPixmap(":images/res/boos-1.png").scaled(150, 150);
        *(rl.pix + 2) = QPixmap(":images/res/boos-2.png").scaled(150, 150);
        *(rl.pix + 3) = QPixmap(":images/res/boos-3.png").scaled(150, 150);
        *(rl.pix + 4) = QPixmap(":images/res/boos-4.png").scaled(150, 150);
        *(rl.pix + 5) = QPixmap(":images/res/boos-5.png").scaled(150, 150);
        *(rl.pix + 6) = QPixmap(":images/res/boos-6.png").scaled(150, 150);
        *(rl.pix + 7) = QPixmap(":images/res/boos-7.png").scaled(150, 150);
        *(rl.pix + 8) = QPixmap(":images/res/boos-8.png").scaled(150, 150);
        *(rl.pix + 9) = QPixmap(":images/res/boos-9.png").scaled(150, 150);
        *(rl.pix + 10) = QPixmap(":images/res/boos-10.png").scaled(150, 150);
        *(rl.pix + 11) = QPixmap(":images/res/boos-11.png").scaled(150, 150);
        *(rl.pix + 12) = QPixmap(":images/res/boos-12.png").scaled(150, 150);
        *(rl.pix + 13) = QPixmap(":images/res/boos-13.png").scaled(150, 150);
        *(rl.pix + 14) = QPixmap(":images/res/boos-14.png").scaled(150, 150);
        *(rl.pix + 15) = QPixmap(":images/res/boos-15.png").scaled(150, 150);
        *(rl.pix + 16) = QPixmap(":images/res/boos-16.png").scaled(150, 150);
        *(rl.pix + 17) = QPixmap(":images/res/boos-17.png").scaled(150, 150);
        *(rl.pix + 18) = QPixmap(":images/res/boos-18.png").scaled(150, 150);
        *(rl.pix + 19) = QPixmap(":images/res/boos-19.png").scaled(150, 150);
        *(rl.pix + 20) = QPixmap(":images/res/boos-20.png").scaled(150, 150);
        *(rl.pix + 21) = QPixmap(":images/res/boos-21.png").scaled(150, 150);
        *(rl.pix + 22) = QPixmap(":images/res/boos-22.png").scaled(150, 150);
        *(rl.pix + 23) = QPixmap(":images/res/boos-23.png").scaled(150, 150);
        *(rl.pix + 24) = QPixmap(":images/res/boos-24.png").scaled(150, 150);
        *(rl.pix + 25) = QPixmap(":images/res/boos-25.png").scaled(150, 150);
        *(rl.pix + 26) = QPixmap(":images/res/boos-26.png").scaled(150, 150);
        *(rl.pix + 27) = QPixmap(":images/res/boos-27.png").scaled(150, 150);
        *(rl.pix + 28) = QPixmap(":images/res/boos-28.png").scaled(150, 150);

        pixmapcontainer->insert(std::pair<EntityTypes, PixmapData>(BOSS1GIF, rl));
    }

}
/**
 * @brief PixmapContainer::~PixmapContainer
 * Destruktor klasy PixmapContainer. Usuwa obiekt pixmapcontainer oraz poszczególne elementy zbioru.
 */

PixmapContainer::~PixmapContainer()
{
    std::map<EntityTypes, PixmapData> *buffmap = pixmapcontainer;
    pixmapcontainer = NULL;

    std::map<EntityTypes, PixmapData>::iterator iter = buffmap->begin();

    for(;iter != buffmap->end(); ++iter)
        delete [] iter->second.pix;

    buffmap->clear();
    delete  buffmap;
}
/**
 * @brief PixmapContainer::getPixmapData
 * Zwraca element graficzny o podanym typie.
 * @param types Rodzaj grafiki stanowiący element typu wyliczeniowego zadeklarowanego w pliku nagłówkowym.
 * @return Element graficzny typu PixmapData wybrany ze zbioru elementów w pixmapcontainer.
 */

PixmapData PixmapContainer::getPixmapData(EntityTypes types)
{
   return pixmapcontainer->find(types)->second;
}

std::map<EntityTypes, PixmapData> *PixmapContainer::pixmapcontainer = NULL;

