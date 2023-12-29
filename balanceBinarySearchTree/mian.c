#include <stdio.h>
#include "binarySearchTree.h"
#define BUFFER_SIZE 5

int compareBasicDataFunc(void *agr1, void *agr2)
{
    int val1 = *(int *)agr1;
    int val2 = *(int *)agr2;

    return val1 - val2;
}

int printFunc(void *arg)
{
    int ret = 0;
    int val = *(int *)arg;
    printf("val:%d\n", val);

    return ret;
}

int main()
{
    /**/
    binarySearchTree *BST;
    binarySearchTreeInit(&BST, compareBasicDataFunc, printFunc);
    int buffer[BUFFER_SIZE] = {56, 28, 75, 73, 77};
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        binarySearchTreeInsert(BST, (void *)&buffer[idx]);
    }
    
    /* 高度 */
    int height = 0;
    binarySearchTreeGetHeight(BST, &height);
    printf("height:%d\n",height);

    /* 结点数*/
    int size = 0;
    binarySearchTreeGetNode(BST, &size);
    printf("size:%d\n",size);




        return 0;
}