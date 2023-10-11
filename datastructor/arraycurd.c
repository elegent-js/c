
/**
 * 演示线性表-数组的CURD操作
 */
#include "../comm.h"

#define ARR_LEN 10

// 当前数组中元素数量
int num = 0;

/**
 * 函数原型声明：添加数组元素到指定位置, 如果指定位置有值，需要进行顺移 
 */
int create(int arr[], int i);

/**
 * 函数原型声明：修改指定索引处的值
 */
int update(int arr[], int i, int newval);

int main(int argc, char* argv[]) 
{
    int arr[ARR_LEN] = {0};
    printarr(arr, ARR_LEN);

    create(arr, 100);
    create(arr, 101);
    create(arr, 102);
    create(arr, 103);
    create(arr, 104);

    printarr(arr, ARR_LEN);


    update(arr, 4, 1004);

    printarr(arr, ARR_LEN);


    return 0;
}


int create(int arr[], int i)
{
    if (arr == NULL || num >= 10) {
        return -1;
    }

    arr[num ++] = i;
    return i; 
}


int update(int arr[], int i, int newval)
{
    if (arr == NULL || i >= ARR_LEN) {
        return -1;
    }

    arr[i] = newval;
}