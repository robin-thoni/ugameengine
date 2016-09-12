#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T15:17:33
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheGame
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    renderwidget.cpp \
    openglrenderdevice.cpp

HEADERS  += mainwindow.h \
    renderwidget.h \
    openglrenderdevice.h

FORMS    += mainwindow.ui

LIBS += -lGLU

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UGameEngine/release/ -lUGameEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UGameEngine/debug/ -lUGameEngine
else:unix: LIBS += -L$$OUT_PWD/../UGameEngine/ -lUGameEngine

INCLUDEPATH += $$PWD/../UGameEngine
DEPENDPATH += $$PWD/../UGameEngine
