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


} binarySearchTree;


/*二叉搜索树的初始化*/
int binarySearchTreeInit(binarySearchTree **pBstree);

/*二叉搜索树的插入*/
int binarySearchTreeInsert(binarySearchTree *pBstree, ELEMENTTPYE val, int( *compareFunc)(ELEMENTTPYE val1, ELEMENTTPYE val2));

/* 二叉搜索树是否包含指定的元素*/
int binarySearchTreeIsContainAppointVal(binarySearchTree *pBstree,ELEMENTTPYE val, int(*compareFunc )(ELEMENTTPYE val1, ELEMENTTPYE val2));

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(binarySearchTree *pBstree);

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(binarySearchTree *pBstree);

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(binarySearchTree *pBstree);

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(binarySearchTree *pBstree);



#endif