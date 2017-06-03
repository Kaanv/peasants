TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Player.cpp \
    Card.cpp \
    Deck.cpp \
    Game.cpp

HEADERS += \
    Player.hpp \
    Card.hpp \
    Deck.hpp \
    Game.hpp

