#ifndef RFID_H
#define RFID_H

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <dirent.h>

#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>
#include <signal.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stropts.h>
#include <net/if.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/time.h>
#include <termios.h>
#include <time.h>

#include <QTimer>
#include <QThread>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QPushButton>
#include <QLabel>
#include "v4l2cameara.h"

extern QSqlDatabase mybase;//安装数据库驱动
extern QList<QPushButton *> buttonList[10];
extern int whichButton;
extern QLabel *stopTimeSend;
extern QLabel *priceSend;
extern QLabel *carNumSend;
extern int busyCar[10];
extern int car;
extern int cameraOpenOrStop;
extern QPushButton *managerSend;
extern QPushButton *flushCarSend;

class RFID:public QThread
{
public:
    RFID();
    int open_serial();
    int init_tty(int fd);
    unsigned char CalBCC(unsigned char *buf, int n);
    int PiccRequest(int fd);
    int PiccAnticoll(int fd);
    void usingRFID();
    struct timeval timeout;
    volatile unsigned int cardid;
    void run();
private:
    int fd;
    QString cardNumCompare;
};

#endif // RFID_H
