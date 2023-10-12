/**
 * 演示创建stack，push, pop, peek操作 
 * 
 */
#include "../../comm.h"

#define ARR_LEN  10

// 数组中当前元素数量
int num = 0;

/**
 * 压栈操作
 * 栈已满，返回-1
 * 压栈成功，返回0 
 * 
 */
int push(int arr[], int i)
{
    if (num == ARR_LEN - 1) 
    {
        return -1;
    }

    arr[num ++] = i;
    return 0;
}

/**
 * 出栈 
 * 
 */
int pop(int arr[])
{
    if (num == 0) 
    {
        return -1;
    }

    return arr[--num];
}

/**
 * 取栈顶元素 
 */
int peek(int arr[])
{
    if (num == 0) 
    {
        return -1;
    }

    return arr[num - 1];
}



int main(int argc, char* argv[])
{
    int stack[10] = {0};
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    push(stack, 70);
    push(stack, 80);
    push(stack, 90);

    printarr(stack, num);

    int r = pop(stack);
    printf("pop: %d \n", r);

    r = pop(stack);
    printf("pop: %d \n", r);
    r = pop(stack);
    printf("pop: %d \n", r);
    r = pop(stack);
    printf("pop: %d \n", r);
    r = pop(stack);
    printf("pop: %d \n", r);
    r = pop(stack);
    printf("pop: %d \n", r);

    printarr(stack, num);
}
