/**
 * 演示一个普通的二叉树 
 * 
 */

#include "../../comm.h"


/**
 * 插入数据至二叉搜索树 
 * 
 */
void insertTreeNode(TreeNode **node, int val)
{
    if (*node == NULL)
    {
        *node = (TreeNode *)malloc(sizeof(TreeNode));
        (*node) -> val = val;
        return;
    }

    TreeNode *curr = *node;

    while (curr != NULL)
    {
        if (val <= curr -> val)
        {
            if (curr -> left == NULL)
            {
                TreeNode *left = (TreeNode *)malloc(sizeof(TreeNode));
                left -> val = val;
                curr -> left = left;
                return;
            } else {
                curr = curr -> left;
            }
        } else {
            if (curr -> right == NULL)
            {
                TreeNode *right = (TreeNode *)malloc(sizeof(TreeNode));
                right -> val = val;
                curr -> right = right;
                return;
            } else {
                curr = curr -> right;
            }
        }
    }


} 

/**
 * 中序遍历二叉树 （有序输出）
 */
void printmidtree(TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printmidtree(node -> left);
    printf("node: %d; ", node -> val);
    printmidtree(node -> right);

}

/**
 * 从树中查找指定值的结点
*/
TreeNode *find(TreeNode *binarysearchtree, int val)
{

    TreeNode *curr = binarysearchtree;

    while (curr != NULL)
    {
        if (val < curr -> val)
        {
            curr = curr -> left;
        } else if (val > curr -> val)
        {
            curr = curr -> right;
        } else {
            return curr;
        }
    }

    return NULL;
}

int main(int argc, char * argv[])
{
    TreeNode *binarytree = NULL;

    insertTreeNode(&binarytree, 20);
    insertTreeNode(&binarytree, 11);
    insertTreeNode(&binarytree, 12);
    insertTreeNode(&binarytree, 13);
    insertTreeNode(&binarytree, 9);
    insertTreeNode(&binarytree, 7);
    insertTreeNode(&binarytree, 4);
    insertTreeNode(&binarytree, 17);
    insertTreeNode(&binarytree, 20);
    insertTreeNode(&binarytree, 25);
    insertTreeNode(&binarytree, 30);
    insertTreeNode(&binarytree, 23);
    insertTreeNode(&binarytree, 15);
    insertTreeNode(&binarytree, 14);



    printmidtree(binarytree);    


    TreeNode *target = find(binarytree, 15);

    if (target == NULL)
    {
        puts("target 15 not found in binary search tree");
    } else {
        printf("find %d in binary search tree. ", target -> val);
    }

    puts("");

    return 0;
}