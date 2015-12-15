#include "gestionobstacle.h"

GestionObstacle::GestionObstacle()
{
    srand(time(NULL));
}

void GestionObstacle::addObstacle()
{
    int random_number = rand() % 300;
    Obstacle* o = new Obstacle(800,random_number);
    this->obstacles.push_back(*o);
    GestionObstacle::afficherObstacle(*o);
}

std::vector<Obstacle> GestionObstacle::getObstacles()
{
    return this->obstacles;
}

void GestionObstacle::moveObstacles()
{
    for(int i = 0; i < obstacles.size();i++)
    {
        this->obstacles.at(i).move();
        GestionObstacle::afficherObstacle(this->obstacles.at(i));
    }
}

void GestionObstacle::afficherObstacle(Obstacle m)
{
    Game* game = Game::getInstance();
    sf::RenderWindow& window = game->getWindow();
    window.draw(m.get_Sprite());
}

void GestionObstacle::checkImpact()
{
    for(int i = 0; i < obstacles.size();i++)
    {
        if(Personnage::getInstance().get_Sprite().getGlobalBounds().intersects(this->obstacles.at(i).get_Sprite().getGlobalBounds()))
        {
            std::cout<<"ok";
           Personnage::getInstance().dead();
           break;

        }
    }

}

