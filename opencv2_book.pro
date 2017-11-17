#-------------------------------------------------
#
# Project created by QtCreator 2017-11-16T10:30:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencv2_book
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
INCLUDEPATH += E:\Qt_opencv\opencv\release\install\include/opencv \
            E:\Qt_opencv\opencv\release\install\include/opencv2  \
            E:\Qt_opencv\opencv\release\install\include

LIBS += -L E:\Qt_opencv\opencv\release\install\x64\mingw\lib/libopencv_*.a

