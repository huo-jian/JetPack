#ifndef GESTIONMISSILE_H
#define GESTIONMISSILE_H
#include <vector>
#include <stdlib.h>
#include "missile.h"
#include "game.h"
class GestionMissile
{
private:
    std::vector<Missile> missiles;
    GestionMissile();
    static GestionMissile* instance;
public:
    void addMissile();
    std::vector<Missile> getMissiles();
    void moveMissiles();
    void checkImpact();
    void afficherMissile(Missile m);
    static GestionMissile& getInstance()
     {
         // The only instance
         // Guaranteed to be lazy initialized
         // Guaranteed that it will be destroyed correctly
         static GestionMissile instance;
         return instance;
     }
};

#endif // GESTIONMISSILE_H
