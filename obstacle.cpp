#include "obstacle.h"

Obstacle::Obstacle(int x,int y)
{
        this->texture.loadFromFile("C:/Users/jb/Desktop/ProjetC2015/sprites_obstacle.png");
        this->sprite.setTexture(texture);
        this->sprite.setTextureRect(sf::IntRect(298,10,89,260));
        this->sprite.setPosition(x,y);
        // Les deux premières valeurs sont la position x,y dans la texture chargés
        // les deux autres sont les dimensions que l'on prend ( voir jet.png )
    std::cout<<"lol";
    this->animation=0;
}

Obstacle::~Obstacle()
{
}

sf::Sprite Obstacle::get_Sprite(){
    animation++;
    if(animation > 24){
        this->sprite.setTextureRect(sf::IntRect(0,0,97,293));
    }else if( animation > 48){
        this->sprite.setTextureRect(sf::IntRect(194,0,97,293));
    }else if( animation > 72){
        this->sprite.setTextureRect(sf::IntRect(291,0,97,293));
    }else if( animation > 96){
        this->sprite.setTextureRect(sf::IntRect(388,0,97,293));
    }else animation = 0;
    return this->sprite;
}

void Obstacle::move()
{
    if(sprite.getPosition().x > -100)
    {
        sprite.move(-2,0);
        //std::cout<<"Missile"<<sprite.getPosition().x<<","<<sprite.getPosition().y<<std::endl;
    }
    else
    {
       sprite.setPosition(-100,0);
    }
}

