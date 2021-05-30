#ifndef ANIMATIONCONTAINER_H
#define ANIMATIONCONTAINER_H

#include <QObject>
#include <list>
#include <animation.h>
#include <QPixmap>
#include <ContainerElement.h>

/**
 * @class animationcontainer
 * Klasa odpowiedzialna za przechowywanie animacji
 */

class AnimationContainer:public QObject,ContainerElement
{
    Q_OBJECT
public:
    AnimationContainer();
    ~AnimationContainer();
    void static addAnimation(Animation *anim);
    void static removeAnimation(Animation *anim);
    void updater();
private:
    static std::list<Animation *>  *animationcon; /**< Lista wskaźników animacji*/
};

#endif // ANIMATIONCONTAINER_H
