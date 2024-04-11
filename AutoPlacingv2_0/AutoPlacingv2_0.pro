QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game_info.cpp \
    getvalue.cpp \
    main.cpp \
    mainwindow.cpp \
    multiselectcombobox.cpp \
    plantsoperation.cpp \
    tabwidget.cpp \
    versioninfo.cpp \
    zombiesoperation.cpp

HEADERS += \
    game_info.h \
    getvalue.h \
    headfile.h \
    mainwindow.h \
    multiselectcombobox.h \
    plantsoperation.h \
    process_op.h \
    tabwidget.h \
    versioninfo.h \
    zombiesoperation.h

FORMS += \
    getvalue.ui \
    mainwindow.ui \
    versioninfo.ui

msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

LIBS += -lversion
TARGET = test9
RC_ICONS = pvzcrickettoolbox.ico
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
