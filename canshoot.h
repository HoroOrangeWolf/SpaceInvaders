#ifndef CANSHOOT_H
#define CANSHOOT_H
#include <chrono>

/**
 * @class CanShoot
 * Klasa odpowiedzialna za szczegóły związane ze strzelaniem ( np. opóźnienie strzału)
 */

class CanShoot
{
public:
    CanShoot();
    CanShoot(int delay);
    bool isCanShoot();
    void updateTime();
    void setDelay(int c);
private:
    long long lastshoot = 0; /**< Kiedy został oddany ostatni strzał*/
    long long delay; /**< Opóźnienie */
};

#endif // CANSHOOT_H
