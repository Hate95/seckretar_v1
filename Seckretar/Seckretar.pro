#-------------------------------------------------
#
# Project created by QtCreator 2015-07-07T18:17:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Seckretar
TEMPLATE = app


SOURCES += main.cpp\
        controlpanel.cpp \
    participant.cpp \
    distance.cpp \
    competition.cpp \
    mymodel.cpp \
    panelsetingscompetition.cpp \
    panelregistration.cpp

HEADERS  += controlpanel.h \
    participant.h \
    distance.h \
    competition.h \
    components.h \
    mymodel.h \
    panelsetingscompetition.h \
    panelregistration.h

FORMS    += controlpanel.ui \
    panelsetingscompetition.ui \
    panelregistration.ui
