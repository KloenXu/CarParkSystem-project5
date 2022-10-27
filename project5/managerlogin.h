#ifndef MANAGERLOGIN_H
#define MANAGERLOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "managerpage.h"

namespace Ui {
class ManagerLogin;
}

class ManagerLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerLogin(QWidget *parent = nullptr);
    ~ManagerLogin();

private slots:
    void on_backBt_clicked();

    void on_enterBt_clicked();

private:
    Ui::ManagerLogin *ui;
    QWidget *p;//用于存储首页地址

    QString passwordStr;
};

extern QSqlDatabase mybase;//安装数据库驱动

#endif // MANAGERLOGIN_H
