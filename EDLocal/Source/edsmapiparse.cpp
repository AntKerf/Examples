#include "edsmapiparse.h"
#include <math.h>


EdsmApiParse::EdsmApiParse(QObject *parent): QObject(parent)
{
}

EdsmApiParse::~EdsmApiParse()
{
}

void EdsmApiParse::getResponse(QNetworkReply *reply)
{
    qDebug() << "go";
#ifndef MUTE_RESPONSE
    qDebug() << "Response";
#endif
    // Если ошибки отсутсвуют
    if(!reply->error()){
#ifndef MUTE_RESPONSE
        qDebug() << "Adding...";
#endif
        // То создаём объект JsonArray, считав в него все данные из ответа
        QJsonArray document = QJsonDocument::fromJson(reply->readAll()).array();
        size_t cSys=0;
        size_t cInfo=0;
        size_t cCoords=0;
        size_t cPS=0;
        if(!db.isConnected())db.openDataBase();
        for(auto el:document)
        {
            if(!el.toObject().isEmpty())
            {
                if(splitSystem(el))cSys++;
            }

            if(!el.toObject()["coords"].isNull())
            {
                if(splitCoords(el))cCoords++;
            }

            if(!el.toObject()["information"].isNull())
            {
                if(splitInfo(el))cInfo++;
            }

            if(!el.toObject()["primaryStar"].isNull())
            {
                if(splitPrimStar(el))cPS++;
            }
        }
#ifndef MUTE_RESPONSE
        qDebug() <<"Processed system" << cSys;
        qDebug() <<"Processed coords" << cCoords;
        qDebug() <<"Processed info" << cInfo;
        qDebug() <<"Processed primaryStar" << cPS;
#endif
    }
    else{
        qDebug() << reply->errorString();
    }
    reply->deleteLater();
    is_now_request = false;
#ifndef MUTE_RESPONSE
    qDebug()<<"Response out";
#endif
}

bool EdsmApiParse::splitSystem(QJsonValueRef el)
{
    QVariantList data;
    auto obj = el.toObject();
    data.push_back(obj["id"].toVariant());
    data.push_back(obj["name"].toVariant());
    data.push_back(obj["bodyCount"].toVariant());
    if(!el.toObject()["coords"].isNull())
    {
        double dist = sqrt(pow(obj["coords"].toObject()["x"].toDouble(),2)+pow(obj["coords"].toObject()["y"].toDouble(),2)+pow(obj["coords"].toObject()["z"].toDouble(),2));
        data.push_back(dist);
    }
    else    data.push_back(obj["distance"].toVariant());
#ifdef SHOWSYSTEMS || SHOWALL
    qDebug() <<"System";
    qDebug() <<data[0].toInt()<<data[1].toString()<<data[2].toInt() <<data[3].toFloat();
#endif
    return db.insertIntoSystems(std::move(data));
}

bool EdsmApiParse::splitCoords(QJsonValueRef el)
{
    QVariantList data;
    auto obj = el.toObject();
    data.push_back(obj["id"].toVariant());
    data.push_back(obj["coords"].toObject()["x"].toVariant());
    data.push_back(obj["coords"].toObject()["y"].toVariant());
    data.push_back(obj["coords"].toObject()["z"].toVariant());
#ifdef SHOWCOORDS || SHOWALL
    qDebug()<<"Coords";
    qDebug() <<data[0].toInt()<<data[1].toFloat()<<data[2].toFloat() <<data[3].toFloat();
#endif
    return db.insertIntoCoords(std::move(data));
}

bool EdsmApiParse::splitInfo(QJsonValueRef el)
{
    QVariantList data;
    data.push_back(el.toObject()["id"].toVariant());
    data.push_back(el.toObject()["information"].toObject()["allegiance"].toVariant());
    data.push_back(el.toObject()["information"].toObject()["government"].toVariant());
    data.push_back(el.toObject()["information"].toObject()["faction"].toVariant());
    data.push_back(el.toObject()["information"].toObject()["factionState"].toVariant());
    data.push_back(el.toObject()["information"].toObject()["population"].toVariant());
    data.push_back(el.toObject()["information"].toObject()["security"].toVariant());
    data.push_back(el.toObject()["information"].toObject()["economy"].toVariant());
#ifdef SHOWINFO || SHOWALL
    qDebug()<<"Info";
    qDebug() <<data[0].toInt()<<data[1].toString()<<data[2].toString() <<data[3].toString()<<data[4].toString()<<data[5].toInt()<<data[6].toString()<<data[7].toString();
#endif
    return db.insertIntoInformation(std::move(data));
}

