#ifndef V4L2CAMEARA_H
#define V4L2CAMEARA_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>        //跟perror有关的头文件
#include <sys/mman.h>     //跟内存映射有关的头文件
#include <linux/input.h>  //跟输入子系统模型有关的头文件
#include <linux/videodev2.h> //跟V4L2架构有关的头文件
#include "jpeglib.h"

#include <QThread>

#define W 160 //本来我想把宽设置成800，但是摄像头默认最大的宽是640,除以4，放在右上角
#define H 120

extern int cameraOpenOrStop;

//结构体，把每个缓冲块的信息组合在一个
struct bufmsg
{
    void *start; //存放每个缓冲区的首地址
    int somelen; //存放每个缓冲区的大小
};

class V4L2Cameara:public QThread
{
public:
    V4L2Cameara();
    int camera_init();
    int camera_using();
    int camera_uninit();
    int camera_full_black();
    void take_photo();
    void run();

private:
    int camerafd;
    int lcdfd;
    int *lcdmem;
    struct bufmsg array[4];//定义结构体数组，存放4个缓冲区的信息
};

#endif // V4L2CAMEARA_H
