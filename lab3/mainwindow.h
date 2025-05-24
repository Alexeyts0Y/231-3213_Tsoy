#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include "clientinterface.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_getByIdSpinBox_valueChanged(int arg1);
    void on_getAllButton_clicked();
    void on_getByIdButton_clicked();
    void on_createButton_clicked();
    void on_updateByIdButton_clicked();
    void on_deleteByIdButton_clicked();
    void on_updateByIdSpinBox_valueChanged(int arg1);
    void on_deleteByIdSpinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    ClientInterface* clientInterface;
    void displayResponse(const QString &response);
    void clearForm();
};
#endif // MAINWINDOW_H
