#include <stdio.h>

/**
 * 使用getchar()和putchar()实现文件复制
 */
int main(int argc, char *argv[])
{
    int c = getchar();

    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
    return 0;
}