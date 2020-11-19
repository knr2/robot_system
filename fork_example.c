#include <stdio.h>
#include <stdlib.h>

int main()
{
        int pid = fork(); //子の場合: 0, 親の場合: 子のPID
        //子の処理
        if (pid == 0)
        {
                while(1)
                {
                        sleep(1);
                        puts("child");
                }
                exit(0);

        }

         //親の処理

         while(1)
         {
                sleep(1);
                puts("parent");
         }
         exit(0);
}
