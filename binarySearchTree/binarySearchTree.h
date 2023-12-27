#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#define ELEMENTTPYE int


typedef struct BSTreeNode
{
    ELEMENTTPYE data;
    struct BSTreeNode * left;       /* 左子树 */
    struct BSTreeNode * right;      /* 右子树 */
    struct BSTreeNode * parent;     /* 父结点 */

} BSTreeNode;

typedef struct binarySearchTree
{   
    BSTreeNode * root;      /*根结点*/
    int size;               /*树的结点个数*/

    /* 钩子函数比较器  */
    int(*compareFunc )(ELEMENTTPYE val1, ELEMENTTPYE val2);

    /* 钩子函数 包装器  实现自定义打印函数接口 */
    int (* printFunc)(ELEMENTTPYE val);

} binarySearchTree;


/*二叉搜索树的初始化*/
int binarySearchTreeInit(binarySearchTree **pBstree,  int(*compareFunc )(ELEMENTTPYE val1, ELEMENTTPYE val2), int (* printFunc)(ELEMENTTPYE val));

/*二叉搜索树的插入*/
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTPYE val);

/* 二叉搜索树是否包含指定的元素*/
int binarySearchTreeIsContainAppointVal(binarySearchTree *pBstree, ELEMENTTPYE val);

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(binarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree *pBstree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(binarySearchTree *pBstree);

/* 获取二叉搜索树的高度 */
int binarySearchTreeGetHeight(binarySearchTree *pBstree, int *pHeight);

/* 二叉搜索树的删除（删除的是值）*/
int binarySearchTreeDelete(binarySearchTree *pBstree);

#endif