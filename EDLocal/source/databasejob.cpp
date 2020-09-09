#include "databasejob.h"

DataBaseJob::DataBaseJob(QObject *parent): QObject(parent)
{

}

DataBaseJob::~DataBaseJob()
{
    this->closeDataBase();
}

bool DataBaseJob::openDataBase()
{
//    db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("localhost");
//    db.setDatabaseName("ed");
//    db.setUserName("root");
//    db.setPassword("root");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("ed");
    db.setDatabaseName("ed.sqlite3");
    if(db.open()){
        is_connect=true;
        return true;
    } else {
        qDebug() << db.lastError();
        is_connect=false;
        return false;
    }
}

void DataBaseJob::closeDataBase()
{
    is_connect=false;
    db.close();
}

bool DataBaseJob::insertIntoSystems(const QVariantList data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT IGNORE INTO systems (id, Name, bodyCount, distance)"
                  "VALUES (:id, :Name, :bodyCount, :distance)");
    query.bindValue(":id", data[0].toInt());
    query.bindValue(":Name", data[1].toString());
    query.bindValue(":bodyCount", data[2].toInt());
    query.bindValue(":distance", data[3].toFloat());

    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into systems";
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBaseJob::insertIntoCoords(const QVariantList data)
{
    QSqlQuery query;
    query.prepare("INSERT IGNORE INTO coords (id, x, y, z)"
                  "VALUES (:id, :x, :y, :z)");
    query.bindValue(":id", data[0].toInt());
    query.bindValue(":x", data[1].toFloat());
    query.bindValue(":y", data[2].toFloat());
    query.bindValue(":z", data[3].toFloat());
    if(!query.exec()){
#ifndef SQL_NO_IGNORE
        qDebug() << "error insert into coords";
        qDebug() << query.lastError().text();
#endif
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBaseJob::insertIntoInformation(const QVariantList data)
{
    QSqlQuery query;
    query.prepare("INSERT IGNORE INTO information (id, allegiance, goverment, "
                  "faction, factionState, population, security, economy)"
                  "VALUES (:id, :allegiance, :goverment,"
                  ":faction, :factionState, :population, :security, :economy)");
    query.bindValue(":id", data[0].toInt());
    query.bindValue(":allegiance", data[1].toString());
    query.bindValue(":goverment", data[2].toString());
    query.bindValue(":faction", data[3].toString());
    query.bindValue(":factionState", data[4].toString());
    query.bindValue(":population", data[5].toInt());
    query.bindValue(":security", data[6].toString());
    query.bindValue(":economy", data[7].toString());
    if(!query.exec()){
        qDebug() << "error insert into information";
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBaseJob::insertIntoPrimaryStar(const QVariantList data)
{
    QSqlQuery query;
    query.prepare("INSERT IGNORE INTO primarystar (id, type, name, isScoopable)"
                  "VALUES (:id, :type, :name, :isScoopable)");
    query.bindValue(":id", data[0].toInt());
    query.bindValue(":type", data[1].toString());
    query.bindValue(":name", data[2].toString());
    query.bindValue(":isScoopable", data[3].toBool());
    if(!query.exec()){
        qDebug() << "error insert into primaryStar";
        qDebug() << query.lastError().text();

        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBaseJob::isConnected()
{
    return is_connect;
}

