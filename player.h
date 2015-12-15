#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "game.h"
#include <vector>

class Player{
private:

    sf::Texture texture;
    sf::Sprite sprite;
    Player();
    static Player* instance;
    int move_front, move_death;
    std::vector<sf::IntRect>vector_rect;
    bool death;
    int distanceBrowsed;
public:
    ~Player();
    void moveDown(int s);
    void dead();
    void moveUp();
    int getDistanceBrowsed()const;
    sf::Sprite get_Sprite();
    bool getDeath()const;
    static Player& getInstance()
     {
         // The only instance
         // Guaranteed to be lazy initialized
         // Guaranteed that it will be destroyed correctly
         static Player instance;
         return instance;
     }
};

#endif

