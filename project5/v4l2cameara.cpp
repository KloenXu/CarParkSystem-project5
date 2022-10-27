#include "v4l2cameara.h"

//封装函数把YUV转成RGB
int yuvtorgb(int y, int u, int v)
{
    int r, g, b;
    int pix;
    r = y + 1.4075 * (v - 128);
    g = y - 0.3455 * (u - 128) - 0.7169 * (v - 128);
    b = y + 1.779 * (u - 128);
    //修正计算结果
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;
    if (r < 0)
        r = 0;
    if (g < 0)
        g = 0;
    if (b < 0)
        b = 0;
    //因为lcd要求是ARGB，所以我们顺便在这里把RGB转成ARGB，方便后续使用
    pix = 0x00 << 24 | r << 16 | g << 8 | b;
    return pix;
}

//封装函数把一张完整画面的YUYV数据全部转换成ARGB数据
int allyuvtoargb(char *yuvdata, int *argb)
{
    /*
        yuvdata[0] -->Y
        yuvdata[1] -->U
        yuvdata[2] -->Y
        yuvdata[3] -->V
    */
    int i, j;
    //循环究竟循环多少次，取决于你的画面有多少个像素点
    //有W*H个像素点
    for (i = 0, j = 0; i < W * H; i += 2, j += 4) // W*H/2  次数
    {
        argb[i] = yuvtorgb(yuvdata[j], yuvdata[j + 1], yuvdata[j + 3]);
        argb[i + 1] = yuvtorgb(yuvdata[j + 2], yuvdata[j + 1], yuvdata[j + 3]);
    }
    return 0;
}

//封装函数把一张完整画面的YUYV数据全部转换成RGB数据
int allyuvtorgb(char *yuvdata,char *rgb)
{
    /*
        yuvdata[0] -->Y
        yuvdata[1] -->U
        yuvdata[2] -->Y
        yuvdata[3] -->V
    */
    int i,j;
    int pix;
    char *p;
    //有W*H个像素点
    for(i=0,j=0; i<W*H*3; i+=6,j+=4) // W*H*3/6  次数
    {
        pix=yuvtorgb(yuvdata[j],yuvdata[j+1],yuvdata[j+3]);
        p=(char *)&pix;
        //根据学习的C语言指针运算规则
        //p+0-->B p+1-->G  p+2-->R  p+3 -->A
        rgb[i]=*(p+2);
        rgb[i+1]=*(p+1);
        rgb[i+2]=*(p+0);

        pix=yuvtorgb(yuvdata[j+2],yuvdata[j+1],yuvdata[j+3]);
        p=(char *)&pix;
        rgb[i+3]=*(p+2);
        rgb[i+4]=*(p+1);
        rgb[i+5]=*(p+0);
    }
    return 0;
}


//把RGB压缩成jpeg图片
int rgbtojpg(char *rgbdata,char *jpgfile)
{
    int i;
    //定义压缩结构体和处理错误的结构体并初始化
    struct jpeg_compress_struct mycom;
    jpeg_create_compress(&mycom);
    struct jpeg_error_mgr myerr;
    mycom.err=jpeg_std_error(&myerr);

    //设置压缩参数(宽，高)
    mycom.image_width=W;
    mycom.image_height=H;
    mycom.in_color_space=JCS_RGB;
    mycom.input_components=3;
    jpeg_set_defaults(&mycom);

    //设置压缩比例(压缩质量)
    jpeg_set_quality(&mycom,90,(boolean)true);

    //绑定输出
    FILE *myfile=fopen(jpgfile,"w+");
    if(myfile==NULL)
    {
        perror("新建jpg图片失败了!\n");
        return -1;
    }
    jpeg_stdio_dest(&mycom,myfile);

    //开始压缩
    jpeg_start_compress(&mycom,(boolean)true);

    JSAMPROW row_pointer[1];
    //把压缩后的数据写入到空白的jpeg文件
    for(i=0; i<H; i++)
    {
        row_pointer[0]=(JSAMPROW)(rgbdata+i*W*3);
        //一次写入一行数据
        jpeg_write_scanlines(&mycom,row_pointer,1);
    }

    //收尾
    jpeg_finish_compress(&mycom);
    jpeg_destroy_compress(&mycom);
    fclose(myfile);
    return 0;
}


