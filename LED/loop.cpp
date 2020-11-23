#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <iostream>

//何回ループさせるか
#define count 10
//青信号の時間
#define TIME_LIMIT_BLUE 10
//黄信号の時間
#define TIME_LIMIT_YELLOW 1
//赤信号の時間(青と黄の合計)
#define TIME_LIMIT_RED TIME_LIMIT_BLUE + TIME_LIMIT_YELLOW

int main()
{
    //実行前にディレクトリの掃除
    std::system("sudo rmmod myled.ko");
    std::system("make clean");

    //実行
    std::system("make");
    std::system("sudo insmod myled.ko");
    std::system("sudo chmod 666 /dev/myled0");
    for (int i = 0; i < count; i++)
    {
        //青
        std::system("echo 1 > /dev/myled0");
        sleep(10);
        //黄
        std::system("echo 2 > /dev/myled0");
        
        //赤
        std::system("echo 3 > /dev/myled0");
    }
    std::system("echo 0 > /dev/myled0");
    std::system("sudo rmmod myled.ko");
    std::system("make clean");
}