bool EdsmApiParse::splitPrimStar(QJsonValueRef el)
{
    QVariantList data;
    data.push_back(el.toObject()["id"].toVariant());
    data.push_back(el.toObject()["primaryStar"].toObject()["type"].toVariant());
    data.push_back(el.toObject()["primaryStar"].toObject()["name"].toVariant());
    data.push_back(el.toObject()["primaryStar"].toObject()["isScoopable"].toVariant());
#ifdef SHOWPRIMARYSTAR || SHOWALL
    qDebug()<<"PrimaryStar";
    qDebug() <<data[0].toInt()<<data[1].toString()<<data[2].toString() <<data[3].toString();
#endif
    return db.insertIntoPrimaryStar(std::move(data));
}

void EdsmApiParse::handleJsonAcync(std::queue<QString> &Que, size_t ThreadCount, bool &status)
{
    for(size_t i =0; i<ThreadCount;i++)
    {
        threadPool.push_back(std::thread([&](){handleJson(Que,status);}));
        threadPool.back().detach();
    }
}

void EdsmApiParse::handleJson(std::queue<QString> &Que, bool &status)
{
    QJsonArray obj;
    while(true)
    {
        {
            //ждем пока другие потоки возьмут строку
            std::lock_guard<std::mutex> guard (mute);
            //пытаемся взять строку на обработку
            // goto так как очередь может быть пуста и while не подходит
tryPutJson:
            if(!Que.empty())
            {
                obj = QJsonDocument::fromJson(Que.front().toUtf8()).array();
                Que.pop();
            }
            //если статус изменился(значит все данные обработанны) то поток уничтожается
            else if(!status){return;}
            //иначе пытаемся взять строку из очереди на обработку
            else goto tryPutJson;
        }
        //если поток взял строку на обработку
        if(!obj.isEmpty())
        {
            for(auto el:obj)
            {
                //обработка только координат и названий систем,
                //так как EDSM не предоставляет в дампах другую информацию
                if(!el.toObject()["coords"].isNull())
                {
                    splitSystem(el);
                    splitCoords(el);
                }
            }
        }
    }
}

void EdsmApiParse::GetCube(const QString SystemName)
{
    networkManager = new QNetworkAccessManager(this);
    // Подключаем networkManager к обработчику ответа
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getResponse(QNetworkReply*)));
    is_now_request = true;
    // Получаем данные, а именно JSON файл с сайта по определённому url
    networkManager->get(QNetworkRequest(QUrl("https://www.edsm.net/api-v1/cube-systems?systemName="+SystemName+"&showInformation=1&showCoordinates=1&showId=1&showPrimaryStar=1")));
}

void EdsmApiParse::GetCube(const QString SystemName, const QString size)
{

    networkManager = new QNetworkAccessManager();
    // Подключаем networkManager к обработчику ответа
    connect(networkManager,SIGNAL(finished(QNetworkReply*)),  this, SLOT(getResponse(QNetworkReply*)));
    is_now_request = true;
    // Получаем данные, а именно JSON файл с сайта по определённому url
    networkManager->get(QNetworkRequest(QUrl("https://www.edsm.net/api-v1/cube-systems?systemName="+SystemName+"&showInformation=1&showCoordinates=1&size="+size+"&showId=1&showPrimaryStar=1")));
    qDebug() << "Connect...";
}

void EdsmApiParse::FromFileJson(const QString Path)
{
    QFile file;
    std::queue<QString> que;
    file.setFileName(Path);
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString str="";
        bool status = 1;
        //запуск 2 потоков на обработку очереди с json строками
        handleJsonAcync(que,2,status);
        while(!file.atEnd())
        {
            str += file.readLine();
            str[0]='[';
            if(str.length()>2)str[str.length()-2]=']';
            //добавляем строку в очередь на обработку если в очереди меньше 100 строк
            while(que.size()>100);
            que.push(std::move(str));
//tryAddToQueue:
//            //пытаемся поместить строку в очередь пока там не освободиться место
//            if(que.size()<100)que.push(std::move(str));
//            else goto tryAddToQueue;
        }
        file.close();
        //ожидание окончания обработки всей очереди
        while(!que.empty());
        status = 0;
        threadPool.clear();
    }

}

bool EdsmApiParse::is_requested()
{
    return is_now_request;
}
