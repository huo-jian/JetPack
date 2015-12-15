#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "personnage.h"
#include "game.h"

class Obstacle
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        int animation;
    public:
        Obstacle(int x,int y);
        ~Obstacle();
        sf::Sprite get_Sprite();
        void move();
};

#endif // OBSTACLE_H
