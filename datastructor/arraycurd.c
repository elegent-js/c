
/**
 * 演示线性表-数组的CURD操作
 */
#include "../comm.h"

#define ARR_LEN 10

// 当前数组中元素数量
int num = 0;

/**
 * 函数原型声明：添加数组元素到数组末尾
 */
int create(int arr[], int i);

/**
 * 函数原型声明：修改指定索引处的值
 */
int update(int arr[], int i, int newval);


/**
 * 函数原型：从数组中查找指定的元素，能找到返回数组下标，找不到返回-1 
 */
int search(int arr[], int target);


/**
 * 函数原型：删除数组指定索引位的元素
 * 删除的如果是中间元素，涉及到后续元素的移位 
 */
int delete(int arr[], int i);


int main(int argc, char* argv[]) 
{
    int arr[ARR_LEN] = {0};
    printarr(arr, num);

    create(arr, 100);
    create(arr, 101);
    create(arr, 102);
    create(arr, 103);
    create(arr, 104);

    printarr(arr, num);


    update(arr, 4, 1004);

    printarr(arr, num);

    int index = search(arr, 102);
    printf("find %d in arr, index: %d \n", 102, index);

    int r = delete(arr, 101);
    printarr(arr, num);
    
    return 0;
}

/**
 * 往数组中插入新元素
 */
int create(int arr[], int i)
{   
    // 数组为空，或者当前数组已满，无法新增元素，返回-1
    if (arr == NULL || num >= ARR_LEN) {
        return -1;
    }

    arr[num ++] = i;
    return i; 
}

/**
 *  更新数组指定位置的值
 */
int update(int arr[], int i, int newval)
{
    // 数组为NULL，或者下标越界，更新失败，返回-1
    if (arr == NULL || i >= ARR_LEN || i < 0) {
        return -1;
    }

    arr[i] = newval;
    return i;
}

/**
 * 从数组中查找指定的元素，能找到返回数组下标，找不到返回-1 
 */
int search(int arr[], int target)
{
    // 数组为NULL，或者当前无元素直接返回-1
    if (arr == NULL || num == 0) {
        return -1;
    }

    for (int i = 0; i < num; i ++) 
    {
        if (arr[i] == target) 
        {
            return i;
        }
    }

    return -1;
}

/**
 * 删除数组指定索引位的元素 
 * 
 * 删除失败返回-1
 * 删除成功返回0
 */
int delete(int arr[], int i)
{
    // 当前数据为NULL或者当前数据元素为空
    if (arr == NULL || num == 0)
    {
        return -1;
    }

    // 查找到待删除位置的下标
    int index = search(arr, i);
    // 未找到指定元素，返回-1
    if (index == -1) {
        return -1;
    }

    // 待删除的是数组最后一个元素
    if (index == num - 1) {
        num --;
        return 0;
    }

    // 待删除的是数组中间的元素，后续元素需要移位
    for (int k = index; k < num; k ++)
    {
        arr[k] = arr[k + 1];
    }

    num --;
    return 0;
}