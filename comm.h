#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * 定义链表结点 
 */
typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} Node;

/**
 * 定义二叉树结点 
 */
typedef struct treenode {
    int val;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

/**
 * 通用遍历打印数组元素函数 
 */
void printarr(int arr[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        printf("arr[%d]: %d, ", i, arr[i]);
    }
    puts("");
}

/**
 * 通用遍历打印链表
 */

void printlinklist(Node *head)
{

   while(head != NULL) {
        printf("%d -> ", head -> val);
        head = head -> next;
   }

    puts("");

}

/**
 * 随机生成指定长度的数组 
 */
int* randarr(int len)
{

    int *arr = (int *) malloc(sizeof(int) * len);

    // 使用时间作为随机数种子
    srand(time(NULL));

    for (int i = 0; i < len; i ++)
    {
        *(arr + i) = rand() % 100;
    }

    return arr;
}