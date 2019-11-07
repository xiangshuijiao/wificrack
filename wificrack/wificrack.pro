#-------------------------------------------------
#
# Project created by QtCreator 2019-10-15T20:49:04
#
#-------------------------------------------------

QT       += core gui
LIBS += -L.   -laircrack-osdep-1.5.2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wificrack
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    FileSystemWatcher.cpp

HEADERS  += mainwindow.h \
    FileSystemWatcher.h

FORMS    += mainwindow.ui
