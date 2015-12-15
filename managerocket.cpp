#include "managerocket.h"

ManageRocket::ManageRocket()
{
    srand(time(NULL));
}

void ManageRocket::addRocket()
{
    int random_number = rand() % 570;
    Rocket* rocket = new Rocket(1016,random_number);std::cout<<"xdxd";
    this->rockets.push_back(*rocket);
    ManageRocket::displayRocket(*rocket);

}

std::vector<Rocket> ManageRocket::getRockets()
{
    return this->rockets;
}

void ManageRocket::moveRockets()
{
    for(int i = 0; i < rockets.size();i++)
        {
            this->rockets.at(i).move();
            if(this->rockets.at(i).get_Sprite().getPosition().x<-156){
                std::cout<<"erase-rocket-outofscreen"<<std::endl;
                rockets.erase(rockets.begin() + i);
            }else ManageRocket::displayRocket(this->rockets.at(i));
        }
}

void ManageRocket::displayRocket(Rocket r)
{
    Game* game = Game::getInstance();
    sf::RenderWindow& window = game->getWindow();
    window.draw(r.get_Sprite());
}

void ManageRocket::checkImpact()
{
    std::vector<Rocket*>::iterator it;
    for(int i = 0; i < rockets.size();i++)
        {
            if(Player::getInstance().get_Sprite().getGlobalBounds().intersects(this->rockets.at(i).get_Sprite().getGlobalBounds()))
            {
               std::cout<<"erase-rocket-impact"<<std::endl;
               Player::getInstance().dead();
               rockets.erase(rockets.begin() + i);
               break;

            }
        }
}
