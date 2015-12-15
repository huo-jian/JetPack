#ifndef ROCKET_H
#define ROCKET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "game.h"

class Rocket
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int animation;
public:
    Rocket(int x,int y);
    ~Rocket();
    Rocket();
    Rocket(const Rocket&);
    sf::Sprite get_Sprite();
    void move();
    Rocket& operator=(const Rocket&);
};

#endif // ROCKET_H
