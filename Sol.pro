#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T21:51:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sol
TEMPLATE = app


SOURCES += main.cpp\
        solwindow.cpp \
    card.cpp

HEADERS  += solwindow.h \
    card.h

FORMS    += solwindow.ui

RESOURCES += \
    images.qrc