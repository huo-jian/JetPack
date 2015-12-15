#include "managezaap.h"

ManageZaap::ManageZaap()
{
    srand(time(NULL));
}

void ManageZaap::addZaap()
{
    int random_number = rand() % 400;
    Zaap* z = new Zaap(1016,random_number);
    this->zaaps.push_back(*z);
    ManageZaap::displayZaap(*z);
}

std::vector<Zaap> ManageZaap::getZaaps()
{
    return this->zaaps;
}

void ManageZaap::moveZaaps()
{
    for(int i = 0; i < zaaps.size();i++)
        {
            this->zaaps.at(i).move();
            if(this->zaaps.at(i).get_Sprite().getPosition().x<-97){
                std::cout<<"erase-zaap-outofscreen"<<std::endl;
                zaaps.erase(zaaps.begin() + i);
            }else ManageZaap::displayZaap(this->zaaps.at(i));
        }
}

void ManageZaap::displayZaap(Zaap z)
{
    Game* game = Game::getInstance();
    sf::RenderWindow& window = game->getWindow();
    window.draw(z.get_Sprite());
}

void ManageZaap::checkImpact()
{
    for(int i = 0; i < zaaps.size();i++)
    {
        if(Player::getInstance().get_Sprite().getGlobalBounds().intersects(this->zaaps.at(i).get_Sprite().getGlobalBounds()))
        {
            std::cout<<"ok";
           Player::getInstance().dead();
           zaaps.erase(zaaps.begin() + i);
           break;

        }
    }

}

