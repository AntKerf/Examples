#ifndef EDSMAPIPARSE_H
#define EDSMAPIPARSE_H

#include <QObject>
#include <databasejob.h>
#include <QString>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QEventLoop>
#include <thread>
#include <mutex>
#include <queue>

class EdsmApiParse: public QObject
{
    Q_OBJECT
public:
    explicit EdsmApiParse(QObject *parent = 0);
    ~EdsmApiParse();

private:
    QNetworkAccessManager* networkManager;
    DataBaseJob db;
    std::vector<std::thread> threadPool;
    std::mutex mute;
    bool is_now_request = false;

private slots:
    //обработка запроса
    void getResponse(QNetworkReply *reply);
    //парсинг json и вставка в бд
    bool splitSystem(QJsonValueRef);
    bool splitCoords(QJsonValueRef);
    bool splitInfo(QJsonValueRef);
    bool splitPrimStar(QJsonValueRef);
    //обработка файлов
    void handleJsonAcync(std::queue<QString>&, size_t ThreadCount, bool&);
    void handleJson(std::queue<QString>&,bool&);

public slots:
    //парсинг через апи EDSM
    void GetCube(const QString SystemName );
    void GetCube(const QString SystemName, const QString size);
    //парсинг через файл
    void FromFileJson(const QString Path);
    bool is_requested();

};

#endif // EDSMAPIPARSE_H
