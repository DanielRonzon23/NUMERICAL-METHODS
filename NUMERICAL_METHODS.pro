#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T22:22:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NUMERICAL_METHODS
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
        numerical_methods.cpp \
        punto_fijo.cpp \
        newtonraphson.cpp \
        eliminacion_gausiana.cpp \
        gaus_seidel.cpp \
        inter_lagrange.cpp \
        regresion_lineal.cpp \
        regresion_multiple.cpp \
        derivacion.cpp \
        integracion.cpp \
        metodo_de_euler.cpp \
        rk.cpp \


HEADERS += \
        numerical_methods.h \
        punto_fijo.h \
        newtonraphson.h \
        eliminacion_gausiana.h \
        gaus_seidel.h \
        inter_lagrange.h \
        regresion_lineal.h \
        regresion_multiple.h \
        derivacion.h \
        integracion.h \
        metodo_de_euler.h \
        rk.h \

FORMS += \
        numerical_methods.ui \
        punto_fijo.ui \
        newtonraphson.ui \
        eliminacion_gausiana.ui \
        gaus_seidel.ui \
        inter_lagrange.ui \
        regresion_lineal.ui \
        regresion_multiple.ui \
        derivacion.ui \
        integracion.ui \
        metodo_de_euler.ui \
        rk.ui \
