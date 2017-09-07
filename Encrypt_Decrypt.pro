#-------------------------------------------------
#
# Project created by QtCreator 2017-09-06T10:13:37
#
#-------------------------------------------------

QT       += core gui

RC_ICONS = crypt.ico

VERSION =1.0.0.1

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Encrypt_Decrypt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    crypttools.cpp \
    configkeywindow.cpp

HEADERS  += mainwindow.h \
    crypttools.h \
    configkeywindow.h

FORMS    += mainwindow.ui \
    configkeywindow.ui


