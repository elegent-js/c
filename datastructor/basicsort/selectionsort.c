/**
 * 选择排序
 * 
 * 核心算法：每一轮比较出最小的放到第一位，以此类推 
 * 
 * 特点： 
 * 
 *   1）原地排序
 *   2）非稳定排序
 */

#include "../../comm.h"

#define ARR_LEN  100000

/**
 * 选择排序 
 */
void selectionsort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i ++) 
    {
        int curr = arr[i];
        int index = i;

        for (int j = i + 1; j < len; j ++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }

        arr[i] = arr[index];
        arr[index] = curr;
    }
}

int main(int argc, char * argv[])
{
    int *a = randarr(ARR_LEN);

    // 记录开始时间  
    clock_t start_time = clock();  
    selectionsort(a, ARR_LEN);
    clock_t end_time = clock();  


    printarr(a, ARR_LEN);

     // 计算程序执行时间（单位：毫秒）  
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;  
  
    printf("execute time: %.2f mills.", time_taken);  
  

}