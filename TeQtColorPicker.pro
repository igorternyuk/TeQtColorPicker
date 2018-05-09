#-------------------------------------------------
#
# Project created by QtCreator 2018-05-09T09:11:49
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++1z

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeQtColorPicker
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    colorpicker.cpp

HEADERS  += widget.hpp \
    colorpicker.hpp

FORMS    += widget.ui \
    colorpicker.ui
