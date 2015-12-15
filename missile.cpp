#include "missile.h"

Missile::Missile(int x,int y)
{
        this->texture.loadFromFile("C:/Users/jb/Desktop/ProjetC2015/Missile-1.png");
        this->sprite.setTexture(texture);
        this->sprite.setTextureRect(sf::IntRect(0,0,156,72));
        this->sprite.setPosition(x,y);
        // Les deux premières valeurs sont la position x,y dans la texture chargés
        // les deux autres sont les dimensions que l'on prend ( voir jet.png )
        std::cout<<"lol";
}

Missile::~Missile()
{
}

sf::Sprite Missile::get_Sprite(){
    return this->sprite;
}

void Missile::move()
{
    if(sprite.getPosition().x > -100)
    {
        sprite.move(-4,0);
        //std::cout<<"Missile"<<sprite.getPosition().x<<","<<sprite.getPosition().y<<std::endl;
    }
    else
    {
       sprite.setPosition(-200,0);
    }
}
