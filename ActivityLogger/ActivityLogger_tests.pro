QT       += core gui
QT += testlib
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# Uncomment to disable deprecated APIs before Qt 6.0.0
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    activity.cpp \
    activitylog.cpp \
    test.cpp \
    external/googletest-main/googletest/src/gtest-all.cc

HEADERS += \
    mainwindow.h \
    activity.h \
    activitylog.h

FORMS += \
    mainwindow.ui

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Ruta a Google Test
INCLUDEPATH += $$PWD/external/googletest-main/googletest/include
INCLUDEPATH += $$PWD/external/googletest-main/googletest
