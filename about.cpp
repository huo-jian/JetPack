#include "about.h"
#include "mainmenu.h"
#include "mainwindow.h"
#include <QVBoxLayout>

About::About(QWidget * parent,QString name):
QWidget(parent)
{
    this->setObjectName(name);
    aboutlabel = new QLabel("Game created by \nBouillez Jordan\nMauroit Jean-Baptiste\nRochez Adrien\nVerhelle Romain",this);
    returnButton = new QPushButton("Return",this);
    returnButton->setMinimumSize(300,100);
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(aboutlabel);
    layout->addWidget(returnButton);
    this->setLayout(layout);
    QObject::connect(returnButton,SIGNAL(clicked()),qobject_cast<MainWindow *>(parent),SLOT(loadMenu()));
}

About::~About()
{
}

void About::on_return_clicked()
{

}

