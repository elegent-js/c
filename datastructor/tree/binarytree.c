/**
 * 演示一个普通的二叉树 
 * 
 */

#include "../../comm.h"

/**
 * 创建树结点 
 */
TreeNode *createTreeNode()
{
    return (TreeNode *) malloc(sizeof(TreeNode));
}

/**
 * 中序遍历二叉树 
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
    TreeNode *binarytree = createTreeNode();
    binarytree -> val = 100;

    TreeNode *left = createTreeNode();
    left -> val = 80;
    TreeNode *right = createTreeNode();
    right -> val = 120;

    binarytree -> left = left;
    binarytree -> right = right;

    TreeNode *left1 = createTreeNode();
    left1 -> val = 70;
    TreeNode *right1 = createTreeNode();
    right1 -> val = 130;

    left -> left = left1;
    right -> right = right1;


    printmidtree(binarytree);    


    TreeNode *target = find(binarytree, 111);

    if (target == NULL)
    {
        puts("target 111 not found in binary search tree");
    } else {
        printf("find %d in binary search tree. ", target -> val);
    }

    puts("");

    return 0;
}