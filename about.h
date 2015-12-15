#ifndef ABOUT_H
#define ABOUT_H
#include<QWidget>
#include<QtWidgets/QLabel>
#include "ui_mainmenu.h"

class About : public QWidget
{
    Q_OBJECT
public:
    About(QWidget * parent,QString name);
    ~About();
private:
    QPushButton* returnButton;
    QLabel* aboutlabel;

public slots:
void on_return_clicked();

};

#endif // ABOUT_H
