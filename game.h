#ifndef GAME_H
#define GAME_H
#define WIDTH 1016
#define HEIGHT 720
#include <stack>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "player.h"
#include <sstream>

class Game
{
private:
     Game();
    static Game* instance;
    sf::RenderWindow window;
    sf::Sprite sprite1,sprite2,sprite3;
    sf::Texture texture;
    sf::Text score;
    sf::Font font;
    int elapsedTime;
public:
    int getWidth();
    int getHeight();
    sf::Text displayScore();
    sf::Texture get_Texture();
    sf::Sprite get_Sprite1();
    sf::Sprite get_Sprite2();
    sf::Sprite get_Sprite3();
    sf::RenderWindow& getWindow();
    void moveBackground();
    ~Game();
    static Game* getInstance()
     {
         // The only instance
         // Guaranteed to be lazy initialized
         // Guaranteed that it will be destroyed correctly
         static Game* instance = new Game();
         return instance;
     }
};

#endif // GAME_H
