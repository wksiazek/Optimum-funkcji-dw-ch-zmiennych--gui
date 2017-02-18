#-------------------------------------------------
#
# Project created by QtCreator 2016-10-15T10:14:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Optimum_funkcji_dwoch_zmiennych
TEMPLATE = app


SOURCES +=\
    ComputingTime.cpp \
    Configuration.cpp \
    Crossover.cpp \
    CrossoverOnePoint.cpp \
    CrossoverThreePoint.cpp \
    CrossoverTwoPoints.cpp \
    GeneticAlgorithm.cpp \
    Factory.cpp \
    Individual.cpp \
    Mutation.cpp \
    MutationSinglePoint.cpp \
    MutationThreePoints.cpp \
    MutationTwoPoints.cpp \
    RouletteWheelSelection.cpp \
    Selection.cpp \
    SelectionRank.cpp \
    SelectionTheBest.cpp \
    SelectionTournament.cpp \
    stdafx.cpp \
    Main.cpp \
    Mainwindow.cpp \
    Writertofile.cpp \
    Population.cpp

HEADERS  += mainwindow.h \
    ComputingTime.h \
    Configuration.h \
    Crossover.h \
    CrossoverOnePoint.h \
    CrossoverThreePoint.h \
    CrossoverTwoPoints.h \
    GeneticAlgorithm.h \
    Factory.h \
    Mutation.h \
    MutationSinglePoint.h \
    MutationThreePoints.h \
    MutationTwoPoints.h \
    RouletteWheelSelection.h \
    Selection.h \
    SelectionRank.h \
    SelectionTheBest.h \
    SelectionTournament.h \
    stdafx.h \
    Individual.h \
    Population.h \
    Writertofile.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    test.qrc
