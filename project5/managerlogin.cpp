#include "managerlogin.h"
#include "ui_managerlogin.h"

ManagerLogin::ManagerLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerLogin)
{
    ui->setupUi(this);

    p=this->parentWidget();

    bool ret;
    QSqlQuery query(mybase);
    ret=query.exec("create table if not exists password(passwd text);");
    if(ret==false)
    {
        qDebug()<<"新建表格失败了,原因是: "<<query.lastError().text();
        return;
    }
    ret=query.exec("select * from password;");
    if(ret==false)
    {
        qDebug()<<"查询数据失败了,原因是: "<<query.lastError().text();
        return;
    }
    while(query.next())
    {
        passwordStr = query.value(0).toString();
    }

}

ManagerLogin::~ManagerLogin()
{
    delete ui;
}

void ManagerLogin::on_backBt_clicked()
{
    p->show();
    delete this;
}

void ManagerLogin::on_enterBt_clicked()
{
    if(ui->password->text() == passwordStr)
    {
        ManagerPage *managerpage = new ManagerPage(p);
        managerpage->show();
        this->hide();
    }
    else
    {
        QMessageBox::critical(this,"警告","密码错误",QMessageBox::Ok,QMessageBox::Ok);
        ui->password->clear();
    }
}
