#-------------------------------------------------
#
# Project created by QtCreator 2018-02-13T17:52:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJECT
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
    CommandWords.cpp \
    Parser.cpp \
    Character.cpp \
    Command.cpp \
    item.cpp \
    Room.cpp \
    areamap.cpp \
    finaldoor.cpp

HEADERS += \
        mainwindow.h \
    Character.h \
    Command.h \
    CommandWords.h \
    item.h \
    Room.h \
    Parser.h \
    areamap.h \
    finaldoor.h

FORMS += \
        mainwindow.ui \
    areamap.ui \
    finaldoor.ui

RESOURCES += \
    mapimg1.qrc

