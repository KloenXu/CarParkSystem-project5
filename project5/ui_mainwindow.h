/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *weatherLabel;
    QLabel *timeLabel;
    QLabel *weather;
    QLabel *time;
    QPushButton *manageBt;
    QLabel *cameraDisplay;
    QPushButton *prevPage;
    QPushButton *nextPage;
    QPushButton *choose1;
    QPushButton *choose2;
    QPushButton *choose3;
    QPushButton *choose4;
    QPushButton *choose5;
    QPushButton *choose1_2;
    QPushButton *choose3_2;
    QPushButton *choose4_2;
    QPushButton *choose2_2;
    QPushButton *choose5_2;
    QLabel *carNumLabel;
    QLabel *stopTimeLabel;
    QLabel *priceLabel;
    QLabel *carNum;
    QLabel *stopTime;
    QLabel *price;
    QPushButton *flashCar;
    QPushButton *takePhoto;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        weatherLabel = new QLabel(centralwidget);
        weatherLabel->setObjectName(QStringLiteral("weatherLabel"));
        weatherLabel->setGeometry(QRect(20, 10, 71, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        weatherLabel->setFont(font);
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        timeLabel->setGeometry(QRect(20, 50, 71, 31));
        timeLabel->setFont(font);
        weather = new QLabel(centralwidget);
        weather->setObjectName(QStringLiteral("weather"));
        weather->setGeometry(QRect(100, 10, 371, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(10);
        weather->setFont(font1);
        time = new QLabel(centralwidget);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(100, 50, 211, 31));
        time->setFont(font);
        manageBt = new QPushButton(centralwidget);
        manageBt->setObjectName(QStringLiteral("manageBt"));
        manageBt->setGeometry(QRect(20, 90, 75, 140));
        manageBt->setMinimumSize(QSize(75, 140));
        manageBt->setMaximumSize(QSize(75, 140));
        manageBt->setFont(font);
        cameraDisplay = new QLabel(centralwidget);
        cameraDisplay->setObjectName(QStringLiteral("cameraDisplay"));
        cameraDisplay->setGeometry(QRect(640, 0, 160, 120));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(28);
        cameraDisplay->setFont(font2);
        prevPage = new QPushButton(centralwidget);
        prevPage->setObjectName(QStringLiteral("prevPage"));
        prevPage->setGeometry(QRect(20, 240, 75, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(14);
        prevPage->setFont(font3);
        nextPage = new QPushButton(centralwidget);
        nextPage->setObjectName(QStringLiteral("nextPage"));
        nextPage->setGeometry(QRect(700, 240, 75, 51));
        nextPage->setFont(font3);
        choose1 = new QPushButton(centralwidget);
        choose1->setObjectName(QStringLiteral("choose1"));
        choose1->setEnabled(true);
        choose1->setGeometry(QRect(120, 240, 75, 201));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(26);
        choose1->setFont(font4);
        choose2 = new QPushButton(centralwidget);
        choose2->setObjectName(QStringLiteral("choose2"));
        choose2->setGeometry(QRect(240, 240, 75, 201));
        choose2->setFont(font4);
        choose3 = new QPushButton(centralwidget);
        choose3->setObjectName(QStringLiteral("choose3"));
        choose3->setGeometry(QRect(360, 240, 75, 201));
        choose3->setFont(font4);
        choose4 = new QPushButton(centralwidget);
        choose4->setObjectName(QStringLiteral("choose4"));
        choose4->setGeometry(QRect(480, 240, 75, 201));
        choose4->setFont(font4);
        choose5 = new QPushButton(centralwidget);
        choose5->setObjectName(QStringLiteral("choose5"));
        choose5->setGeometry(QRect(600, 240, 75, 201));
        choose5->setFont(font4);
        choose1_2 = new QPushButton(centralwidget);
        choose1_2->setObjectName(QStringLiteral("choose1_2"));
        choose1_2->setGeometry(QRect(120, 240, 75, 201));
        choose1_2->setFont(font4);
        choose3_2 = new QPushButton(centralwidget);
        choose3_2->setObjectName(QStringLiteral("choose3_2"));
        choose3_2->setGeometry(QRect(360, 240, 75, 201));
        choose3_2->setFont(font4);
        choose4_2 = new QPushButton(centralwidget);
        choose4_2->setObjectName(QStringLiteral("choose4_2"));
        choose4_2->setGeometry(QRect(480, 240, 75, 201));
        choose4_2->setFont(font4);
        choose2_2 = new QPushButton(centralwidget);
        choose2_2->setObjectName(QStringLiteral("choose2_2"));
        choose2_2->setGeometry(QRect(240, 240, 75, 201));
        choose2_2->setFont(font4);
        choose5_2 = new QPushButton(centralwidget);
        choose5_2->setObjectName(QStringLiteral("choose5_2"));
        choose5_2->setGeometry(QRect(600, 240, 75, 201));
        choose5_2->setFont(font4);
        carNumLabel = new QLabel(centralwidget);
        carNumLabel->setObjectName(QStringLiteral("carNumLabel"));
        carNumLabel->setGeometry(QRect(180, 90, 151, 31));
        carNumLabel->setFont(font);
        stopTimeLabel = new QLabel(centralwidget);
        stopTimeLabel->setObjectName(QStringLiteral("stopTimeLabel"));
        stopTimeLabel->setGeometry(QRect(180, 140, 151, 31));
        stopTimeLabel->setFont(font);
        priceLabel = new QLabel(centralwidget);
        priceLabel->setObjectName(QStringLiteral("priceLabel"));
        priceLabel->setGeometry(QRect(180, 190, 151, 31));
        priceLabel->setFont(font);
        carNum = new QLabel(centralwidget);
        carNum->setObjectName(QStringLiteral("carNum"));
        carNum->setGeometry(QRect(350, 90, 141, 31));
        carNum->setFont(font);
        carNum->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        stopTime = new QLabel(centralwidget);
        stopTime->setObjectName(QStringLiteral("stopTime"));
        stopTime->setGeometry(QRect(350, 140, 141, 31));
        stopTime->setFont(font);
        stopTime->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        price = new QLabel(centralwidget);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(350, 190, 141, 31));
        price->setFont(font);
        price->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        flashCar = new QPushButton(centralwidget);
        flashCar->setObjectName(QStringLiteral("flashCar"));
        flashCar->setGeometry(QRect(470, 170, 201, 61));
        flashCar->setFont(font3);
        takePhoto = new QPushButton(centralwidget);
        takePhoto->setObjectName(QStringLiteral("takePhoto"));
        takePhoto->setGeometry(QRect(490, 7, 121, 41));
        takePhoto->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        weatherLabel->setText(QApplication::translate("MainWindow", "\345\244\251\346\260\224\357\274\232", 0));
        timeLabel->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0));
        weather->setText(QString());
        time->setText(QString());
        manageBt->setText(QApplication::translate("MainWindow", "\347\256\241\n"
"\347\220\206\n"
"\345\221\230", 0));
        cameraDisplay->setText(QApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264", 0));
        prevPage->setText(QApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", 0));
        nextPage->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", 0));
        choose1->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"1", 0));
        choose2->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"2", 0));
        choose3->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"3", 0));
        choose4->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"4", 0));
        choose5->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"5", 0));
        choose1_2->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"6", 0));
        choose3_2->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"8", 0));
        choose4_2->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"9", 0));
        choose2_2->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"7", 0));
        choose5_2->setText(QApplication::translate("MainWindow", "\350\275\246\n"
"\344\275\215\n"
"10", 0));
        carNumLabel->setText(QApplication::translate("MainWindow", "\345\211\251\344\275\231\350\275\246\344\275\215\357\274\232", 0));
        stopTimeLabel->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\346\227\266\351\227\264\357\274\232", 0));
        priceLabel->setText(QApplication::translate("MainWindow", "\345\201\234\350\275\246\350\264\271\347\224\250\357\274\232", 0));
        carNum->setText(QString());
        stopTime->setText(QString());
        price->setText(QString());
        flashCar->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\350\275\246\344\275\215\351\200\200\345\207\272\350\275\246\345\272\223", 0));
        takePhoto->setText(QApplication::translate("MainWindow", "\346\213\215\347\205\247", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
