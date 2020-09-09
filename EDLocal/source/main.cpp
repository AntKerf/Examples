#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qdebug.h>
#include <QTabletEvent>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlerror.h>
#include <QtSql/qsqlquery.h>
#include <qsqltablemodel.h>
#include <QTableView>
#include <edsmapiparse.h>
#include <listmodel.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // Подключаемся к базе данных
    DataBaseJob database;
    database.openDataBase();
    // Объявляем и инициализируем модель данных
    ListModel *model = new ListModel();

    // Обеспечиваем доступ к модели и классу для работы с базой данных из QML
    engine.rootContext()->setContextProperty("myModel", model);
    engine.rootContext()->setContextProperty("database", &database);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
