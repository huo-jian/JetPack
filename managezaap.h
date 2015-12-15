#ifndef MANAGEZAAP_H
#define MANAGEZAAP_H

#include <vector>
#include <stdlib.h>
#include "zaap.h"
#include "game.h"

class ManageZaap
{
private:
    std::vector<Zaap> zaaps;
    ManageZaap();
    static ManageZaap* instance;
public:
    void addZaap();
    std::vector<Zaap> getZaaps();
    void moveZaaps();
    void checkImpact();
    void displayZaap(Zaap o);
    static ManageZaap& getInstance()
     {
         // The only instance
         // Guaranteed to be lazy initialized
         // Guaranteed that it will be destroyed correctly
         static ManageZaap instance;
         return instance;
     }
};

#endif // GESTIONOBSTACLE_H
