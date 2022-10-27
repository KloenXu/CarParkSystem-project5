#include "rfid.h"

void openButton()
{
    buttonList->at(0)->setEnabled(true);
    buttonList->at(1)->setEnabled(true);
    buttonList->at(2)->setEnabled(true);
    buttonList->at(3)->setEnabled(true);
    buttonList->at(4)->setEnabled(true);
    buttonList->at(5)->setEnabled(true);
    buttonList->at(6)->setEnabled(true);
    buttonList->at(7)->setEnabled(true);
    buttonList->at(8)->setEnabled(true);
    buttonList->at(9)->setEnabled(true);
}

void closeButton()
{
    buttonList->at(0)->setEnabled(false);
    buttonList->at(1)->setEnabled(false);
    buttonList->at(2)->setEnabled(false);
    buttonList->at(3)->setEnabled(false);
    buttonList->at(4)->setEnabled(false);
    buttonList->at(5)->setEnabled(false);
    buttonList->at(6)->setEnabled(false);
    buttonList->at(7)->setEnabled(false);
    buttonList->at(8)->setEnabled(false);
    buttonList->at(9)->setEnabled(false);
}

void carExitToButton(int car_num)
{
    if(car_num == 1)
    {
        buttonList->at(0)->setStyleSheet("");
        busyCar[0] = 0;
    }
    else if(car_num == 2)
    {
        buttonList->at(1)->setStyleSheet("");
        busyCar[1] = 0;
    }
    else if(car_num == 3)
    {
        buttonList->at(2)->setStyleSheet("");
        busyCar[2] = 0;
    }
    else if(car_num == 4)
    {
        buttonList->at(3)->setStyleSheet("");
        busyCar[3] = 0;
    }
    else if(car_num == 5)
    {
        buttonList->at(4)->setStyleSheet("");
        busyCar[4] = 0;
    }
    else if(car_num == 6)
    {
        buttonList->at(5)->setStyleSheet("");
        busyCar[5] = 0;
    }
    else if(car_num == 7)
    {
        buttonList->at(6)->setStyleSheet("");
        busyCar[6] = 0;
    }
    else if(car_num == 8)
    {
        buttonList->at(7)->setStyleSheet("");
        busyCar[7] = 0;
    }
    else if(car_num == 9)
    {
        buttonList->at(8)->setStyleSheet("");
        busyCar[8] = 0;
    }
    else if(car_num == 10)
    {
        buttonList->at(9)->setStyleSheet("");
        busyCar[9] = 0;
    }
    car++;
    QString carStr = QString("%1").arg(car);
    carNumSend->setText(carStr);
}

/*void car_init_RFID()
{
    car = 10;
    QString carStr = QString("%1").arg(car);
    carNumSend->setText(carStr);

    for(int i = 0;i <= 9;i++)
    {
        if(busyCar[i] == 0)
            buttonList->at(i)->setStyleSheet("");
        else
        {
            buttonList->at(i)->setStyleSheet("background-color:rgb(255,0,0);");
            car--;
        }
    }

    carStr = QString("%1").arg(car);
    carNumSend->setText(carStr);
}*/

int parkIsEmpty()
{
    int i;
    for(i = 0;i <= 9;i++)
    {
        if(busyCar[i] == 1)
            return 0;
    }
    return 1;
}

RFID::RFID()
{

}

int RFID::open_serial()
{
    int fd;

    fd = open("/dev/ttySAC1", O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd < 0)
    {
        printf("Open /dev/ttySAC1 fail!\n");
        return -1;
    }
    return fd;
}

int RFID::init_tty(int fd)
{
    struct termios termios_new; //声明设置串口的结构体
    bzero(&termios_new, sizeof(termios_new));

    cfmakeraw(&termios_new); // cfmakeraw()设置终端属性，就是设置termios结构中的各个参数。

    //设置波特率
    cfsetispeed(&termios_new, B9600);
    cfsetospeed(&termios_new, B9600);

    // CLOCAL和CREAD分别用于本地连接和接受使能，因此，首先要通过位掩码的方式激活这两个选项
    termios_new.c_cflag |= CLOCAL | CREAD;

    //通过掩码设置数据位为8位
    termios_new.c_cflag &= ~CSIZE;
    termios_new.c_cflag |= CS8;

    //设置无奇偶校验
    termios_new.c_cflag &= ~PARENB;

    //一位停止位
    termios_new.c_cflag &= ~CSTOPB;

    // 可设置接收字符和等待时间，无特殊要求可以将其设置为0
    termios_new.c_cc[VTIME] = 10;
    termios_new.c_cc[VMIN] = 1;

    // 用于清空输入/输出缓冲区
    tcflush(fd, TCIFLUSH);

    //完成配置后，可以使用以下函数激活串口设置
    tcsetattr(fd, TCSANOW, &termios_new);
    return 0;
}

