#include "keyboardpress.h"
#include <QDebug>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QApplication>
keyboardPress::keyboardPress(QWidget *parent) : QPushButton(parent)
{
    //关联clicked信号和自定义的槽函数
    connect(this,SIGNAL(clicked()),this,SLOT(fun()));
}

void keyboardPress::fun()
{
    //获取信号的发送者
    QPushButton *p=qobject_cast<QPushButton *>(sender());
    QString str=p->text();
    QKeyEvent *keyevent;
    //按照上课讲的事件产生的流程去写代码
    //自定义一个按键事件
    //对特殊按键单独判断
    if(str=="<--") //退格
    {
        keyevent=new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier,str);
    }
    else
    {
        keyevent=new QKeyEvent(QEvent::KeyPress,str.toInt()-32,Qt::NoModifier,str);
    }

    //把这个按键事件发送出去--》发送个鼠标光标聚集的组件
    //QCoreApplication::postEvent(鼠标光标聚集的组件,keyevent);
    QCoreApplication::postEvent(QApplication::focusWidget(),keyevent);
}
