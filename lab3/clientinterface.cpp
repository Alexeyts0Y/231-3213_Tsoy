#include "clientinterface.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonArray>

ClientInterface* ClientInterface::instance = nullptr;

ClientInterface::ClientInterface(const QString& newUrl)
    :url{newUrl}
{
    m_client = new QNetworkAccessManager();
}

ClientInterface::~ClientInterface() {
    m_client->deleteLater();
    m_client = nullptr;
}

// void ClientInterface::responseRecieved(QNetworkReply *reply) {
//     qDebug() << "Server reponse: " << reply->readAll();
// }

Bike ClientInterface::getBike(const int id){
    Bike bike;
    QNetworkRequest request(QUrl(url + "/bikes/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->get(request);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        if (!doc.isNull() && doc.isObject()) {
            bike = Bike::toObject(doc.object());
        }
    }

    reply->deleteLater();
    return bike;
}

QList<Bike> ClientInterface::getBikes() {
    QList<Bike> bikes;
    QNetworkRequest request(QUrl(url + "/bikes"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        if (!doc.isNull() && doc.isArray()) {
            QJsonArray array = doc.array();
            for (const QJsonValue& value : array) {
                if (value.isObject()) {
                    Bike bike = Bike::toObject(value.toObject());
                    bikes.append(bike);
                }
            }
        }
    }

    reply->deleteLater();
    return bikes;
}

void ClientInterface::createBike(const Bike &bike) {
    QNetworkRequest request(QUrl(url + "/bikes"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json = Bike::toJson(bike);
    json.remove("id");

    QJsonDocument doc(json);

    qDebug() << doc.toJson();

    QNetworkReply* reply = m_client->post(request, doc.toJson());

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    reply->deleteLater();
}

void ClientInterface::updateBike(const int id, const Bike &bike) {
    QNetworkRequest request(QUrl(url + "/bikes/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument doc(Bike::toJson(bike));
    QNetworkReply* reply = m_client->put(request, doc.toJson());

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    reply->deleteLater();
}

void ClientInterface::deleteBike(const int id) {
    QNetworkRequest request(QUrl(url + "/bikes/" + QString::number(id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = m_client->deleteResource(request);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    reply->deleteLater();
}
