/**
 * 归并排序用到了分解和合并思想
 * 
 * 核心算法： 
 * 
 * 将一个长的序列分为两段，两段排序后再合并，以此递归，小段再分为更小的两段，知道只有两个元素
 *  
 * 核心就是分治思想
 * 
 */

#include "../../comm.h"

#define ARR_LEN 100000

// 合并两个有序数组  
void merge(int arr[], int left, int mid, int right) {  
    int i = left, j = mid + 1, k = 0;  
    int *temp = (int *)malloc((right - left + 1) * sizeof(int));  
    while (i <= mid && j <= right) {  
        if (arr[i] <= arr[j]) {  
            temp[k ++] = arr[i ++];  
        } else {  
            temp[k ++] = arr[j ++];  
        }  
    }  
    while (i <= mid) {  
        temp[k ++] = arr[i ++];  

    }  
    while (j <= right) {  
        temp[k ++] = arr[j ++];  
    }  

    for (int p = 0; p < k; p++) {  
        arr[left + p] = temp[p];  
    }  
    free(temp);  
}  


void mergesortinternal(int arr[], int left, int right)
{
    if (left == right) return;

    int mid = (left + right) / 2;

    mergesortinternal(arr, left, mid);
    mergesortinternal(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void custommergesort(int arr[], int len)
{
    mergesortinternal(arr, 0, len - 1);
}


int main(int argc, char * argv[])
{
    int *a = randarr(ARR_LEN);

    // 记录开始时间  
    clock_t start_time = clock();  
    custommergesort(a, ARR_LEN);
    clock_t end_time = clock();  


    printarr(a, ARR_LEN);

     // 计算程序执行时间（单位：毫秒）  
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;  
  
    printf("execute time: %.2f mills.", time_taken);  
  
    return 0;
}
