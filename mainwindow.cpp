#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget * parent):
QStackedWidget(parent),about(NULL)/*,menu(NULL)*/
{
about = new About(this,"about");
this->addWidget(about);
menu = new MainMenu(this,"menu");
this->addWidget(menu);
this->setCurrentWidget(menu);
this->setMinimumSize(800,600);
}

MainWindow::~MainWindow()
{
}

// slot pour changer d'onglet
void MainWindow::loadAbout()
{
this->setCurrentWidget(about);
}

void MainWindow::loadMenu()
{
    this->setCurrentWidget(menu);
}

