#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T16:32:08
#
#-------------------------------------------------

QT       += gui core

TARGET = UGameEngine
TEMPLATE = lib

DEFINES += UGAMEENGINE_LIBRARY

SOURCES += ugameengine.cpp \
    ugeentity.cpp \
    vector3d.cpp \
    abstractrenderdevice.cpp \
    colorvector3d.cpp

HEADERS += ugameengine.h\
    ugeentity.h \
    vector3d.h \
    abstractrenderdevice.h \
    colorvector3d.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
