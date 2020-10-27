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


DESTDIR = D:\Users\Documents\GitHub\Examples\EDLocal

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = D:\Qt\5.15.1\mingw81_32\qml\

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

QT_QPA_PLATFORM_PLUGIN_PATH =%QTDIR%\plugins\platform\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    DataBaseJob.h \
    edsmapiparse.h \
    listmodel.h
