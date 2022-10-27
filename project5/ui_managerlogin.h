/********************************************************************************
** Form generated from reading UI file 'managerlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERLOGIN_H
#define UI_MANAGERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "keyboardui.h"

QT_BEGIN_NAMESPACE

class Ui_ManagerLogin
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *password;
    keyboardUI *widget;
    QPushButton *backBt;
    QPushButton *enterBt;

    void setupUi(QMainWindow *ManagerLogin)
    {
        if (ManagerLogin->objectName().isEmpty())
            ManagerLogin->setObjectName(QStringLiteral("ManagerLogin"));
        ManagerLogin->resize(800, 480);
        centralwidget = new QWidget(ManagerLogin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 80, 441, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(26);
        label->setFont(font);
        password = new QLineEdit(centralwidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(160, 140, 461, 61));
        password->setFont(font);
        widget = new keyboardUI(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(220, 260, 351, 151));
        backBt = new QPushButton(centralwidget);
        backBt->setObjectName(QStringLiteral("backBt"));
        backBt->setGeometry(QRect(0, 400, 151, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(28);
        backBt->setFont(font1);
        enterBt = new QPushButton(centralwidget);
        enterBt->setObjectName(QStringLiteral("enterBt"));
        enterBt->setGeometry(QRect(690, 260, 75, 151));
        enterBt->setFont(font1);
        enterBt->setFocusPolicy(Qt::NoFocus);
        ManagerLogin->setCentralWidget(centralwidget);

        retranslateUi(ManagerLogin);

        QMetaObject::connectSlotsByName(ManagerLogin);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerLogin)
    {
        ManagerLogin->setWindowTitle(QApplication::translate("ManagerLogin", "MainWindow", 0));
        label->setText(QApplication::translate("ManagerLogin", "\350\257\267\350\276\223\345\205\245\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201\357\274\232", 0));
        password->setText(QString());
        backBt->setText(QApplication::translate("ManagerLogin", "\350\277\224\345\233\236", 0));
        enterBt->setText(QApplication::translate("ManagerLogin", "\347\241\256\n"
"\350\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class ManagerLogin: public Ui_ManagerLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERLOGIN_H
