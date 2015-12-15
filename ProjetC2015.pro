QT       += core gui \
         multimedia

QT += widgets

TARGET = ProjetC2015
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    game.cpp \
    mainmenu.cpp \
    about.cpp \
    mainwindow.cpp \
    managerocket.cpp \
    rocket.cpp \
    zaap.cpp \
    player.cpp \
    managezaap.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../SFML/SFML-2.3.2/lib/ -lsfml-graphics -lsfml-main -lsfml-window -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../SFML/SFML-2.3.2/lib/ -lsfml-graphics-d -lsfml-main-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/../../../../../SFML/SFML-2.3.2/include
DEPENDPATH += $$PWD/../../../../../SFML/SFML-2.3.2/include

HEADERS += \
    game.h \
    mainmenu.h \
    about.h \
    mainwindow.h \
    managerocket.h \
    managezaap.h \
    rocket.h \
    zaap.h \
    player.h

FORMS += \
    mainmenu.ui \
    about.ui \
    mainwindow.ui


