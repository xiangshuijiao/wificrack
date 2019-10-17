#-------------------------------------------------
#
# Project created by QtCreator 2019-10-15T20:49:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wificrack
TEMPLATE = app

LIBS += -lssl
LIBS += -lcrypto

SOURCES += main.cpp\
        mainwindow.cpp \
    FileSystemWatcher.cpp \
    fastpbkdf2.cpp \
    hmac_sha1.cpp \
    wpa2break.cpp

HEADERS  += mainwindow.h \
    FileSystemWatcher.h \
    fastpbkdf2.h \
    hmac_sha1.h \
    wpa2break.h

FORMS    += mainwindow.ui
