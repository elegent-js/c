/**
 * 直接插入排序
 * 
 * 核心算法： 从第二位开始往前比较，找到合适的位置，保证第N轮时前N个元素有序 
 *  
 * 特点： 
 *    1）原地排序
 *    2）稳定排序
 */

#include "../../comm.h"

#define ARR_LEN 100000

void insertionsort(int a[], int len)
{
    for (int i = 1; i < len; i ++)
    {
        int temp = a[i];
        int j;
        for (j = i - 1; j >= 0; j --)
        {
            if (a[j] > temp)
            {
               a[j + 1] = a[j];
            } else {
                break;
            }
        }

        a[j] = temp; 
    }
}

int main(int argc, char * argv[])
{
    int *a = randarr(ARR_LEN);

    // 记录开始时间  
    clock_t start_time = clock();  
    insertionsort(a, ARR_LEN);
    clock_t end_time = clock();  


    printarr(a, ARR_LEN);

     // 计算程序执行时间（单位：毫秒）  
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;  
  
    printf("execute time: %.2f mills.", time_taken);  
  

}