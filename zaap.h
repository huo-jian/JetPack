#ifndef ZAAP_H
#define ZAAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "game.h"

class Zaap
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        int animation;
    public:
        Zaap(int x,int y);
        ~Zaap();
        sf::Sprite get_Sprite();
        void move();
};

#endif // ZAAP_H
