#include "mainmenu.h"
#include "ui_mainmenu.h"

#include "mainwindow.h"

MainMenu::MainMenu(QWidget * parent,QString name):
QWidget(parent)
{
    this->setObjectName(name);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->setSizeConstraint(QLayout::SetMinAndMaxSize);

    gameButton = new QPushButton("Launch game",this);
    gameButton->setMaximumSize(300,100);
    QObject::connect(gameButton,SIGNAL(clicked()),this,SLOT(on_gameButton_clicked()));
    aboutButton = new QPushButton("About",this);
    aboutButton->setMaximumSize(300,100);
    QObject::connect(aboutButton,SIGNAL(clicked()),qobject_cast<MainWindow *>(parent),SLOT(loadAbout()));

    layout->addWidget(gameButton);
    layout->addWidget(aboutButton);
    this->setLayout(layout);
}

MainMenu::~MainMenu()
{
}

void MainMenu::on_gameButton_clicked()
{
        int launch_rocket  = rand()%(10-2 + 1) + 2;
        int launch_zaap = rand()%(10-2 + 1) + 2;
        sf::Clock clock_rocket;
        sf::Clock clock_zaap;
        Game* game = Game::getInstance();
        sf::RenderWindow& window = game->getWindow();
    while (window.isOpen())
        {
        window.clear();
        Game::getInstance()->getWindow().draw(Game::getInstance()->get_Sprite1());
        Game::getInstance()->getWindow().draw(Game::getInstance()->get_Sprite2());
        Game::getInstance()->getWindow().draw(Game::getInstance()->get_Sprite3());
        Game::getInstance()->moveBackground();

        Game::getInstance()->getWindow().draw(Player::getInstance().get_Sprite());
        if(Player::getInstance().getDeath() == false){ //"Quand on est mort, on ne bouge plus" de Captain Obvious
            if (sf::Keyboard::isKeyPressed((sf::Keyboard::Z)))
            {
                Player::getInstance().moveUp();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)==false)
            {
                Player::getInstance().moveDown(2); // effet gravité
            }
            if (sf::Keyboard::isKeyPressed((sf::Keyboard::S)))
            {
                Player::getInstance().moveDown(1);
            }
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::Escape)))
            {
                this->show();
                Game::getInstance()->getWindow().close();

            }
        }

        if(clock_rocket.getElapsedTime().asSeconds() > launch_rocket)
        {

            ManageRocket::getInstance().addRocket();
            launch_rocket = rand()%(10-2 + 1) + 2;
            clock_rocket.restart();
        }
        if(clock_zaap.getElapsedTime().asSeconds() > launch_zaap)
        {

            ManageZaap::getInstance().addZaap();
            std::cout<<"hello";
            launch_zaap = rand()%(10-2 + 1) + 2;
            clock_zaap.restart();
        }
        ManageRocket::getInstance().moveRockets();
        ManageRocket::getInstance().checkImpact();

        ManageZaap::getInstance().moveZaaps();
        ManageZaap::getInstance().checkImpact();
        window.draw(Game::getInstance()->displayScore());
        window.display();
    }
}


void MainMenu::on_aboutButton_clicked()
{

}
