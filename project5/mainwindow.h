#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonParseError>
#include <QMessageBox>
#include "managerlogin.h"
#include "v4l2cameara.h"
#include "rfid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


extern QSqlDatabase mybase;//安装数据库驱动
extern void closeButton();
extern void openButton();

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void button_init();
    void car_init();
    void cameraTimer_init();
    void carButtonConnect_init();
    void timeTimer_init();
    void sendButton();
private slots:
    void timeFunc();
    void weatherFunc(QNetworkReply *p);
    void chooseCar();

    void on_prevPage_clicked();

    void on_nextPage_clicked();

    void on_manageBt_clicked();

    //void usingCamera();

    void on_flashCar_clicked();

    void on_takePhoto_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timeTimer;
    QTime systemTime;
    QNetworkAccessManager manager;
    QString carStr;

    int stopTime;
    int price;

    //QTimer *cameraTimer;
    V4L2Cameara cam;
    RFID rfid_device;

};
#endif // MAINWINDOW_H
