#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T16:32:08
#
#-------------------------------------------------

QT       -= gui

TARGET = UGameEngine
TEMPLATE = lib

DEFINES += UGAMEENGINE_LIBRARY

SOURCES += ugameengine.cpp \
    ugeentity.cpp \
    vector3d.cpp

HEADERS += ugameengine.h\
        ugameengine_global.h \
    ugeentity.h \
    vector3d.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
