TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lncurses
SOURCES += main.cpp \
    board.cpp \
    screen.cpp

HEADERS += \
    board.h \
    screen.h
