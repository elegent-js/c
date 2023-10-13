/**
 * 演示冒泡排序
 * 核心算法：相邻元素俩俩比较，一轮至少一个元素的位置确定，比较N轮即可 
 *  
 * 特点：
 * 1）原地排序
 * 2）稳定排序
 */
#include "../../comm.h"

#define ARR_LEN 100000

/**
 * 冒泡算法 
 */
void bubblesort(int a[], int len) {
    for (int i = 0; i < len - 1; i ++)
    {
        // 判断一轮中是否发生交换，如果未发生交换则说明已经有序，结束循环
        int change = 0;
        for (int j = 1; j < len - i; j ++)
        {
            if (a[j] < a[j - 1]) 
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                change = 1;
            }
        }

        if (!change) 
        {
            break;
        }
        
    }
}

int main(int argc, char * argv[])
{
    int *a = randarr(ARR_LEN);

    // 记录开始时间  
    clock_t start_time = clock();  
    bubblesort(a, ARR_LEN);
    clock_t end_time = clock();  


    printarr(a, ARR_LEN);

     // 计算程序执行时间（单位：毫秒）  
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;  
  
    printf("execute time: %.2f mills.", time_taken);  
  

}