#-------------------------------------------------
#
# Project created by QtCreator 2015-11-19T09:55:13
#
#-------------------------------------------------

QT       += core gui
CONFIG += static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClassCombiner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classcombineruserinterface.cpp

HEADERS  += mainwindow.h \
    classcombineruserinterface.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    images.qrc
