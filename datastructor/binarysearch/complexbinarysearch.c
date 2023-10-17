/**
 * 变体的二分查找算法
 * 
 * 查找第一个等于target的下标
 * 
 * 此时对待查找的数组比较苛刻
 * 1）数组是有序的
 * 2）元素可以重复
 * 
 * @param arr 待查找数组
 * @param len 数组的长度
 */

#include "../../comm.h"

#define ARR_LEN 10

int binarysearch(int arr[], int len, int target)
{
    int low = 0;
    int high = len - 1;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 2);

        if (target < arr[mid]) 
        {
            high = mid - 1;
        } else if (target > arr[mid])
        {
            low = mid + 1;
        } else {

            if (mid == 0 || arr[mid - 1] != target) 
            {
                return mid;
            } else {
                high = mid - 1;
            }

        }
    }

    return -1;
}

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

int main(int argc, char* argv[])
{
    int a[ARR_LEN] = { 10, 8, 45, 12, 33, 33, 33, 2000, 1500, 1499 };
    
    // 记录开始时间  
    clock_t start_time = clock();  
    quicksort(a, ARR_LEN);
    printarr(a, ARR_LEN);

    int index = binarysearch(a, ARR_LEN, 33);
    printf("find %d in arr, index: %d \n", 33, index);

    clock_t end_time = clock();  

     // 计算程序执行时间（单位：毫秒）  
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;  
  
    printf("execute time: %.2f mills.", time_taken);  
  
    return 0;
}