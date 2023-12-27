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
static BSTreeNode *baseAppointValGetBSTreeNode(binarySearchTree *pBstree, ELEMENTTPYE val);

/* 判断二叉搜索树的度为2 */
static int binarySearchTreeNodeTwochildrens(BSTreeNode *node);

/* 判断二叉搜索树的度为1 */
static int binarySearchTreeNodeOnechildrens(BSTreeNode *node);

/* 判断二叉搜索树的度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node);

/* 前序遍历 */
static int preOrderTravel(binarySearchTree *pBstree, BSTreeNode *node);

/* 中序遍历 */
static int inOrderTravel(binarySearchTree *pBstree, BSTreeNode *node);

/* 后序遍历 */
static int posteOrderTrave(binarySearchTree *pBstree, BSTreeNode *node);

/* 获得当前结点的前驱结点 */
static BSTreeNode *bstreeNodepreDecessor(BSTreeNode *node);

/* 获得当前结点的后继结点 */
static BSTreeNode *bstreeNodeSuccessor(BSTreeNode *node);

/* 二叉搜索树删除指定的结点 */
static int binarySearchTreeDeleteNode(binarySearchTree *pBstree, BSTreeNode *node);

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(binarySearchTree **pBstree, int (*compareFunc)(ELEMENTTPYE val1, ELEMENTTPYE val2), int (*printFunc)(ELEMENTTPYE val))
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
    /* 钩子函数在这赋值 */
    bstree->compareFunc = compareFunc;
    /* 钩子函数的包装器 */
    bstree->printFunc = printFunc;

    doubleLinkListQueueInit(&(bstree->queue));
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
    /* 是为了travelNode和parantNode 的移动 */
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
    /*  赋值 判断新的结点是parantNode的左子树 还是右子树 */
    BSTreeNode *newNode = createBSTreeNewNode(val, parentNode);

    /* 小于就左子树 */
    if (cmp < 0)
    {
        parentNode->left = newNode;
    }
    /* 大于就右子树 */
    else
    {
        parentNode->right = newNode;
    }
    /* 将父结点向新的结点移动*/
    newNode->parent = parentNode;

    (pBstree->size)++;
    return ret;
}

/* 判断二叉搜索树的度为2 */
static int binarySearchTreeNodeTwochildrens(BSTreeNode *node)
{
    return (node->left != NULL) && (node->right != NULL);
}

/* 判断二叉搜索树的度为1 */
static int binarySearchTreeNodeOnechildrens(BSTreeNode *node)
{
    return ((node->left != NULL) && (node->right == NULL)) || ((node->right != NULL) && (node->left == NULL));
}

/* 判断二叉搜索树的度为0 */
static int binarySearchTreeNodeIsLeaf(BSTreeNode *node)
{
    return (node->left == NULL) && (node->right == NULL);
}

/* 获得当前结点的前驱结点 */
static BSTreeNode *bstreeNodepreDecessor(BSTreeNode *node)
{
    /*  如果当前结点的左子树不为空 当前结点的前驱结点在 左右右 */
    if (node->left != NULL)
    {
        BSTreeNode *travelNode = node->left;
        while (travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }
    /* 程序到这里一定说明当前结点没有左子树 就往其父结点寻找 直到找到当前结点是其父结点的右子树 */
    while (node->parent != NULL && node == node->parent->left)
    {
        node = node->parent;
    }
    return node->parent;
}

/* 获得当前结点的后继结点 */
static BSTreeNode *bstreeNodeSuccessor(BSTreeNode *node)
{
    /*  如果当前结点的右子树不为空 当前结点的后继结点在 右左左 */
    if (node->right != NULL)
    {
        BSTreeNode *travelNode = node->right;
        while (travelNode->left != NULL)
        {
            travelNode = travelNode->left;
        }
        return travelNode;
    }
    /* 程序到这里一定说明当前结点没有右子树 就往其父结点寻找 直到找到当前结点是其父结点的左子树 */
    while (node->parent != NULL && node == node->parent->right)
    {
        node = node->parent;
    }
    return node->parent;
}

/* 前序遍历 根左右 */
static int preOrderTravel(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }

    /* 打印根结点*/
    pBstree->printFunc(node->data);
    /* 左 */
    preOrderTravel(pBstree, node->left);
    /* 右 */
    preOrderTravel(pBstree, node->right);
}

/* 中序遍历 左根右 */
static int inOrderTravel(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 左 */
    inOrderTravel(pBstree, node->left);
    /* 打印根结点*/
    pBstree->printFunc(node->data);
    /* 右 */
    inOrderTravel(pBstree, node->right);
}

