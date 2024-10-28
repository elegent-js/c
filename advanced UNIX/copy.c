/**
 * 
 * 1. 从标准输入读取输入，并输出
 * 
 * @author: liupj
 */
#include "apue.h"
#define BUFFSIZE 4096 


int main(int args, char *argv[])
{
    int n;

    char buf[BUFFSIZE];
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("write error");
        }
    }


    if (n < 0)
    {
        printf("read error");
    }
    
    exit(0);

}

