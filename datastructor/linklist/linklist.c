/**
 * 演示双向链表 linklist CURD操作 
 * 
 */
#include "../../comm.h"


/**
 * 从链表中查找指定元素的节点
 */
Node * findNode(Node *head, int target)
{
    while(head -> next != NULL)
    {
        if (head -> val == target)
        {
            return head;
        }

        head = head -> next;
    }

    return NULL;
}

/**
 * 插入元素至链表尾 
 */
void insert(Node **head, int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> val = data;
    newNode -> next = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
    } else {

        Node *temp = *head;
        while ( temp -> next != NULL) 
        {
            temp = temp -> next;
        }

        temp -> next = newNode;
        newNode -> prev = temp;
    }
}

/**
 * 更新链表中某个节点的数据
 * 查不到该节点，更新失败返回-1
 * 更新成功返回0 
 */
int update(Node *head, int target, int newdata)
{
    Node *temp = head;
    Node *currNode = findNode(head, target);

    if (currNode == NULL)
    {
        return -1;
    }

    currNode -> val = newdata;
    return 0;
}

/**
 * 删除链表中指定元素 
 */
int delete(Node *head, int val)
{
    Node *curr = findNode(head, val);

    if (curr == NULL) 
    {
        return -1;
    }

    curr -> prev -> next = curr -> next;
    free(curr);
    return 0;
}


/**
 * 反转链表
 * 
 * a -> b -> c -> d
 * 
 * reverse to
 * 
 * a <- b <- c <- d
 * 
 *
 */
Node *reverselinklist(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL) 
    {
        Node *next = curr -> next;
        curr -> next = prev;
        curr -> prev = next;

        prev = curr;
        curr = next;
    }

    return prev;
}

int main(int argc, char * args[])
{
    Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    insert(&head, 60);
    insert(&head, 70);
    insert(&head, 80);

    printlinklist(head);

    update(head, 40, 400);

    printlinklist(head);

    delete(head, 400);

    printlinklist(head);

    Node *reverse = reverselinklist(head);   

    printlinklist(reverse); 
    return 0;
}