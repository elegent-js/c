/**
 * 希尔排序是直接插入排序的改良版
 * 
 * 核心算法：
 *  1）以较大的间隔做直接插入排序，再缩小间隔 
 * 
 */

#include "../../comm.h"

#define ARR_LEN 100000

void shellsort(int arr[], int len)
{
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; i ++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}


int main(int argc, char * argv[])
{
    int *a = randarr(ARR_LEN);

    // 记录开始时间  
    clock_t start_time = clock();  
    shellsort(a, ARR_LEN);
    clock_t end_time = clock();  


    printarr(a, ARR_LEN);

     // 计算程序执行时间（单位：毫秒）  
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;  
  
    printf("execute time: %.2f mills.", time_taken);  
  

}