unsigned char RFID::CalBCC(unsigned char *buf, int n)
{
    int i;
    unsigned char bcc = 0;
    for (i = 0; i <= n - 1; i++)
    {
        bcc ^= *(buf + i);
    }
    return (~bcc);
}

int RFID::PiccRequest(int fd)
{
    unsigned char WBuf[128], RBuf[128];
    int ret, len = 0;
    fd_set rdfd;

    memset(WBuf, 0, 128); //数组清空
    memset(RBuf, 0, 128);

    WBuf[0] = 0x07;                      //帧长= 7 Byte
    WBuf[1] = 0x02;                      //包号= 0 , 命令类型
    WBuf[2] = 0x41;                      //命令= 'A'
    WBuf[3] = 0x01;                      //信息长度
    WBuf[4] = 0x52;                      //请求模式:  ALL=0x52
    WBuf[5] = CalBCC(WBuf, WBuf[0] - 2); //校验和
    WBuf[6] = 0x03;                      //结束标志

    while (1)
    {
        FD_ZERO(&rdfd);
        FD_SET(fd, &rdfd);
        tcflush(fd, TCIFLUSH);

        write(fd, WBuf, 7);

        ret = select(fd + 1, &rdfd, NULL, NULL, &timeout); //监测文件描述符的变化
        switch (ret)
        {
        case -1:
            perror("select error\n");
            break;
        case 0:
            len++; // 3次请求超时后，退出该函数
            if (len == 3)
            {
                len = 0;
                return -1;
            }

            // printf("Request timed out.\n");
            break;
        default:
            usleep(10000);
            ret = read(fd, RBuf, 8);

            if (ret < 0)
            {
                //printf("len = %d, %m\n", ret, errno);
                printf("len = %d\n",ret);
                break;
            }

            // printf("RBuf[2]:%x\n", RBuf[2]);
            if (RBuf[2] == 0x00) //应答帧状态部分为0 则请求成功
            {
                return 0;
            }
            break;
        }

        usleep(100000);
    }

    return -1;
}

int RFID::PiccAnticoll(int fd)
{
    unsigned char WBuf[128], RBuf[128];
    int ret = 1, len = 0;
    fd_set rdfd;

    memset(WBuf, 0, 128);
    memset(RBuf, 1, 128);

    WBuf[0] = 0x08;                      //帧长= 8 Byte
    WBuf[1] = 0x02;                      //包号= 0 , 命令类型= 0x01
    WBuf[2] = 0x42;                      //命令= 'B'
    WBuf[3] = 0x02;                      //信息长度= 2
    WBuf[4] = 0x93;                      //防碰撞0x93
    WBuf[5] = 0x00;                      //位计数0
    WBuf[6] = CalBCC(WBuf, WBuf[0] - 2); //校验和
    WBuf[7] = 0x03;                      //结束标志

    while (1)
    {

        tcflush(fd, TCIFLUSH);
        FD_ZERO(&rdfd);
        FD_SET(fd, &rdfd);

        write(fd, WBuf, 8);

        ret = select(fd + 1, &rdfd, NULL, NULL, &timeout);
        switch (ret)
        {
        case -1:
            perror("select error\n");
            break;
        case 0:
            len++;
            if (len == 10)
            {
                len = 0;
                return -1;
            }
            perror("Timeout:");
            break;

        default:
            usleep(10000);
            ret = read(fd, RBuf, 10);
            if (ret < 0)
            {
                printf("ret = %d\n", ret);
                break;
            }
            if (RBuf[2] == 0x00) //应答帧状态部分为0 则获取ID 成功
            {
                cardid = (RBuf[4] << 24) | (RBuf[5] << 16) | (RBuf[6] << 8) | RBuf[7];

                return 0;
            }
        }
    }

    return -1;
}

