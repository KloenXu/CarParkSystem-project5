/********************************************************************************
** Form generated from reading UI file 'keyboardui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDUI_H
#define UI_KEYBOARDUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <keyboardpress.h>

QT_BEGIN_NAMESPACE

class Ui_keyboardUI
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    keyboardPress *pushButton_12;
    keyboardPress *pushButton_14;
    keyboardPress *pushButton_11;
    QHBoxLayout *horizontalLayout_2;
    keyboardPress *pushButton_15;
    keyboardPress *pushButton_13;
    keyboardPress *pushButton_25;
    QHBoxLayout *horizontalLayout_3;
    keyboardPress *pushButton_23;
    keyboardPress *pushButton_26;
    keyboardPress *pushButton_22;
    QVBoxLayout *verticalLayout;
    keyboardPress *pushButton_24;
    keyboardPress *pushButton_18;

    void setupUi(QWidget *keyboardUI)
    {
        if (keyboardUI->objectName().isEmpty())
            keyboardUI->setObjectName(QStringLiteral("keyboardUI"));
        keyboardUI->resize(300, 200);
        keyboardUI->setMinimumSize(QSize(300, 200));
        keyboardUI->setMaximumSize(QSize(300, 200));
        widget = new QWidget(keyboardUI);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 10, 269, 172));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_12 = new keyboardPress(widget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(50, 50));
        pushButton_12->setMaximumSize(QSize(50, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        pushButton_12->setFont(font);
        pushButton_12->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_12);

        pushButton_14 = new keyboardPress(widget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(50, 50));
        pushButton_14->setMaximumSize(QSize(50, 50));
        pushButton_14->setFont(font);
        pushButton_14->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_14);

        pushButton_11 = new keyboardPress(widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(50, 50));
        pushButton_11->setMaximumSize(QSize(50, 50));
        pushButton_11->setFont(font);
        pushButton_11->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(pushButton_11);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_15 = new keyboardPress(widget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(50, 50));
        pushButton_15->setMaximumSize(QSize(50, 50));
        pushButton_15->setFont(font);
        pushButton_15->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(pushButton_15);

        pushButton_13 = new keyboardPress(widget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(50, 50));
        pushButton_13->setMaximumSize(QSize(50, 50));
        pushButton_13->setFont(font);
        pushButton_13->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(pushButton_13);

        pushButton_25 = new keyboardPress(widget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(50, 50));
        pushButton_25->setMaximumSize(QSize(50, 50));
        pushButton_25->setFont(font);
        pushButton_25->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(pushButton_25);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_23 = new keyboardPress(widget);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(50, 50));
        pushButton_23->setMaximumSize(QSize(50, 50));
        pushButton_23->setFont(font);
        pushButton_23->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(pushButton_23);

        pushButton_26 = new keyboardPress(widget);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setMinimumSize(QSize(50, 50));
        pushButton_26->setMaximumSize(QSize(50, 50));
        pushButton_26->setFont(font);
        pushButton_26->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(pushButton_26);

        pushButton_22 = new keyboardPress(widget);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setMinimumSize(QSize(50, 50));
        pushButton_22->setMaximumSize(QSize(50, 50));
        pushButton_22->setFont(font);
        pushButton_22->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(pushButton_22);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_24 = new keyboardPress(widget);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(50, 50));
        pushButton_24->setMaximumSize(QSize(50, 50));
        pushButton_24->setFont(font);
        pushButton_24->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_24);

        pushButton_18 = new keyboardPress(widget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(pushButton_18);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(keyboardUI);

        QMetaObject::connectSlotsByName(keyboardUI);
    } // setupUi

    void retranslateUi(QWidget *keyboardUI)
    {
        keyboardUI->setWindowTitle(QApplication::translate("keyboardUI", "Form", 0));
        pushButton_12->setText(QApplication::translate("keyboardUI", "1", 0));
        pushButton_14->setText(QApplication::translate("keyboardUI", "2", 0));
        pushButton_11->setText(QApplication::translate("keyboardUI", "3", 0));
        pushButton_15->setText(QApplication::translate("keyboardUI", "4", 0));
        pushButton_13->setText(QApplication::translate("keyboardUI", "5", 0));
        pushButton_25->setText(QApplication::translate("keyboardUI", "6", 0));
        pushButton_23->setText(QApplication::translate("keyboardUI", "7", 0));
        pushButton_26->setText(QApplication::translate("keyboardUI", "8", 0));
        pushButton_22->setText(QApplication::translate("keyboardUI", "9", 0));
        pushButton_24->setText(QApplication::translate("keyboardUI", "0", 0));
        pushButton_18->setText(QApplication::translate("keyboardUI", "<--", 0));
    } // retranslateUi

};

namespace Ui {
    class keyboardUI: public Ui_keyboardUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDUI_H
