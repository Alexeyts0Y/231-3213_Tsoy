#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H

#include <QObject>
#include <QList>
#include <QString>
#include <QNetworkAccessManager>

#include "bike.h"

class ClientInterface : public QObject
{
    Q_OBJECT
public:
    static ClientInterface* getInstance(const QString& url = "http://localhost:8080/api"){
        if (instance == nullptr) {
            instance = new ClientInterface(url);
        }
        return instance;
    }

    static void removeInstance() {
        if (instance) {
            instance->deleteLater();
            instance = nullptr;
        }
    }

    Bike getBike(const int id);
    QList<Bike> getBikes();
    void createBike(const Bike &bike);
    void updateBike(const int id, const Bike &bike);
    void deleteBike(const int id);

private:
    QString url;
    ClientInterface(const QString& url);
    ~ClientInterface();
    static ClientInterface* instance;
    QNetworkAccessManager* m_client = nullptr;

private slots:
    // void responseRecieved(QNetworkReply *reply);
signals:
};

#endif // CLIENTINTERFACE_H
