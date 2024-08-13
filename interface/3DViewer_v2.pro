QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl
greaterThan(QT_MAJOR_VERSION, 5): QT += openglwidgets
include(qtgifimage/src/gifimage/qtgifimage.pri)

CONFIG += c++17
QMAKE_CXXFLAGS += -Wall -Wextra -Wpedantic -g
#Turned off -Werror flag is to ignore qtgifimage warnings

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES = \
    ../misc/resource.qrc

SOURCES += \
    ../controller/s21_controller.cpp \
    ../model/s21_model.cpp \
    ../model/s21_transformation.cpp \
    main.cpp \
    mainwindow.cpp \
    messagewidget.cpp \
    openglsettings.cpp \
    openglwidget.cpp

HEADERS += \
    ../controller/s21_controller.h \
    ../model/s21_model.h \
    ../model/s21_transformation.h \
    mainwindow.h \
    messagewidget.h \
    openglsettings.h \
    openglwidget.h

FORMS += \
    mainwindow.ui \
    messagewidget.ui \
    openglwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
