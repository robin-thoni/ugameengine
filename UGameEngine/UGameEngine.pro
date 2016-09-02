#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T16:32:08
#
#-------------------------------------------------

QT       += gui core

TARGET = UGameEngine
TEMPLATE = lib

DEFINES += UGAMEENGINE_LIBRARY

SOURCES += engine/ugameengine.cpp \
    engine/abstractrenderdevice.cpp \
    entities/ugeentity.cpp \
    utils/vector3d.cpp \
    utils/colorvector3d.cpp \
    entities/ugeentitycube.cpp

HEADERS += engine/ugameengine.h\
    engine/abstractrenderdevice.h \
    entities/ugeentity.h \
    utils/vector3d.h \
    utils/colorvector3d.h \
    entities/ugeentitycube.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
