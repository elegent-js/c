#include <stdio.h>

/**
 * 通用打印数组元素函数 
 */
void printarr(int arr[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        printf("arr[%d]: %d ", i, arr[i]);
    }
    puts("");
}