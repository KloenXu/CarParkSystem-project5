#include "mainwindow.h"
#include "ui_mainwindow.h"

QSqlDatabase mybase;
QList<QPushButton *> buttonList[10];
int whichButton = -1;
QLabel *stopTimeSend;
QLabel *priceSend;
QLabel *carNumSend;
int busyCar[10];
int car;
int cameraOpenOrStop = 0;
QPushButton *managerSend;
QPushButton *flushCarSend;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stopTimeSend = ui->stopTime;
    priceSend = ui->price;
    carNumSend = ui->carNum;
    managerSend = ui->manageBt;
    flushCarSend = ui->flashCar;

    /*将按钮地址存入全局变量QList中给别的文件使用*/
    sendButton();

    /*数据库初始化*/
    mybase=QSqlDatabase::addDatabase("QSQLITE");
    mybase.setDatabaseName("inf.db");
    bool ret=mybase.open();
    if(ret==false)
    {
        qDebug()<<"打开数据库失败了,原因是: "<<mybase.lastError().text();
        return;
    }

    /*按钮初始化*/
    button_init();

    /*车位初始化*/
    car_init();

    /*摄像头以及对应的定时器初始化*/
    //cameraTimer_init();
    cam.camera_init();

    /*时间定时器初始化并开启*/
    timeTimer_init();

    /*获取天气初始化*/
    connect(&manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(weatherFunc(QNetworkReply *)));
    //获取天气预报的网址
    QString str="http://www.weather.com.cn/data/cityinfo/101010100.html";
    QUrl url(str);
    //创建http请求
    QNetworkRequest quest(url);
    //发送请求
    manager.get(quest);

    /*车位按钮连接*/
    carButtonConnect_init();

    /*读卡器初始化以及其线程*/
    rfid_device.start();

    cam.start();
}

MainWindow::~MainWindow()
{
    cam.camera_uninit();
    rfid_device.terminate();
    cam.terminate();
    delete ui;
}

void MainWindow::button_init()
{
    ui->choose1_2->hide();
    ui->choose2_2->hide();
    ui->choose3_2->hide();
    ui->choose4_2->hide();
    ui->choose5_2->hide();
    ui->choose1->show();
    ui->choose2->show();
    ui->choose3->show();
    ui->choose4->show();
    ui->choose5->show();
    ui->choose1->setEnabled(0);
    ui->choose2->setEnabled(0);
    ui->choose3->setEnabled(0);
    ui->choose4->setEnabled(0);
    ui->choose5->setEnabled(0);
    ui->choose1_2->setEnabled(0);
    ui->choose2_2->setEnabled(0);
    ui->choose3_2->setEnabled(0);
    ui->choose4_2->setEnabled(0);
    ui->choose5_2->setEnabled(0);
}

void MainWindow::car_init()
{
    for(int i = 0;i <= 9;i++)
    {
        busyCar[i] = 0;
    }
    car = 10;
    carStr = QString("%1").arg(car);
    ui->carNum->setText(carStr);

    QSqlQuery mydb(mybase);
    bool ret = mydb.exec("select * from card;");
    if(ret == false)
    {
        qDebug()<<"查询信息失败，原因是: "<<mydb.lastError().text();
        return;
    }
    while(mydb.next())
    {
        int carNumTemp = mydb.value(2).toInt();
        carNumTemp--;
        busyCar[carNumTemp] = 1;
        buttonList->at(carNumTemp)->setStyleSheet("background-color:rgb(255,0,0);");
        car--;
    }

    for(int i = 0;i <= 9;i++)
    {
        if(busyCar[i] == 0)
            buttonList->at(i)->setStyleSheet("");
    }

    carStr = QString("%1").arg(car);
    ui->carNum->setText(carStr);
}

void MainWindow::carButtonConnect_init()
{
    connect(ui->choose1,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose2,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose3,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose4,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose5,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose1_2,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose2_2,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose3_2,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose4_2,SIGNAL(clicked()),this,SLOT(chooseCar()));
    connect(ui->choose5_2,SIGNAL(clicked()),this,SLOT(chooseCar()));
}

void MainWindow::timeTimer_init()
{
    timeTimer = new QTimer(this);
    timeTimer->setInterval(1000);
    connect(timeTimer,SIGNAL(timeout()),this,SLOT(timeFunc()));
    timeTimer->start();
}

void MainWindow::sendButton()
{
    buttonList->push_back(ui->choose1);
    buttonList->push_back(ui->choose2);
    buttonList->push_back(ui->choose3);
    buttonList->push_back(ui->choose4);
    buttonList->push_back(ui->choose5);
    buttonList->push_back(ui->choose1_2);
    buttonList->push_back(ui->choose2_2);
    buttonList->push_back(ui->choose3_2);
    buttonList->push_back(ui->choose4_2);
    buttonList->push_back(ui->choose5_2);
}

void MainWindow::timeFunc()
{
    systemTime = QTime::currentTime();
    QString timeDisplay = systemTime.toString();
    ui->time->setText(timeDisplay);

    //car_init();
}

