#ifndef CONTAINERELEMENT_H
#define CONTAINERELEMENT_H


/**
 * @class ContainerElement
 * Klasa abstrakcyjna
 */

class ContainerElement{
public:
    virtual void updater() = 0;
    virtual ~ContainerElement(){};
};

#endif // CONTAINERELEMENT_H
