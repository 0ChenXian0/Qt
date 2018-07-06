#-------------------------------------------------
#
# Project created by QtCreator 2018-07-03T10:12:55
#
#-------------------------------------------------

QT       += sql

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ClinicManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    patient.cpp \
    doctor.cpp \
    createdb.cpp \
    bill.cpp \
    addpatient.cpp \
    addoctor.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    patient.h \
    doctor.h \
    createdb.h \
    bill.h \
    addpatient.h \
    addoctor.h \
    login.h

FORMS    += mainwindow.ui \
    patient.ui \
    doctor.ui \
    bill.ui \
    addpatient.ui \
    addoctor.ui \
    login.ui
