#include "binarySearchTree.h"
#include <stdlib.h>
#include <string.h>
#include "doubleLinklistQueue.h"
#include <stdio.h>

enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,

};

/* 创建结点*/
static BSTreeNode *createBSTreeNewNode(ELEMENTTPYE val, BSTreeNode *Parant);

/* 静态函数前置声明*/
static int compareFunc(ELEMENTTPYE val1, ELEMENTTPYE val2);

/* 根据指定的值获取二叉搜索树里面的结点 */
static BSTreeNode *baseAppointValGetBSTreeNode(binarySearchTree *pBstree, ELEMENTTPYE val)

    /* 二叉搜索树的初始化 */
    int binarySearchTreeInit(binarySearchTree **pBstree, int (*compareFunc)(ELEMENTTPYE val1, ELEMENTTPYE val2))
{
    int ret = 0;
    /* 树开辟空间*/
    binarySearchTree *bstree = (binarySearchTree *)malloc(sizeof(binarySearchTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(binarySearchTree) * 1);
    /* 初始化树 */
    bstree->root = NULL;
    bstree->size = 0;
    /* 钩子函数在这赋值*/
    bstree->compareFunc = compareFunc;
#if 0
    /* 根结点分配空间 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);

    /* 初始化根结点 */
    bstree->root->data = 0;
    bstree->root->left = NULL;
    bstree->root->parent = NULL;
    bstree->root->right = NULL;
#endif

    bstree->root = createBSTreeNewNode(0, NULL);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    return ret;
}

/* 创建结点*/
static int createBSTreeNewNode(ELEMENTTPYE val, BSTreeNode *Parant)
{
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode) * 1);
    if (newBstNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newBstNode, 0, sizeof(BSTreeNode) * 1);

    /* 初始化新结点 */
    newBstNode->data = 0;
    newBstNode->left = NULL;
    newBstNode->parent = NULL;
    newBstNode->right = NULL;
}

/* 静态函数前置声明*/
static int compareFunc(ELEMENTTPYE val1, ELEMENTTPYE val2)
{
#if 0
    if(val1 < val2)
    {
        return -1;
    }
    else if (val1 > val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#endif

    return val1 - val2;
}

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTPYE val)

{
    int ret = 0;
    if (pBstree->size == 0)
    {
        (pBstree->size)++;

        pBstree->root->data = val;
        return ret = 0;
    }
    /* 新定义结点 指向根结点*/
    BSTreeNode *travelNode = pBstree->root;
    BSTreeNode *parentNode = pBstree->root;

    int cmp = 0;
    while (travelNode != NULL)
    {
        /* 标记父结点*/
        parentNode = travelNode;
        cmp = pBstree->compareFunc(val, travelNode->data);

        /* 插入元素 < 遍历的结点 往左走*/
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        /* 插入元素 >  遍历的结点 往右走*/
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 插入元素 = 遍历的结点 退出*/
            return ret;
        }
    }
#if 0

    /* 定义一个新结点*/
    BSTreeNode * newNode =(BSTreeNode *) malloc(sizeof(BSTreeNode) * 1);
      if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(BSTreeNode) * 1);
    newNode->data = 0;
    newNode->left = NULL;
    newNode->parent = NULL;
    newNode->right = NULL;
    newNode->data = val;
#endif
    BSTreeNode *newNode = createBSTreeNewNode(val, parentNode);

    /* 小于就左子树 */
    if (cmp < 0)
    {
        parentNode->left = newNode;
    }
    /* 大于就左子树 */
    else
    {
        parentNode->right = newNode;
    }
    /* 将父结点向新的结点移动*/
    newNode->parent = parentNode;

    (pBstree->size)++;
    return ret;
}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(binarySearchTree *pBstree)
{
    int ret = 0;
    return ret;
}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree *pBstree)
{
    int ret = 0;
    return ret;
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree *pBstree)
{
    int ret = 0;
    return ret;
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(binarySearchTree *pBstree)
{
    int ret = 0;

    doubleLinkListQueue *Queue = NULL;
    doubleLinkListQueueInit(&Queue);

    /* 根结点入队*/
    doubleLinkListQueuePush(Queue, pBstree->root);
    
    /* 判断队列是否为空*/
    BSTreeNode *nodeVal = NULL;
    while (doubleLinkListQueueIsEmpty(Queue))
    {
        doubleLinkListQueueTop(Queue, (void **)&nodeVal);
        printf("data:%d\n", nodeVal->data);
        doubleLinkListQueuePop(Queue);
        /* 判断左子树是否为空  不为空就将左子树入队*/
        if(nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(Queue, nodeVal->left);
        }
        /* 判断右子树是否为空  不为空就将右子树入队*/
        if(nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(Queue, nodeVal->right);
        }
    }
    doubleLinkListQueueDestroy(Queue);
    return ret;
}

/* 根据指定的值获取二叉搜索树里面的结点 */
static BSTreeNode *baseAppointValGetBSTreeNode(binarySearchTree *pBstree, ELEMENTTPYE val)
{
    BSTreeNode *travelNode = pBstree->root;
    int cmp = 0;
    while (travelNode != NULL)
    {
        /* 比较 */
        cmp = pBstree->compareFunc(val, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 找到相同的 */
            return travelNode;
        }
    }
    return NULL;
}

/* 二叉搜索树是否包含指定的元素*/
int binarySearchTreeIsContainAppointVal(binarySearchTree *pBstree, ELEMENTTPYE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}