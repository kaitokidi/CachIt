#-------------------------------------------------
#
# Project created by QtCreator 2014-02-09T10:12:02
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = cachit
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -L"/usr/SFML/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/usr/include"
DEPENDPATH += "/usr/include"

SOURCES += main.cpp \
    control.cpp \
    stats.cpp \
    background.cpp \
    wordblock.cpp

HEADERS += \
    control.h \
    stats.h \
    background.h \
    wordblock.h

RESOURCES += \
    MyResources.qrc


