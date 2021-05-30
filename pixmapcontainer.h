#ifndef PIXMAPCONTAINER_H
#define PIXMAPCONTAINER_H
#include <QPixmap>
#include <map>
/**
 * @enum EntityTypes
 * Zmienna typu wyliczeniowego będąca rodzajem grafiki.
 */
enum EntityTypes { BULLETDEFAULT, ENEMY1, SHIP1, ENEMYGIF2, EXPLOSIONGIF, BOSS1GIF};

/**
 * @struct PixmapData
 * Struktura przechowująca grafikę.
 */
struct PixmapData{
    int size; /**< Rozmiar grafiki */
    QPixmap *pix = NULL; /**< Obiekt QPixmap przechowujący pojedynczy element graficzny. */
};

/**
 * @class PixmapContainer
 * Klasa odpowiedzialna za tworzenie i przechowywanie elementów graficznych.
 */
class PixmapContainer
{
public:
    PixmapContainer();
    ~PixmapContainer();
    static PixmapData getPixmapData(EntityTypes types);
private:
    static std::map<EntityTypes, PixmapData> *pixmapcontainer; /**< Zbiór elementów graficznych */
};

#endif // PIXMAPCONTAINER_H
