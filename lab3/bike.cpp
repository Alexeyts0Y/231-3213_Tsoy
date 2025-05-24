#include "bike.h"

Bike::Bike() {
}

void Bike::setId(int id) {
    this->id = id;
}

void Bike::setPrice(int price) {
    this->price = price;
}

void Bike::setWeight(int weight) {
    this->weight = weight;
}

void Bike::setName(QString name) {
    this->name = name;
}

void Bike::setBrand(QString brand) {
    this->brand = brand;
}

void Bike::setColor(QString color) {
    this->color = color;
}

void Bike::setImageUrl(QString imageUrl) {
    this->imageUrl = imageUrl;
}

void Bike::setDescription(QString description) {
    this->description = description;
}

int Bike::getId() const {
    return this->id;
}

int Bike::getPrice() const {
    return this->price;
}

int Bike::getWeight() const {
    return this->weight;
}

QString Bike::getName() const {
    return this->name;
}

QString Bike::getBrand() const {
    return this->brand;
}

QString Bike::getColor() const {
    return this->color;
}

QString Bike::getImageUrl() const {
    return this->imageUrl;
}

QString Bike::getDescription() const {
    return this->description;
}

QJsonObject Bike::toJson(const Bike& bike) {
    QJsonObject json;

    json.insert("id", bike.getId());
    json.insert("price", bike.getPrice());
    json.insert("weight", bike.getWeight());
    json.insert("name", bike.getName());
    json.insert("brand", bike.getBrand());
    json.insert("color", bike.getColor());
    json.insert("imageUrl", bike.getImageUrl());
    json.insert("description", bike.getDescription());

    return json;
}

Bike Bike::toObject(const QJsonObject& json) {
    Bike bike;

    bike.setId(json["id"].toInt());
    bike.setPrice(json["price"].toInt());
    bike.setWeight(json["weight"].toInt());
    bike.setName(json["name"].toString());
    bike.setBrand(json["brand"].toString());
    bike.setColor(json["color"].toString());
    bike.setImageUrl(json["imageUrl"].toString());
    bike.setDescription(json["description"].toString());

    return bike;
}

QDebug operator<<(QDebug d, const Bike& bike) {
    qDebug() << "ID:" << bike.getId();
    qDebug() << "price:" << bike.getPrice();
    qDebug() << "weight:" << bike.getWeight();
    qDebug() << "name:" << bike.getName();
    qDebug() << "brand:" << bike.getBrand();
    qDebug() << "color:" << bike.getColor();
    qDebug() << "description:" << bike.getDescription();
    qDebug() << "imageUrl: " << bike.getImageUrl();
    return d;
}
