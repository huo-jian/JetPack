#ifndef GESTIONOBSTACLE_H
#define GESTIONOBSTACLE_H

#include <vector>
#include <stdlib.h>
#include "obstacle.h"
#include "game.h"

class GestionObstacle
{
private:
    std::vector<Obstacle> obstacles;
    GestionObstacle();
    static GestionObstacle* instance;
public:
    void addObstacle();
    std::vector<Obstacle> getObstacles();
    void moveObstacles();
    void checkImpact();
    void afficherObstacle(Obstacle o);
    static GestionObstacle& getInstance()
     {
         // The only instance
         // Guaranteed to be lazy initialized
         // Guaranteed that it will be destroyed correctly
         static GestionObstacle instance;
         return instance;
     }
};

#endif // GESTIONOBSTACLE_H