V4L2Cameara::V4L2Cameara()
{

}

int V4L2Cameara::camera_init()
{
    int ret;
    int i;

    //打开液晶屏的驱动
    lcdfd = open("/dev/fb0", O_RDWR);
    if (lcdfd == -1)
    {
        perror("打开液晶屏的驱动失败!\n");
        return -1;
    }

    //映射得到液晶屏的首地址
    lcdmem = (int *)mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcdfd, 0);
    if (lcdmem == NULL)
    {
        perror("映射lcd失败了!\n");
        return -1;
    }

    //摄像头的驱动是谁？--》打开摄像头的驱动
    camerafd = open("/dev/video7", O_RDWR);
    if (camerafd == -1)
    {
        perror("打开摄像头的驱动失败!\n");
        return -1;
    }

    //提前设置好摄像头的采集格式--》画面宽，画面高，画面是什么格式。。。。
    struct v4l2_format myfmt;
    bzero(&myfmt, sizeof(myfmt));
    myfmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    myfmt.fmt.pix.width = W;
    myfmt.fmt.pix.height = H;
    myfmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV; // yuv格式
    ret = ioctl(camerafd, VIDIOC_S_FMT, &myfmt);
    if (ret == -1)
    {
        perror("设置采集格式失败了!\n");
        return -1;
    }

    //跟摄像头的驱动申请缓冲区
    struct v4l2_requestbuffers mybuf;
    bzero(&mybuf, sizeof(mybuf));
    mybuf.count = 4;//申请了4个缓冲区，可申请4-8个
    mybuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    mybuf.memory = V4L2_MEMORY_MMAP;
    ret = ioctl(camerafd, VIDIOC_REQBUFS, &mybuf);
    if (ret == -1)
    {
        perror("申请缓冲区失败!\n");
        return -1;
    }

    //分配刚才你申请的4个缓冲区
    struct v4l2_buffer otherbuf;
    for (i = 0; i < 4; i++)
    {
        bzero(&otherbuf, sizeof(otherbuf));
        otherbuf.index = i;
        otherbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        otherbuf.memory = V4L2_MEMORY_MMAP;
        ret = ioctl(camerafd, VIDIOC_QUERYBUF, &otherbuf);
        if (ret == -1)
        {
            perror("分配缓冲区失败!\n");
            return -1;
        }

        //顺便映射得到4个缓冲块的首地址(方便后面取出画面数据)
        array[i].somelen = otherbuf.length;
        array[i].start = mmap(NULL, otherbuf.length, PROT_READ | PROT_WRITE, MAP_SHARED, camerafd, otherbuf.m.offset);
        if (array[i].start == NULL)
        {
            perror("映射缓冲区首地址失败!\n");
            return -1;
        }

        //立马申请入队--》下一步摄像头立马就要启动采集了
        ret = ioctl(camerafd, VIDIOC_QBUF, &otherbuf);
        if (ret == -1)
        {
            perror("入队失败!\n");
            return -1;
        }
    }

    //启动摄像头采集
    enum v4l2_buf_type mytype;
    mytype = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ret = ioctl(camerafd, VIDIOC_STREAMON, &mytype);
    if (ret == -1)
    {
        perror("启动摄像头失败!\n");
        return -1;
    }

    return 0;
}

