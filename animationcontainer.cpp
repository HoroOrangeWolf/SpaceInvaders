#include "animationcontainer.h"


/**
 * @file animationcontainer.h
 * Plik nagłówkowy klasy animatiorcontainer odpowiedzialnej za przechowywanie animacji
 */

/**
 * @brief AnimationContainer::AnimationContainer
 * Konstruktor klasy tworzący listę wskaźników animacji
 */

AnimationContainer::AnimationContainer()
{
    animationcon = new std::list<Animation *>();
}

/**
 * @brief AnimationContainer::~AnimationContainer
 * Destruktor klasy zwalniający pamięć
 */

AnimationContainer::~AnimationContainer()
{
    std::list<Animation*> *listbuff = animationcon;

    animationcon = NULL;
    std::list<Animation*>::iterator buff = listbuff->begin();

    for(; buff != listbuff->end(); ++buff)
        delete *buff;

    listbuff->clear();
    delete  listbuff;
}

/**
 * @brief AnimationContainer::addAnimation
 * Metoda dodająca animacje
 * @param anim Wskaźnik na animacje
 */
void AnimationContainer::addAnimation(Animation *anim)
{
    animationcon->push_front(anim);
}
/**
 * @brief AnimationContainer::removeAnimation
 * Metoda usuwająca animacje
 * @param anim Wskaźnik na animacje
 */

void AnimationContainer::removeAnimation(Animation *anim)
{
    if(animationcon != NULL)
        animationcon->remove(anim);
}

/**
 * @brief AnimationContainer::updater
 * Metoda wywołująca updater każdej klasy zawartej w liście
 */
void AnimationContainer::updater()
{
    std::list<Animation *>::iterator iter = animationcon->begin();

    for(; iter != animationcon->end(); ++iter)
        (*iter)->updater();

}

std::list<Animation *> *AnimationContainer::animationcon = NULL;
