#-------------------------------------------------
#
# Project created by QtCreator 2018-09-18T03:03:14
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CG1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    o_ponto.cpp \
    coordenada.cpp \
    l_pontos.cpp \
    l_faces.cpp \
    o_aresta.cpp \
    o_face.cpp \
    glwidget.cpp \
    cubo.cpp \
    objeto.cpp \
    circulo.cpp \
    camera.cpp \
    luz.cpp \
    cor.cpp

HEADERS += \
        mainwindow.h \
    o_ponto.h \
    coordenada.h \
    l_pontos.h \
    l_faces.h \
    o_aresta.h \
    o_face.h \
    glwidget.h \
    cubo.h \
    objeto.h \
    circulo.h \
    camera.h \
    luz.h \
    cor.h

FORMS += \
        mainwindow.ui

LIBS += -lOpengl32 -lglu32
