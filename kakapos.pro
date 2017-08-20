#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T12:32:09
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kakapos
TEMPLATE = app
SUBDIRS += Sources Headers
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cc \
    Sources/mainwindow.cc \
    Sources/splash_recentfile.cc \
    Sources/splashwindow.cc \
    Sources/codeeditor.cc \
    Sources/customshadoweffect.cc \
    Sources/highlighter_C.cc

HEADERS += \
        Headers/mainwindow.h \
    Headers/splashwindow.h \
    Headers/splash_recentfile.h \
    Headers/codeeditor.h \
    Headers/customshadoweffect.h \
    Headers/highlighter_C.h

FORMS += \
        ui/mainwindow.ui \
    ui/splashwindow.ui \
    ui/splash_recentfile.ui \

RESOURCES += \
    images.qrc

win32:{
    RC_ICONS = kakapos.ico
    RC_FILE = kakapos.rc
}

macx:{
    ICON = Mac.icns
}

DISTFILES += \
    kakapos.rc


unix: LIBS += -L$$PWD/./ -lyaml-cpp

INCLUDEPATH += $$PWD/yaml-cpp
DEPENDPATH += $$PWD/yaml-cpp