int V4L2Cameara::camera_using()
{
    int i,j;
    int ret;
    int argbbuf[W * H];
    fd_set myset;
    struct v4l2_buffer otherbuf;

    //循环出队，入队显示视频流， 但在QT中不能使用while
    FD_ZERO(&myset);
    FD_SET(camerafd, &myset); //监测摄像头
    //用多路复用监测摄像头是否有数据可读，有数据可读我才来出队
    ret = select(camerafd + 1, &myset, NULL, NULL, NULL);
    if (ret > 0)
    {
        for (i = 0; i < 4; i++)
        {
            bzero(&otherbuf, sizeof(otherbuf));
            otherbuf.index = i;
            otherbuf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            otherbuf.memory = V4L2_MEMORY_MMAP;
            //出队
            ret = ioctl(camerafd, VIDIOC_DQBUF, &otherbuf);
            if (ret == -1)
            {
                perror("出队失败!\n");
                return -1;
            }
            //把出队的画面数据在开发板的液晶屏上显示出来
            // array[i].start里面保存的就是一张张画面数据
            //画面数据是YUV格式,液晶屏要求ARGB格式
            //把YUV格式转换成ARGB格式
            allyuvtoargb((char *)(array[i].start), argbbuf);
            //把ARGB数据填充到开发板的液晶屏中
            /*
                        argbbuf[0]---argbbuf[W-1]   画面的第一行数据
                        lcdmem
                        argbbuf[W]---argbbuf[2*W-1] 画面的第二行数据
                        lcdmem+800
                    */
            for (j = 0; j < H; j++)
                memcpy(lcdmem + 800 * j + 640, &argbbuf[j * W], W * 4);

            //入队
            ret = ioctl(camerafd, VIDIOC_QBUF, &otherbuf);
            if (ret == -1)
            {
                perror("入队失败!\n");
                return -1;
            }
        }
    }
    return 0;
}

int V4L2Cameara::camera_uninit()
{
    int i;
    int ret;
    enum v4l2_buf_type mytype;
    mytype=V4L2_BUF_TYPE_VIDEO_CAPTURE;

    ret=ioctl(camerafd,VIDIOC_STREAMOFF,&mytype);
    if(ret==-1)
    {
        perror("关闭摄像头失败!\n");
        return -1;
    }
    close(camerafd);
    close(lcdfd);
    munmap(lcdmem,800*480*4);
    for(i=0; i<4; i++)
        munmap(array[i].start,array[i].somelen);
    return 0;
}

int V4L2Cameara::camera_full_black()
{
    int i;
    int argbbuf[W * H] = {0};
    for (i = 0; i < H; i++)
        memcpy(lcdmem + 800 * i + 640, &argbbuf[i * W], W * 4);
    return 0;
}

void V4L2Cameara::take_photo()
{
    char rgbbuf[W*H*3];
    int i;
    fd_set myset;
    struct v4l2_buffer otherbuf;
    //循环出队，入队显示视频流

    FD_ZERO(&myset);
    FD_SET(camerafd,&myset); //监测摄像头
    //用多路复用监测摄像头是否有数据可读，有数据可读我才来出队
    int ret=select(camerafd+1,&myset,NULL,NULL,NULL);
    if(ret>0)
    {
        for(i=0; i<4; i++)
        {
            bzero(&otherbuf,sizeof(otherbuf));
            otherbuf.index=i;
            otherbuf.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
            otherbuf.memory=V4L2_MEMORY_MMAP;
            //出队
            ret=ioctl(camerafd,VIDIOC_DQBUF,&otherbuf);
            if(ret==-1)
            {
                perror("出队失败!\n");
                return;
            }
            //把出队的画面数据保存成jpeg图片
            //array[i].start里面保存的就是一张张画面数据
            //画面数据是YUV格式,jpeg图片要求是RGB数据压缩得到的
            //把YUV格式转换成RGB格式
            allyuvtorgb((char *)(array[i].start),rgbbuf);
            //把刚才转换得到的RGB数据压缩成jpeg图片
            //sprintf(jpgname,"%d.jpg",n++);
            char path[10] = "temp.jpg";
            rgbtojpg(rgbbuf,path);
            //入队
            ret=ioctl(camerafd,VIDIOC_QBUF,&otherbuf);
            if(ret==-1)
            {
                perror("入队失败!\n");
                return;
            }
        }
    }

}

void V4L2Cameara::run()
{
    while(1)
    {
        if(cameraOpenOrStop == 1)
            camera_using();
        else
            camera_full_black();
    }
}

