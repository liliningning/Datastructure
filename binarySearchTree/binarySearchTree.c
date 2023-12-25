#include "binarySearchTree.h"
#include <stdlib.h>
#include <string.h>

enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,

};

static int compareFunc( ELEMENTTPYE val1,ELEMENTTPYE val2)
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




/* 二叉搜索树的初始化 */
int binarySearchTreeInit(binarySearchTree **pBstree)
{
    int ret = 0;
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

    return ret;
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
    cmp = compareFunc(val, travelNode->data);

    while (travelNode != NULL)
    {
        /* 标记父结点*/
        parentNode = travelNode;

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

    /* 新结点赋值 */
    newNode->data = val;

    /* 小于就左子树 */
    if(cmp < 0)
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

    return ret;
}