void MainWindow::weatherFunc(QNetworkReply *p)
{
    QByteArray buf=p->readAll();

    //把网站回复的json数据规格化存储
    QJsonParseError err;
    QJsonDocument mydoc=QJsonDocument::fromJson(buf,&err);

    //严格依照你看到的json数据的格式一步步剥洋葱解析
    //最外面是个对象
    QJsonObject obj1=mydoc.object();
    //obj1就是"weatherinfo":{"city":"北京","cityid":"101010100","temp1":"18℃","temp2":"31℃","weather":"多云转阴","img1":"n1.gif","img2":"d2.gif","ptime":"18:00"}
    //继续，是个键值对
    QJsonValue val1=obj1.value("weatherinfo"); //获取"weatherinfo"对应的值
    //val1就是{"city":"北京","cityid":"101010100","temp1":"18℃","temp2":"31℃","weather":"多云转阴","img1":"n1.gif","img2":"d2.gif","ptime":"18:00"}
    QJsonObject obj2=val1.toObject();
    //继续
    QJsonValue val2=obj2.value("temp1");
    QJsonValue val3 = obj2.value("temp2");
    QJsonValue val4 = obj2.value("weather");
    QString weatherInf = QString("最高气温:%1 最低气温:%2 天气:%3").arg(val3.toString()).arg(val2.toString()).arg(val4.toString());
    ui->weather->setText(weatherInf);
}

void MainWindow::chooseCar()
{
    QObject *p=sender();
    //把p的类型转换成QPushButton
    QPushButton *btp=qobject_cast<QPushButton *>(p);
    if(btp == ui->choose1)
    {
        qDebug()<<"按了车位1";
        if(busyCar[0] == 0)//车位为空
        {
            qDebug()<<"车位1从空变被占用";
            busyCar[0] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 1;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[0] == 1)
        {
            qDebug()<<"车位1正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose2)
    {
        qDebug()<<"按了车位2";
        if(busyCar[1] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[1] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 2;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[1] == 1)
        {
            qDebug()<<"车位2正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose3)
    {
        qDebug()<<"按了车位3";
        if(busyCar[2] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[2] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 3;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[2] == 1)
        {
            qDebug()<<"车位3正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose4)
    {
        qDebug()<<"按了车位4";
        if(busyCar[3] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[3] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 4;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[3] == 1)
        {
            qDebug()<<"车位4正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose5)
    {
        qDebug()<<"按了车位5";
        if(busyCar[4] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[4] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 5;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[4] == 1)
        {
            qDebug()<<"车位5正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose1_2)
    {
        qDebug()<<"按了车位6";
        if(busyCar[5] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[5] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 6;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[5] == 1)
        {
            qDebug()<<"车位6正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose2_2)
    {
        qDebug()<<"按了车位7";
        if(busyCar[6] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[6] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 7;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[6] == 1)
        {
            qDebug()<<"车位7正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose3_2)
    {
        qDebug()<<"按了车位8";
        if(busyCar[7] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[7] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 8;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[7] == 1)
        {
            qDebug()<<"车位8正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose4_2)
    {
        qDebug()<<"按了车位9";
        if(busyCar[8] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[8] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 9;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[8] == 1)
        {
            qDebug()<<"车位9正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
    else if(btp == ui->choose5_2)
    {
        qDebug()<<"按了车位10";
        if(busyCar[9] == 0)//车位为空
        {
            qDebug()<<"车位2从空变被占用";
            busyCar[9] = 1;
            car = car - 1;
            carStr = QString("%1").arg(car);
            ui->carNum->setText(carStr);
            whichButton = 10;
            btp->setStyleSheet("background-color:rgb(255,0,0);");
            closeButton();
        }
        else if(busyCar[9] == 1)
        {
            qDebug()<<"车位10正在被占用";
            QMessageBox::critical(this,"警告","该车位已被占用,请选择另外的车位",QMessageBox::Ok,QMessageBox::Ok);
        }
    }

    //btp->setStyleSheet("");//恢复默认的颜色
}

void MainWindow::on_prevPage_clicked()
{
    ui->choose1_2->hide();
    ui->choose2_2->hide();
    ui->choose3_2->hide();
    ui->choose4_2->hide();
    ui->choose5_2->hide();

    ui->choose1->show();
    ui->choose2->show();
    ui->choose3->show();
    ui->choose4->show();
    ui->choose5->show();
}

void MainWindow::on_nextPage_clicked()
{
    ui->choose1_2->show();
    ui->choose2_2->show();
    ui->choose3_2->show();
    ui->choose4_2->show();
    ui->choose5_2->show();

    ui->choose1->hide();
    ui->choose2->hide();
    ui->choose3->hide();
    ui->choose4->hide();
    ui->choose5->hide();
}

void MainWindow::on_manageBt_clicked()
{
    ManagerLogin *managerlogin = new ManagerLogin(this);
    this->hide();
    managerlogin->show();
}


void MainWindow::on_flashCar_clicked()
{
    car_init();
}

void MainWindow::on_takePhoto_clicked()
{
    cam.take_photo();
}
