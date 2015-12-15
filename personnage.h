#ifndef PERSONNAGE
#define PERSONNAGE
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "game.h"
#include <vector>

class Personnage{
private:
    int vie;
    sf::Texture texture;
    sf::Sprite sprite;
    Personnage(int vie = 10);
    static Personnage* instance;
    int move_front, move_death;
    std::vector<sf::IntRect>vector_rect;
    bool death;
public:
    ~Personnage();
    void moveDown(int s);
    void dead();
    void moveUp();
    int get_Vie()const;
    sf::Sprite get_Sprite();
    bool set_vie(int vie); // renvoi true si il est encore en vie
    bool getDeath()const;
    static Personnage& getInstance()
     {
         // The only instance
         // Guaranteed to be lazy initialized
         // Guaranteed that it will be destroyed correctly
         static Personnage instance;
         return instance;
     }
};

#endif

