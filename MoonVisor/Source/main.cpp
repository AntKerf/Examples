#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <qdebug.h>
#include "basetelescope.h"
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif



    QGuiApplication app(argc, argv);
    qmlRegisterType<baseTelescope>("Telescope",1,0,"Telescope");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
