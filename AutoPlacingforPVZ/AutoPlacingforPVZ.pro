QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customplantplace.cpp \
    customzombieplace.cpp \
    gameinfo.cpp \
    help.cpp \
    main.cpp \
    mainwindow.cpp \
    plant_formation.cpp \
    randplantplace.cpp \
    randzombieplace.cpp \
    versioninfo.cpp \
    zombies.cpp

HEADERS += \
    customplantplace.h \
    customzombieplace.h \
    gameinfo.h \
    headfile.h \
    help.h \
    mainwindow.h \
    plant_formation.h \
    process_op.h \
    randplantplace.h \
    randzombieplace.h \
    versioninfo.h \
    zombies.h

FORMS += \
    customplantplace.ui \
    customzombieplace.ui \
    help.ui \
    mainwindow.ui \
    randplantplace.ui \
    randzombieplace.ui \
    versioninfo.ui
TARGET = PvzAutoPlacing


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
