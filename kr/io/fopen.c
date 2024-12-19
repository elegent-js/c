#include <stdio.h>

/**
 * 使用fopen打开文件
 * FILE* fopen(const char *filename, const char *mode);
 * 
 */
int main(int argc, char *argv[])
{

    FILE *fp = fopen("example.txt", "w");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(fp, "Hello, World!\n");
    fclose(fp);

    return 0;
}