SOURCES += ../sources/main.cpp

HEADERS += ../sources/feedThread.hpp
HEADERS += ../sources/display-modes/raceDisplay.hpp
HEADERS += ../sources/elements/throttleBar.hpp
HEADERS += ../sources/elements/brakeBar.hpp

HEADERS += ../headers/games/games.hpp
HEADERS += ../headers/games/F1-2020/packetManager.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/carSetup.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/carStatus.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/carTelemetry.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/event.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/finalClassification.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/header.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/lapData.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/lobbyInfo.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/motion.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/participants.hpp
HEADERS += ../headers/games/F1-2020/packets-structures/session.hpp


QT += widgets
QT += core gui
#DESTDIR = ../../../../../usr/share/applications
TARGET = f1-wheel-screen

#CONFIG += console
