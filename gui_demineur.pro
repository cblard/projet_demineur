#-------------------------------------------------
#
# Project created by QtCreator 2020-06-12T13:24:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui_demineur
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
        main.cpp \
        mainwindow.cpp \
    jeufacile.cpp \
    clickablelabel.cpp \
    jeumoyen.cpp \
    clickablelabel2.cpp \
    dialogmoyen.cpp \
    clickablelabel3.cpp \
    jeudifficile.cpp \
    dialogdifficile.cpp \
    jeuperso.cpp \
    dialogfacile.cpp \
    clickablelabel4.cpp \
    dialogperso.cpp

HEADERS += \
        mainwindow.h \
    jeufacile.h \
    clickablelabel.h \
    jeumoyen.h \
    clickablelabel2.h \
    dialogmoyen.h \
    clickablelabel3.h \
    jeudifficile.h \
    dialogdifficile.h \
    jeuperso.h \
    dialogfacile.h \
    clickablelabel4.h \
    dialogperso.h

FORMS += \
        mainwindow.ui \
    jeufacile.ui \
    jeumoyen.ui \
    dialogmoyen.ui \
    jeudifficile.ui \
    dialogdifficile.ui \
    jeuperso.ui \
    dialogfacile.ui \
    dialogperso.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    cases.qrc

