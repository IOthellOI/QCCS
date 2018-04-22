#-------------------------------------------------
#
# Project created by QtCreator 2018-04-21T13:08:50
#
#-------------------------------------------------

QT       += core gui \
    xml \
    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCCS
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
    src/main.cpp \
    src/systemTimer.cpp \
    src/widget.cpp \
    src/xmlRead.cpp \
    src/iniRead.cpp \
    src/computerTable.cpp

HEADERS += \
    src/systemTimer.h \
    src/widget.h \
    src/xmlRead.h \
    src/iniRead.h \
    src/computerTable.h

RESOURCES += \
    qccs.qrc

DISTFILES +=
