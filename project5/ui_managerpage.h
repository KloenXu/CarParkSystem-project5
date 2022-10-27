/********************************************************************************
** Form generated from reading UI file 'managerpage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERPAGE_H
#define UI_MANAGERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "keyboardui.h"

QT_BEGIN_NAMESPACE

class Ui_ManagerPage
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *displayInf;
    QPushButton *changeInf;
    QPushButton *backHomeBt;
    keyboardUI *widget;
    QLineEdit *changeInfText;
    QPushButton *deleteInf;
    QPushButton *passwdChange;

    void setupUi(QMainWindow *ManagerPage)
    {
        if (ManagerPage->objectName().isEmpty())
            ManagerPage->setObjectName(QStringLiteral("ManagerPage"));
        ManagerPage->resize(800, 480);
        centralwidget = new QWidget(ManagerPage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(360, 170, 431, 301));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        tableWidget->setFont(font);
        displayInf = new QPushButton(centralwidget);
        displayInf->setObjectName(QStringLiteral("displayInf"));
        displayInf->setGeometry(QRect(10, 10, 211, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(26);
        displayInf->setFont(font1);
        changeInf = new QPushButton(centralwidget);
        changeInf->setObjectName(QStringLiteral("changeInf"));
        changeInf->setGeometry(QRect(290, 10, 211, 71));
        changeInf->setFont(font1);
        backHomeBt = new QPushButton(centralwidget);
        backHomeBt->setObjectName(QStringLiteral("backHomeBt"));
        backHomeBt->setGeometry(QRect(4, 370, 201, 101));
        backHomeBt->setFont(font1);
        widget = new keyboardUI(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 169, 341, 181));
        changeInfText = new QLineEdit(centralwidget);
        changeInfText->setObjectName(QStringLiteral("changeInfText"));
        changeInfText->setGeometry(QRect(10, 100, 261, 51));
        changeInfText->setFont(font);
        deleteInf = new QPushButton(centralwidget);
        deleteInf->setObjectName(QStringLiteral("deleteInf"));
        deleteInf->setGeometry(QRect(290, 90, 211, 71));
        deleteInf->setFont(font1);
        passwdChange = new QPushButton(centralwidget);
        passwdChange->setObjectName(QStringLiteral("passwdChange"));
        passwdChange->setGeometry(QRect(260, 370, 93, 101));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(24);
        passwdChange->setFont(font2);
        ManagerPage->setCentralWidget(centralwidget);

        retranslateUi(ManagerPage);

        QMetaObject::connectSlotsByName(ManagerPage);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerPage)
    {
        ManagerPage->setWindowTitle(QApplication::translate("ManagerPage", "MainWindow", 0));
        displayInf->setText(QApplication::translate("ManagerPage", "\345\210\267\346\226\260\344\277\241\346\201\257", 0));
        changeInf->setText(QApplication::translate("ManagerPage", "\344\277\235\345\255\230\344\277\241\346\201\257", 0));
        backHomeBt->setText(QApplication::translate("ManagerPage", "\345\233\236\345\210\260\351\246\226\351\241\265", 0));
        changeInfText->setText(QString());
        changeInfText->setPlaceholderText(QString());
        deleteInf->setText(QApplication::translate("ManagerPage", "\345\210\240\351\231\244\344\277\241\346\201\257", 0));
        passwdChange->setText(QApplication::translate("ManagerPage", "\344\277\256\346\224\271\n"
"\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class ManagerPage: public Ui_ManagerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERPAGE_H
