#include "mainwindow.h"
#include "clientinterface.h"
#include "./ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QScrollBar>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clientInterface(ClientInterface::getInstance())
{
    ui->setupUi(this);
    qDebug() << "MainWindow constructor";
    qDebug() << "ClientInterface initialized";
}

MainWindow::~MainWindow()
{
    delete ui;
    ClientInterface::removeInstance();
}

void MainWindow::displayResponse(const QString &response) {
    ui->outputTextEdit->setPlainText(response);
    ui->outputTextEdit->moveCursor(QTextCursor::Start);
    ui->outputTextEdit->ensureCursorVisible();
}

void MainWindow::clearForm() {
    ui->name->clear();
    ui->imageUrl->clear();
    ui->brand->clear();
    ui->color->clear();
    ui->price->clear();
    ui->weight->clear();
    ui->description->clear();
}

void MainWindow::on_getAllButton_clicked()
{
    QList<Bike> bikes = clientInterface->getBikes();

    QJsonArray bikesArray;
    for (const Bike &bike : bikes) {
        bikesArray.append(Bike::toJson(bike));
    }

    QJsonDocument doc(bikesArray);
    displayResponse(doc.toJson());
}


void MainWindow::on_getByIdButton_clicked()
{
    int id = ui->getByIdSpinBox->value();

    Bike bike = clientInterface->getBike(id);
    QJsonDocument doc(Bike::toJson(bike));
    displayResponse(doc.toJson());

    ui->name->setText(bike.getName());
    ui->imageUrl->setText(bike.getImageUrl());
    ui->brand->setText(bike.getBrand());
    ui->color->setText(bike.getColor());
    ui->price->setText(QString::number(bike.getPrice()));
    ui->weight->setText(QString::number(bike.getWeight()));
    ui->description->setText(bike.getDescription());

}


void MainWindow::on_createButton_clicked()
{
    Bike bike;
    bike.setName(ui->name->text());
    bike.setImageUrl(ui->imageUrl->text());
    bike.setBrand(ui->brand->text());
    bike.setColor(ui->color->text());
    bike.setPrice(ui->price->text().toDouble());
    bike.setWeight(ui->weight->text().toDouble());
    bike.setDescription(ui->description->toPlainText());

    clientInterface->createBike(bike);
    displayResponse("Bike created");
    clearForm();
}


void MainWindow::on_updateByIdButton_clicked()
{
    int id = ui->updateByIdSpinBox->value();

    Bike bike;
    bike.setName(ui->name->text());
    bike.setImageUrl(ui->imageUrl->text());
    bike.setBrand(ui->brand->text());
    bike.setColor(ui->color->text());
    bike.setPrice(ui->price->text().toDouble());
    bike.setWeight(ui->weight->text().toDouble());
    bike.setDescription(ui->description->toPlainText());

    clientInterface->updateBike(id, bike);
    displayResponse(QString("Bike updated"));
}


void MainWindow::on_deleteByIdButton_clicked()
{
    int id = ui->deleteByIdSpinBox->value();

    clientInterface->deleteBike(id);
    displayResponse(QString("Bike deleted"));
    clearForm();
}


void MainWindow::on_updateByIdSpinBox_valueChanged(int arg1)
{
    ui->updateByIdSpinBox->setValue(arg1);
}


void MainWindow::on_getByIdSpinBox_valueChanged(int arg1)
{
    ui->getByIdSpinBox->setValue(arg1);
}


void MainWindow::on_deleteByIdSpinBox_valueChanged(int arg1)
{
    ui->deleteByIdSpinBox->setValue(arg1);
}

