#-------------------------------------------------
#
# Project created by QtCreator 2020-07-14T21:39:09
#
#-------------------------------------------------

QT       += core gui

QT       += network
QT       += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zhineng
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

CONFIG += c++11

SOURCES += \
    audio.cpp \
    http.cpp \
    main.cpp \
    speech.cpp \
    widget.cpp \
    robot.cpp

HEADERS += \
    audio.h \
    http.h \
    speech.h \
    widget.h \
    robot.h
FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32: LIBS += -L$$PWD/libs/ -lpython36

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libs/python36.lib
#else:win32-g++: PRE_TARGETDEPS += $$PWD/libs/libpython36.a
