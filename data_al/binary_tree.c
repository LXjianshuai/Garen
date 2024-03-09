/*
二叉树实现
链式实现
实现前序遍历，中序遍历和后序遍历
gcc binary_tree.c -o binary_tree
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int val)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (NULL == new) {
        return NULL;
    }
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

//前序遍历递归实现
void preorderTraverse(Node *root)
{
    if (NULL == root) {
        return;
    }
    printf("%d ", root->val);
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

//中序遍历递归实现
void inorderTraverse(Node *root)
{
    if (NULL == root) {
        return;
    }
    inorderTraverse(root->left);
    printf("%d ", root->val);
    inorderTraverse(root->right);
}

//后序遍历递归实现
void postorderTraverse(Node *root)
{
    if (NULL == root) {
        return;
    }
    postorderTraverse(root->left);
    postorderTraverse(root->right);
    printf("%d ", root->val);
}

//前序遍历非递归实现
void preorderTraverse_2(Node *root)
{
    if (NULL == root) {
        return;
    }

    // 使用栈来存储节点
    Node *stack[100]; // 假设树深度不超过100
    int top = -1;
    //将根结点压入栈
    stack[++top] = root;
    while (top >= 0) {
        //弹出栈顶并访问
        Node *node = stack[top--];
        printf("%d ", node->val);
        if (node->right) {
            //先将右孩入栈，因为需要后访问它
            stack[++top] = node->right;
        }
        if (node->left) {
            stack[++top] = node->left;
        }
    }   
}

//中序遍历非递归实现
void inorderTraverse_2(Node *root)
{
    if (NULL == root) {
        return;
    }

    Node *stack[100];
    int top = -1;
    Node *cur = root;

    while (NULL != cur || top >=0)
    {
        //遍历到最左边的节点
        while (NULL != cur)
        {
            stack[++top] = cur;
            cur = cur->left;
        }
        //跳出循环，代表左子树为空
        //出栈访问目前未访问的最左的节点
        cur = stack[top--];
        printf("%d ", cur->val);

        // 移到右子树
        cur = cur->right;
    }
}

int main() 
{
    // 构建二叉树
    //         1
    //       /   \
    //      2     3
    //     / \
    //    4   5
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // 执行遍历
    printf("前序遍历： ");
    preorderTraverse(root);
    printf("\n");
    printf("中序遍历： ");
    inorderTraverse(root);
    printf("\n");
    printf("后序遍历： ");
    postorderTraverse(root);
    printf("\n");

    //非递归实现遍历
    printf("前序遍历： ");
    preorderTraverse_2(root);
    printf("\n");
    printf("中序遍历： ");
    inorderTraverse_2(root);
    printf("\n");
    return 0;
}