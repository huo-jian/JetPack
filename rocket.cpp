#include "rocket.h"

Rocket::Rocket(){

}
Rocket::Rocket(int x,int y)
{
        animation = 0;
        this->texture.loadFromFile("C:/Users/jb/Desktop/ProjetC2015/Missile-1.png");
        this->sprite.setTexture(texture);
        this->sprite.setTextureRect(sf::IntRect(0,0,156,72));
        this->sprite.setPosition(x,y);
        // Les deux premières valeurs sont la position x,y dans la texture chargés
        // les deux autres sont les dimensions que l'on prend ( voir jet.png )
        std::cout<<"lol";
}

Rocket::~Rocket()
{
}

Rocket::Rocket(const Rocket& original){
    texture = original.texture;
    sprite = original.sprite;
}

Rocket& Rocket::operator=(const Rocket& src) {
    if (this != &src) {
        texture = src.texture;
        sprite = src.sprite;
    }
    return *this;
}

sf::Sprite Rocket::get_Sprite(){
    return this->sprite;
}

void Rocket::move()
{
    animation++;
    if(animation<12){
        sprite.setRotation(7);
    }else if(animation<24){
        sprite.setRotation(-7);
    }else animation=0;
    sprite.move(-25,0);

}
