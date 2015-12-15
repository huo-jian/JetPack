#ifndef MISSILE_H
#define MISSILE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "personnage.h"
#include "game.h"

class Missile
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Missile(int x,int y);
    ~Missile();
    sf::Sprite get_Sprite();
    void move();
};

#endif // MISSILE_H
