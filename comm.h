#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} Node;

/**
 * 通用遍历打印数组元素函数 
 */
void printarr(int arr[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        printf("arr[%d]: %d ", i, arr[i]);
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