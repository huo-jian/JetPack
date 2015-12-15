#ifndef MANAGEROCKET_H
#define MANAGEROCKET_H
#include <vector>
#include <stdlib.h>
#include "rocket.h"
#include "game.h"
class ManageRocket
{
private:
    std::vector<Rocket> rockets;
    ManageRocket();
    static ManageRocket* instance;
public:
    void addRocket();
    std::vector<Rocket> getRockets();
    void moveRockets();
    void checkImpact();
    void displayRocket(Rocket r);
    static ManageRocket& getInstance()
     {
         // The only instance
         // Guaranteed to be lazy initialized
         // Guaranteed that it will be destroyed correctly
         static ManageRocket instance;
         return instance;
     }
};

#endif // GESTIONMISSILE_H
