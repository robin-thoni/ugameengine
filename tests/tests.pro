#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T17:54:11
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tests
TEMPLATE = app


SOURCES += \
    testvector3d.cpp

HEADERS  +=

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UGameEngine/release/ -lUGameEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UGameEngine/debug/ -lUGameEngine
else:unix: LIBS += -L$$OUT_PWD/../UGameEngine/ -lUGameEngine

INCLUDEPATH += $$PWD/../UGameEngine
DEPENDPATH += $$PWD/../UGameEngine
