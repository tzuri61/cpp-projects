TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        battleship.cpp \
        gameboard.cpp \
        main.cpp \
        part.cpp \
        player.cpp \
        ship.cpp

HEADERS += \
  battleship.h \
  gameboard.h \
  part.h \
  player.h \
  ship.h
