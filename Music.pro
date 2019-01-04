#-------------------------------------------------
#
# Project created by QtCreator 2013-07-15T14:08:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Music
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    musicmodel.cpp \
    cd.cpp

HEADERS  += mainwindow.h \
    musicmodel.h \
    cd.h

FORMS    += mainwindow.ui
