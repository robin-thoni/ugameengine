#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T16:32:08
#
#-------------------------------------------------

QT       += gui core

TARGET = UGameEngine
TEMPLATE = lib

CONFIG += c++11

DEFINES += UGAMEENGINE_LIBRARY

SOURCES += engine/ugameengine.cpp \
    engine/abstractrenderdevice.cpp \
    entities/ugeentity.cpp \
    utils/colorvector3d.cpp \
    entities/ugeentitycube.cpp \
    entities/ugeentityaxes.cpp \
    utils/wavefrontobj.cpp \
    entities/ugeentitywavefrontobj.cpp \
    utils/texturevector3d.cpp \
    utils/vector2d.cpp \
    utils/vector3d.cpp \
    utils/matrix3x3.cpp \
    utils/tools.cpp

HEADERS += engine/ugameengine.h\
    engine/abstractrenderdevice.h \
    entities/ugeentity.h \
    utils/vector3d.h \
    utils/colorvector3d.h \
    entities/ugeentitycube.h \
    entities/ugeentityaxes.h \
    utils/wavefrontobj.h \
    entities/ugeentitywavefrontobj.h \
    utils/texturevector3d.h \
    utils/vectorxd.h \
    utils/vectorxd.hxx \
    utils/vector2d.h \
    utils/matrixmxn.h \
    utils/matrixmxn.hxx \
    utils/matrix3x3.h \
    utils/tools.h \
    utils/tools.hxx


# FLEX && BISON

LIBS += -lfl -ly

FLEXSOURCES = utils/lexer-wavefront-obj.l \
    utils/lexer-wavefront-mtl.l
BISONSOURCES = utils/parser-wavefront-obj.y \
    utils/parser-wavefront-mtl.y

OTHER_FILES +=  \
    $$FLEXSOURCES \
    $$BISONSOURCES

flexsource.input = FLEXSOURCES
flexsource.output = ${QMAKE_FILE_BASE}.cpp
flexsource.commands = flex --header-file=${QMAKE_FILE_BASE}.h -o ${QMAKE_FILE_BASE}.cpp ${QMAKE_FILE_IN}
flexsource.variable_out = SOURCES
flexsource.name = Flex Sources ${QMAKE_FILE_IN}
flexsource.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += flexsource

flexheader.input = FLEXSOURCES
flexheader.output = ${QMAKE_FILE_BASE}.h
flexheader.commands = @true
flexheader.variable_out = HEADERS
flexheader.name = Flex Headers ${QMAKE_FILE_IN}
flexheader.CONFIG += target_predeps no_link

QMAKE_EXTRA_COMPILERS += flexheader

bisonsource.input = BISONSOURCES
bisonsource.output = ${QMAKE_FILE_BASE}.cpp
bisonsource.commands = bison -d --defines=${QMAKE_FILE_BASE}.h -o ${QMAKE_FILE_BASE}.cpp ${QMAKE_FILE_IN}
bisonsource.variable_out = SOURCES
bisonsource.name = Bison Sources ${QMAKE_FILE_IN}
bisonsource.CONFIG += target_predeps

QMAKE_EXTRA_COMPILERS += bisonsource

bisonheader.input = BISONSOURCES
bisonheader.output = ${QMAKE_FILE_BASE}.h
bisonheader.commands = @true
bisonheader.variable_out = HEADERS
bisonheader.name = Bison Headers ${QMAKE_FILE_IN}
bisonheader.CONFIG += target_predeps no_link

QMAKE_EXTRA_COMPILERS += bisonheader






unix {
    target.path = /usr/lib
    INSTALLS += target
}
