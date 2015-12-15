#ifndef MAINMENU_H
#define MAINMENU_H
#include <QVBoxLayout>
#include <QWidget>
#include "managezaap.h"
#include "game.h"
#include "player.h"
#include "managerocket.h"
#include "ui_mainmenu.h"

namespace Ui {
    class MainMenu;

}

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    ~MainMenu();
    MainMenu(QWidget *parent = 0,QString name = "menu");
private:
    QPushButton* gameButton;
    QPushButton* aboutButton;

private slots:
    void on_gameButton_clicked();
    void on_aboutButton_clicked();

signals:
    void load(QString name);
};

#endif // MAINMENU_H


