#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T16:32:08
#
#-------------------------------------------------

QT       -= gui

TARGET = UGameEngine
TEMPLATE = lib

DEFINES += UGAMEENGINE_LIBRARY

SOURCES += ugameengine.cpp

HEADERS += ugameengine.h\
        ugameengine_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