void RFID::usingRFID()
{

    //初始化串口
    init_tty(fd);
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    int ret;
    //发送A命令
    ret = PiccRequest(fd);
    if(ret == -1)  //若是请求超时退出，必须要关闭串口后，重新打开才能再次读取数据
    {
        usleep(500000);
        ::close(fd);

        //打开串口文件
        fd = open_serial();
        /*初始化串口*/
        init_tty(fd);
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        //continue;
        return;
    }

    else//(ret == 0)
    {
        printf("ok!\n");
    }
    //发送B命令 和获取卡号
    ret = PiccAnticoll(fd);

    //若获取的cardid为0，或获取id超时，则需重新发送'A'命令
    if(cardid == 0 || ret == -1)
        //continue;
        return;
    else if(ret == 0)
    {
        printf("card ID = %x\n", cardid);  //打印cardid号
        QString cardnum = QString::number(cardid,16);

        bool ret;
        QSqlQuery query(mybase);
        ret=query.exec("create table if not exists card(id text not null unique,time text,num int not null unique);");
        if(ret==false)
        {
            qDebug()<<"新建表格失败了,原因是: "<<query.lastError().text();
            return;
        }
        time_t time_enter = time(NULL);
        QString cmd = QString("insert into card values (\"%1\",\"%2\",\"%3\");").arg(cardnum).arg(time_enter).arg(whichButton);
        ret=query.exec(cmd);
        if(ret==false)//卡号已经在数据库里
        {
            //qDebug()<<"插入卡号失败了,原因是: "<<query.lastError().text();
            if(query.lastError().text() == "UNIQUE constraint failed: card.id Unable to fetch row" || query.lastError().text() == "UNIQUE constraint failed: card.num Unable to fetch row")
            {
                cmd = QString("select * from card where id=\"%1\";").arg(cardnum);
                bool ret1=query.exec(cmd);
                if(ret1 == false)
                {
                    qDebug()<<"查询信息失败，原因是: "<<query.lastError().text();
                    return;
                }
                query.next();
                QString time_getStr = query.value("time").toString();
                time_t time_get = (time_t)time_getStr.toLong();
                qDebug()<<"time_get:"<<time_get;
                time_t time_exit = time(NULL);
                qDebug()<<"time_exit:"<<time_exit;
                time_t time_fact = time_exit - time_get;
                qDebug()<<"time_fact:"<<time_fact;

                qDebug()<<"num:"<<query.value("num").toInt();
                carExitToButton(query.value("num").toInt());

                QString time_factStr = QString("%1").arg(time_fact);
                QString price_Str = QString("%1").arg(time_fact * 2);
                stopTimeSend->setText(time_factStr);
                priceSend->setText(price_Str);

                cmd = QString("delete from card where id=\"%1\";").arg(cardnum);
                qDebug()<<"delete card";
                query.exec(cmd);
                if(parkIsEmpty() == 1)
                    cameraOpenOrStop = 0;
                sleep(1);
            }
            return;
        }
        else//卡号未在数据库里
        {
            //car_init_RFID();
            openButton();
            int count = 0;
            managerSend->setEnabled(false);
            flushCarSend->setEnabled(false);
            while(whichButton==-1)
            {
                if(count == 0)
                {
                    qDebug()<<"choose Button";
                    count = 1;
                }
                if(whichButton != -1)
                    break;
                qDebug()<<whichButton;
                usleep(500000);
            }
            managerSend->setEnabled(true);
            flushCarSend->setEnabled(true);
            qDebug()<<whichButton;
            cmd = QString("update card set num=%1 where id=\"%2\";").arg(whichButton).arg(cardnum);
            ret=query.exec(cmd);
            if(ret == false)
            {
                qDebug()<<"修改按钮号失败了,原因是: "<<query.lastError().text();
            }
            if(parkIsEmpty() == 0)
                cameraOpenOrStop = 1;
            sleep(1);
            whichButton = -1;
        }

        usleep(500000);
        //break;
    }
}

void RFID::run()
{
    fd = open_serial();
    while(1)
        usingRFID();
}



