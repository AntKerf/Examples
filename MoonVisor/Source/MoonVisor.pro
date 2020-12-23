QT += quick
CONFIG += qt c++11

CONFIG(release, debug|release){
DESTDIR = ./bin
}
CONFIG(debug, debug|release) {
DESTDIR = ./bin_debug
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

SOURCES +=main.cpp \
	basetelescope.cpp
RESOURCES += qml.qrc
HEADERS += basetelescope.h
TARGET = MoonVisor