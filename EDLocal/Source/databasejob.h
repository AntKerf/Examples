#ifndef DATABASEJOB_H
#define DATABASEJOB_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <qsqlresult.h>

class DataBaseJob: public QObject
{
    Q_OBJECT
public:
    explicit DataBaseJob(QObject *parent = 0);
    ~DataBaseJob();
    /* Методы для непосредственной работы с классом
       * Подключение к базе данных и вставка записей в таблицу
       * */

private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;
    bool is_connect;
public slots:
    bool openDataBase();        // Открытие базы данных
    void closeDataBase();       // Закрытие базы данных
    // Добавление записей в таблицы
    bool insertIntoSystems(const QVariantList data);
    bool insertIntoCoords(const QVariantList data);
    bool insertIntoInformation(const QVariantList data);
    bool insertIntoPrimaryStar(const QVariantList data);
    bool isConnected();
};

#endif // DATABASEJOB_H
