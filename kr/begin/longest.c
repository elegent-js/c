#include <stdio.h>
#include <string.h>

/**
 * 打印最长的输入行
 */

#define MAXLINE 1000

int get_line(char line[], int maxline);

int main(int argc, char *argv[])
{
    // 当前行的长度
    int len;
    // 行的最大长度
    int max = 0;

    char line[MAXLINE];
    char longest[MAXLINE];

    while((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            strcpy(longest, line);
        }
    }

    if (max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}


int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}