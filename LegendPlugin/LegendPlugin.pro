#-------------------------------------------------
#
# Project created by QtCreator 2020-02-25T21:08:06
#
#-------------------------------------------------

QT       +=core gui
QT       +=network
QT       +=xml
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LegendPlugin
TEMPLATE = app

CXXFLAGS += -std=c++0x
SOURCES += main.cpp\
    DesCrypt.cpp \
        mainwindow.cpp \
    content.cpp \
    qbase.cpp \
    qftp.cpp \
    qspy.cpp \
    qplugin.cpp \
    qguide.cpp \
    qaddplugin.cpp \
    easylogging++.cc \
    qeditplugin.cpp \
    qurlinfo.cpp \
    qxml.cpp

HEADERS  += mainwindow.h \
    DesCrypt.h \
    content.h \
    qbase.h \
    qftp.h \
    qspy.h \
    qplugin.h \
    qguide.h \
    qaddplugin.h \
    easylogging++.h \
    qeditplugin.h \
    gloabl.h \
    qurlinfo.h \
    qxml.h

FORMS    += mainwindow.ui \
    qspy.ui \
    qplugin.ui \
    qguide.ui \
    qaddplugin.ui \
    qeditplugin.ui
