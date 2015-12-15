#include "game.h"

Game::Game()
{
    this->window.create(sf::VideoMode(WIDTH,HEIGHT), "Jet Pack!");
    this->window.setFramerateLimit(60);
    this->texture.loadFromFile("C:/Users/jb/Desktop/ProjetC2015/fondinfini.png");
    this->sprite1.setTexture(texture);
    this->sprite2.setTexture(texture);
    this->sprite3.setTexture(texture);
    this->sprite1.setPosition(0,0);
    this->sprite2.setPosition(508,0);
    this->sprite3.setPosition(1016,0);

    font.loadFromFile("C:/Users/jb/Desktop/ProjetC2015/ariali.ttf");
    score.setFont(font);
    score.setPosition(500,10);
    score.setColor(sf::Color::Red);
    score.setCharacterSize(32);
}

Game::~Game()
{
}

int Game::getWidth()
{
    return WIDTH;
}

int Game::getHeight()
{
    return HEIGHT;
}

sf::Text Game::displayScore(){
    std::stringstream ss;
    ss<<"Distance : "<<(Player::getInstance().getDistanceBrowsed()/10)<<" m";
    score.setString(ss.str());
    return score;
}

sf::RenderWindow& Game::getWindow()
{
    return window;
}

sf::Sprite Game::get_Sprite1(){
    return this->sprite1;
}

sf::Sprite Game::get_Sprite2(){
    return this->sprite2;
}

sf::Sprite Game::get_Sprite3(){
    return this->sprite3;
}

sf::Texture Game::get_Texture(){
    return this->texture;
}

void Game::moveBackground()
{
    if(Player::getInstance().getDeath()==false){
        sprite1.move(-4,0);
        sprite2.move(-4,0);
        sprite3.move(-4,0);
        if(sprite1.getPosition().x == -508)
        {
            sprite1.setPosition(1016,0);
        }
        if(sprite2.getPosition().x == -508)
        {
            sprite2.setPosition(1016,0);
        }
        if(sprite3.getPosition().x == -508)
        {
            sprite3.setPosition(1016,0);
        }
    }
}

