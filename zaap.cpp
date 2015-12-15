#include "zaap.h"

Zaap::Zaap(int x,int y)
{
        this->texture.loadFromFile("C:/Users/jb/Desktop/ProjetC2015/sprites_obstacle.png");
        this->sprite.setTexture(texture);
        this->sprite.setTextureRect(sf::IntRect(298,10,89,260));
        this->sprite.setPosition(x,y);
        // Les deux premières valeurs sont la position x,y dans la texture chargés
        // les deux autres sont les dimensions que l'on prend ( voir jet.png )
    std::cout<<"lolii";
    this->animation=0;
}

Zaap::~Zaap()
{
}

sf::Sprite Zaap::get_Sprite()
{
    return this->sprite;
}

void Zaap::move()
{

    animation++;
    if(animation < 6){
        this->sprite.setTextureRect(sf::IntRect(0,0,97,293));
    }else if( animation < 12){
        this->sprite.setTextureRect(sf::IntRect(97,0,97,293));
    }else if( animation < 18){
        this->sprite.setTextureRect(sf::IntRect(194,0,97,293));
    }else if( animation < 24){
        this->sprite.setTextureRect(sf::IntRect(291,0,97,293));
    }else animation = 0;
    sprite.move(-4,0);
}


