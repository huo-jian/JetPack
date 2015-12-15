#include "player.h"

Player::~Player()
{

}

Player::Player()
{
    //Compteur pour chaque animation
    this->move_death=0;this->move_front=0;
    //Pour savoir si l'état mort ou vivant
    death = false;
    //Vecteur de tout les coordonées dans le sprite du personnage
    std::cout<<"wesh";
    vector_rect.push_back(sf::IntRect(0,0,42,58));   // 0-run1
    vector_rect.push_back(sf::IntRect(42,0,48,56));  // 1-run2
    vector_rect.push_back(sf::IntRect(128,0,34,66)); // 2-jump1
    vector_rect.push_back(sf::IntRect(162,0,34,72)); // 3-jump2
    vector_rect.push_back(sf::IntRect(90,0,38,64));  // 4-fall1
    vector_rect.push_back(sf::IntRect(196,0,38,64)); // 5-fall2
    vector_rect.push_back(sf::IntRect(303,0,66,32)); // 6-death1
    vector_rect.push_back(sf::IntRect(244,0,47,60)); // 7-death2
    vector_rect.push_back(sf::IntRect(350,0,69,46)); // 8-death3


    this->texture.loadFromFile("C:/Users/jb/Desktop/ProjetC2015/sprite_player.png");
    this->texture.setSmooth(true);
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(vector_rect[0]);
    this->sprite.setPosition(35,50);
    std::cout<<sprite.getPosition().x<<","<<sprite.getPosition().y<<std::endl;
}
void Player::moveDown(int s){
    this->distanceBrowsed++;
    if(sprite.getPosition().y>=570){
        move_front++;
        if(move_front>12){
            sprite.setTextureRect(vector_rect[0]);
        }else {
            sprite.setTextureRect(vector_rect[1]);
        }
        if(move_front>24){
            move_front=0;
        }
    }
    else if(sprite.getPosition().y <= 570)
    {
        sprite.setTexture(texture);
        if(s==1)
              sprite.setTextureRect(vector_rect[5]);
        else
              sprite.setTextureRect(vector_rect[4]);

        sprite.move(0,8);
        std::cout<<sprite.getPosition().x<<","<<sprite.getPosition().y<<std::endl;
    }
}
void Player::moveUp(){
    this->distanceBrowsed++;
    this->sprite.setTextureRect(vector_rect[3]);
    if(sprite.getPosition().y > 80)
    {
        sprite.move(0,-10);
        std::cout<<sprite.getPosition().x<<","<<sprite.getPosition().y<<std::endl;
    }
    else
    {
       sprite.setPosition(sprite.getPosition().x,80);
    }
}

sf::Sprite Player::get_Sprite(){
    return this->sprite;
}
bool Player::getDeath()const{return death;}
void Player::dead()
{
    death = true;
    this->sprite.setTextureRect(vector_rect[7]);
    while(Player::getInstance().get_Sprite().getPosition().y <=600)
    {
        this->sprite.move(0,2);
        Game::getInstance()->getWindow().draw(this->sprite);
    }
    //this->sprite.setTextureRect((sf::IntRect(485,156,105,53)));
}

int Player::getDistanceBrowsed()const{
    return this->distanceBrowsed;
}
