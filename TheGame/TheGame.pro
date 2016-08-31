#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T15:17:33
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderwidget.cpp

HEADERS  += mainwindow.h \
    renderwidget.h

FORMS    += mainwindow.ui

LIBS += -lGLU
