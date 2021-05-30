#ifndef CONTAINER_H
#define CONTAINER_H
#include <ContainerElement.h>
#include <list>

class Container
{
public:
    Container();
    static void addElement(ContainerElement *element);
    static void removeElement(ContainerElement *element);
    void updater();
private:
    static std::list<ContainerElement *> *listelement;
};

#endif // CONTAINER_H
