/**
 * 快速排序实现
 * 
 * 核心算法： 
 * 
 *  选定一个基准点（pivot）, 从两端往中间搜索，小的在pivot左侧，大的在pivot右侧，一轮后pivot的值的位置已经确定
 *  将pivot左侧，右侧分别执行上述递归操作
 * 
 * 特点： 
 *   
 *  时间复杂度： O（logN * N）
 *  是否原地排序： 是
 *  是否稳定排序： 否
 *  
 *  快速排序是所有排序中最通用的，一般情况下是首选
 */

#include "../../comm.h"

#define ARR_LEN  100000

/**
 * 执行快速排序 
 */
void quickinternal(int arr[], int low, int high)
{
    if (low >= high) 
    {
        return;
    }

    int pivot = arr[low];
    int start = low;
    int end = high;


    while(low < high)
    {
        while(low < high && arr[high] >= pivot) {
            high --;
        }

        if(low < high) {
            arr[low] = arr[high];  
        }

        while(low < high && arr[low] <= pivot) {
            low ++;
        }

        if(low < high) {
            arr[high] = arr[low]; 
        }

    }

    arr[low] = pivot;
    quickinternal(arr, start, low - 1);    
    quickinternal(arr, low + 1, end); 
}

void quicksort(int arr[], int len)
{
    quickinternal(arr, 0, len - 1);
}



int main(int argc, char * argv[])
{
    int *a = randarr(ARR_LEN);

    // 记录开始时间  
    clock_t start_time = clock();  
    quicksort(a, ARR_LEN);
    clock_t end_time = clock();  


    printarr(a, ARR_LEN);

     // 计算程序执行时间（单位：毫秒）  
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;  
  
    printf("execute time: %.2f mills.", time_taken);  
  
    return 0;
}




