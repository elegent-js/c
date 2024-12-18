#include <stdio.h>
/**
 * 统计输入中的数字、空白符（空格、制表符、换行符）和其他字符的个数
 * 采用数组记录0～9数字的个数
 */
int main(int argc, char *argv[])
{
    int white = 0;
    int other = 0;
    int digits[10] = {0};

    int c;
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ digits[c - '0'];
        }
        else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++ white;
        }
        else
        {
            ++ other;
        }
    }
    
    printf("digits =");
    for (int i = 0; i < 10; ++i)
    {
        printf(" %d", digits[i]);
    }

    printf(", white = %d, other = %d\n", white, other);

    return 0;
}