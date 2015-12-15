#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets/QStackedWidget>
#include "about.h"
#include "mainmenu.h"
#include "ui_mainwindow.h"


class MainWindow : public QStackedWidget
{
Q_OBJECT
public:
MainWindow(QWidget * parent = 0);
~MainWindow();

private slots:
void loadAbout();
void loadMenu();

private:
About* about;
MainMenu* menu;

};

#endif // MAINWINDOW_H
