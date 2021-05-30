#include "container.h"

Container::Container()
{
    listelement = new std::list<ContainerElement *>();
}

void Container::addElement(ContainerElement *element)
{
    listelement->push_front(element);
}

void Container::removeElement(ContainerElement *element)
{
    listelement->remove(element);
}

void Container::updater()
{
  std::list<ContainerElement *>::iterator iter = listelement->begin();

  for(;iter != listelement->end(); ++iter)
      (*iter)->updater();
}


std::list<ContainerElement *> *Container::listelement = NULL;
