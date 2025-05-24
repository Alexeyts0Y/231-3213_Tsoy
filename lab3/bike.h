#ifndef BIKE_H
#define BIKE_H

#include <QString>
#include <QJsonObject>

class Bike
{
public:
    Bike();

    void setId(int id);
    void setPrice(int price);
    void setWeight(int weight);
    void setName(QString name);
    void setBrand(QString brand);
    void setColor(QString color);
    void setImageUrl(QString imageUrl);
    void setDescription(QString description);

    int getId() const;
    int getPrice() const;
    int getWeight() const;
    QString getName() const;
    QString getBrand() const;
    QString getColor() const;
    QString getImageUrl() const;
    QString getDescription() const;

    static QJsonObject toJson(const Bike& bike);
    static Bike toObject(const QJsonObject& json);

private:
    int id;
    int price;
    int weight;
    QString name;
    QString brand;
    QString color;
    QString imageUrl;
    QString description;
};

QDebug operator<<(QDebug d, const Bike& bike);

#endif // BIKE_H
