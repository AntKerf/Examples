QT += quick sql widgets network
CONFIG += c++11
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        listmodel.cpp \
        main.cpp \
        DataBaseJob.cpp \
        edsmapiparse.cpp

RESOURCES += qml.qrc

HEADERS += \
    DataBaseJob.h \
    edsmapiparse.h \
    listmodel.h

CONFIG(release, debug|release){
DESTDIR = ./bin
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui
