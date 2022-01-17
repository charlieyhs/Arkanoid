QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Arkanoid.cpp \
    BallItem.cpp \
    GraphicsScene.cpp \
    IObjectItem.cpp \
    PlatformItem.cpp \
    ThreadTimer.cpp \
    Util.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Arkanoid.h \
    BallItem.h \
    GlobalDefines.h \
    GraphicsScene.h \
    IObjectItem.h \
    PlatformItem.h \
    ThreadTimer.h \
    Util.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++14

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
