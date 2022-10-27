#include "managerpage.h"
#include "ui_managerpage.h"

int nrow = -1;
int ncol = -1;

ManagerPage::ManagerPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerPage)
{
    ui->setupUi(this);

    ui->changeInfText->setMaxLength(6);

    p=this->parentWidget();

    QSqlQuery query(mybase);
    QString passwordStr;
    bool ret=query.exec("select * from password;");
    if(ret==false)
    {
        qDebug()<<"查询数据失败了,原因是: "<<query.lastError().text();
        return;
    }
    while(query.next())
    {
        passwordStr = query.value(0).toString();
    }
    ui->changeInfText->setPlaceholderText(passwordStr);
    query.seek(0);
    query.previous();
}

ManagerPage::~ManagerPage()
{
    delete ui;
}

void ManagerPage::displayInfAgain()
{
    ui->tableWidget->clearContents();
    int i = 0;
    QSqlQuery mydb(mybase);
    int row_num = 0;
    bool ret = mydb.exec("select * from card;");
    if(ret == false)
    {
        qDebug()<<"查询信息失败，原因是: "<<mydb.lastError().text();
        return;
    }

    while(mydb.next())
        row_num++;

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(row_num);
    QStringList cardlist;
    cardlist.append("cardID");
    cardlist.append("Time");
    cardlist.append("carNum");
    ui->tableWidget->setHorizontalHeaderLabels(cardlist);

    mydb.seek(0);//定位到第0条记录
    mydb.previous();//在第0条记录的基础上再往前一条，这样就能读到第0条，否则会从第0条记录之后开始读取
    while(mydb.next())
    {
        QTableWidgetItem *item1 = new QTableWidgetItem(mydb.value("id").toString());
        QTableWidgetItem *item2 = new QTableWidgetItem(mydb.value("time").toString());
        QTableWidgetItem *item3 = new QTableWidgetItem(mydb.value("num").toString());

        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
        ui->tableWidget->setItem(i,2,item3);
        i++;
    }
}

void ManagerPage::on_backHomeBt_clicked()
{
    p->show();
    delete this;
}

void ManagerPage::on_displayInf_clicked()
{
    ui->tableWidget->clearContents();
    int i = 0;
    QSqlQuery mydb(mybase);
    int row_num = 0;
    bool ret = mydb.exec("select * from card;");
    if(ret == false)
    {
        qDebug()<<"查询信息失败，原因是: "<<mydb.lastError().text();
        return;
    }

    while(mydb.next())
        row_num++;

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(row_num);
    QStringList cardlist;
    cardlist.append("cardID");
    cardlist.append("Time");
    cardlist.append("carNum");
    ui->tableWidget->setHorizontalHeaderLabels(cardlist);

    mydb.seek(0);//定位到第0条记录
    mydb.previous();//在第0条记录的基础上再往前一条，这样就能读到第0条，否则会从第0条记录之后开始读取
    while(mydb.next())
    {
        QTableWidgetItem *item1 = new QTableWidgetItem(mydb.value("id").toString());
        QTableWidgetItem *item2 = new QTableWidgetItem(mydb.value("time").toString());
        QTableWidgetItem *item3 = new QTableWidgetItem(mydb.value("num").toString());

        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
        ui->tableWidget->setItem(i,2,item3);
        i++;
    }
}

void ManagerPage::on_changeInf_clicked()
{
    QSqlQuery mydb(mybase);
    if(nrow == -1 || ncol == -1)
        return;
    else if(ncol == 2)
    {
        QString changeID = ui->tableWidget->model()->index(nrow,0).data().toString();
        int carNum_change = ui->tableWidget->model()->index(nrow,2).data().toInt();
        if(carNum_change >= 11)
        {
            QMessageBox::critical(this,"警告","不合法的车位，请重新输入",QMessageBox::Ok,QMessageBox::Ok);
            ui->changeInfText->clear();
            displayInfAgain();
            return;
        }
        QString cmd = QString("update card set num=%1 where id=\"%2\";").arg(carNum_change).arg(changeID);
        bool ret = mydb.exec(cmd);
        if(ret == false)
        {
            qDebug()<<"修改信息失败，原因是: "<<mydb.lastError().text();
            return;
        }
    }
    ui->changeInfText->clear();
}

void ManagerPage::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    nrow = item->row();
    ncol = item->column();
    qDebug()<<nrow<<","<<ncol;
}

void ManagerPage::on_deleteInf_clicked()
{
    QSqlQuery mydb(mybase);
    if(nrow == -1 || ncol == -1)
        return;
    else
    {
        QString deleteID = ui->tableWidget->model()->index(nrow,0).data().toString();
        QString cmd = QString("delete from card where id=\"%1\";").arg(deleteID);
        bool ret = mydb.exec(cmd);
        if(ret == false)
        {
            qDebug()<<"删除信息失败，原因是: "<<mydb.lastError().text();
            return;
        }
        ui->tableWidget->removeRow(nrow);
    }
}

void ManagerPage::on_passwdChange_clicked()
{
    QSqlQuery query(mybase);
    QString passwordStr;
    bool ret=query.exec("select * from password;");
    if(ret==false)
    {
        qDebug()<<"查询数据失败了,原因是: "<<query.lastError().text();
        return;
    }
    while(query.next())
    {
        passwordStr = query.value(0).toString();
    }
    query.seek(0);
    query.previous();
    QString cmd = QString("update password set passwd=\"%1\" where passwd=\"%2\";").arg(ui->changeInfText->text()).arg(passwordStr);
    ret = query.exec(cmd);
    if(ret==false)
    {
        qDebug()<<"更新数据失败了,原因是: "<<query.lastError().text();
        return;
    }
    ui->changeInfText->setPlaceholderText(ui->changeInfText->text());
    ui->changeInfText->clear();
    QMessageBox::question(this,"成功","密码修改成功",QMessageBox::Ok,QMessageBox::Ok);
}
