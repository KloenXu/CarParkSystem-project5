#ifndef MANAGERPAGE_H
#define MANAGERPAGE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QMessageBox>

extern QSqlDatabase mybase;//安装数据库驱动

namespace Ui {
class ManagerPage;
}

class ManagerPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerPage(QWidget *parent = nullptr);
    ~ManagerPage();
    void displayInfAgain();
private slots:
    void on_backHomeBt_clicked();

    void on_displayInf_clicked();

    void on_changeInf_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_deleteInf_clicked();

    void on_passwdChange_clicked();

private:
    Ui::ManagerPage *ui;
    QWidget *p;//用于存储首页地址
};

#endif // MANAGERPAGE_H
