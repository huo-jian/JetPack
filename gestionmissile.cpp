#include "gestionmissile.h"

GestionMissile::GestionMissile()
{
    srand(time(NULL));
}

void GestionMissile::addMissile()
{
    int random_number = rand() % 580;
    Missile* missile = new Missile(800,random_number);
    this->missiles.push_back(*missile);
    GestionMissile::afficherMissile(*missile);
}

std::vector<Missile> GestionMissile::getMissiles()
{
    return this->missiles;
}

void GestionMissile::moveMissiles()
{
    for(int i = 0; i < missiles.size();i++)
    {
        this->missiles.at(i).move();
        GestionMissile::afficherMissile(this->missiles.at(i));
    }
}

void GestionMissile::afficherMissile(Missile m)
{
    Game* game = Game::getInstance();
    sf::RenderWindow& window = game->getWindow();
    window.draw(m.get_Sprite());
}

void GestionMissile::checkImpact()
{
    for(int i = 0; i < missiles.size();i++)
    {
        if(Personnage::getInstance().get_Sprite().getGlobalBounds().intersects(this->missiles.at(i).get_Sprite().getGlobalBounds()))
        {
            std::cout<<"ok";
           Personnage::getInstance().dead();
           break;

        }
    }

}