/* 后序遍历 左右根 */
static int posteOrderTravel(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }
    /* 左 */
    postOrderTravel(pBstree, node->left);
    /* 右 */
    posttOrderTravel(pBstree, node->right);
    /* 打印根结点*/
    pBstree->printFunc(node->data);
}
/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(binarySearchTree *pBstree)
{
    int ret = 0;
    preOrderTravel(pBstree, pBstree->root);
    return ret;
}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree *pBstree)
{
    int ret = 0;
    inOrderTravel(pBstree, pBstree->root);
    return ret;
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree *pBstree)
{
    int ret = 0;
    posteOrderTravel(pBstree, pBstree->root);
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
    BSTreeNode *popnodeVal = NULL;

    while (!doubleLinkListQueueIsEmpty(Queue))
    {
        doubleLinkListQueueTop(Queue, (void **)&popnodeVal);
#if 0
        printf("data:%d\n", nodeVal->data);
#endif

        pBstree->printFunc(popnodeVal->data);

        doubleLinkListQueuePop(Queue);

        /* 判断左子树是否为空  不为空就将左子树入队*/
        if (nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(Queue, popnodeVal->left);
        }
        /* 判断右子树是否为空  不为空就将右子树入队*/
        if (nodeVal->right != NULL)
        {
            doubleLinkListQueuePush(Queue, popnodeVal->right);
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

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(binarySearchTree *pBstree, int *pHeight)
{
    /* 如果树为空则返回高度为0 */
    if (pBstree == NULL)
    {
        return 0;
    }
    int height = 0; /* 树的高度 */
    int count = 1;  /* 记录每一层的结点数 */
    /* 初始化队列 */
    doubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(&queue);
    /* 根结点入队 */
    doubleLinkListQueuePush(queue, pBstree->root);
    BSTreeNode *newNode = NULL;
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&newNode);

        doubleLinkListQueuePop(queue);

        /* 当前层的结点数 */
        count--;
        /* 判断左子树是否为空 不为空入队 */
        if (newNode->left != NULL)
        {
            doubleLinkListQueuePush(queue, newNode->left);
        }
        /* 判断右子树是否为空 不为空入队 */
        if (newNode->right != NULL)
        {
            doubleLinkListQueuePush(queue, newNode->right);
        }
        /* 队列的大小 */
        int size = 0;
        if (count == 0)
        {
            height++;
            count = doubleLinkListQueueGetSize(queue, &size);
        }
    }
    if (pHeight)
    {
        *pHeight = height;
    }
    return height;
    /* 释放空间 */
    doubleLinkListQueueDestroy(queue);
}

static int binarySearchTreeDeleteNode(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if (node == NULL)
    {
        return ret;
    }

    (pBstree->size)--;
    if (binarySearchTreeNodeTwochildrens(node))
    {

        BSTreeNode *newNode  = bstreeNodepreDecessor(node);
        node->data = newNode->data;
        node = newNode;
    }
#if 0
    if (binarySearchTreeNodeOnechildrens(node))
    {
        newChildNode->parent = node->parent;

   }
#else
    /* 判断 删除结点的孩子是 它的左子树 还是右子树 */
    BSTreeNode *childNode = node->left != NULL ? node->left : node->right;

    if (childNode)
    {
        /* 度为1 */
        childNode->parent = node->parent;
        /* 说明该结点是根结点*/
        if (node->parent == NULL)
        {
            pBstree->root = childNode;
            if (node)
            {
                free(node)
                node = NULL;
            }
        }
        /* 判断该结点是父结点的左子树还是右子树 */
        else
        {
            if (node == node->parent->left)
            {
                childNode = node->parent->left;
            }
            else
            {
                childNode = node->parent->right;
            }
            if (node)
            {
                free(node)
                node = NULL;
            }
        }
    }
    else
    {
        /* 度为0 直接将其释放掉 */
        if(node)
        {
            free(node)
            node = NULL;
        }

    }

#endif
}

/* 二叉搜索树的删除（删除的是值）*/
int binarySearchTreeDelete(binarySearchTree *pBstree)
{
    int ret = 0;
#if 0
   BSTreeNode * delNode = baseAppointValGetBSTreeNode(pBstree, val);
   return binarySearchTreeDeleteNode(pBstree, delNode);
#else
    return binarySearchTreeDeleteNode(pBstree, baseAppointValGetBSTreeNode(pBstree, val));

#endif
    return ret;
}

/* 二叉搜索树的销毁 */
int binarySearchTreeDestory(binarySearchTree *pBstree)
{
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }
    doubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(&queue);

    /* 根结点入队 */
    doubleLinkListQueuePush(queue, pBstree->root);

    BSTreeNode *newNode = NULL;
    while (!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&newNode);

        doubleLinkListQueuePop(queue);

        /* 判断左子树是否为空 不为空入队 */
        if (newNode->left != NULL)
        {
            doubleLinkListQueuePush(queue, newNode->left);
        }
        /* 判断右子树是否为空 不为空入队 */
        if (newNode->right != NULL)
        {
            doubleLinkListQueuePush(queue, newNode->right);
        }
        if (newNode)
        {
            free(newNode);
            newNode = NULL;
        }
        if (pBstree)
        {
            free(pBstree);
            pBstree = NULL;
        }
    }
    doubleLinkListQueueDestroy(queue);
}