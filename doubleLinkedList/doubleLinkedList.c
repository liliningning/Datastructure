#include "doubleLinkedList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 状态码
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,

};

// 静态函数的声明 找到要删除元素的位置
static int linkedListAccordAppointVal(DoubleLinkList *pList, ELEMENTTPYE val, int *pPos, int (*comparFunc)(ELEMENTTPYE, ELEMENTTPYE));

// 静态函数的声明  将结点封装为函数
static DoubleLinkNode *createDoubleLinkNode(ELEMENTTPYE val);

// 链表初始化
int DoubleLinkListInit(DoubleLinkList **pList)
{
    int ret = 0;
    // 链表开辟空间
    DoubleLinkList *list = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清楚脏数据
    memset(list, 0, sizeof(DoubleLinkList) * 1);
    // 头结点开辟空间
    list->head = malloc(sizeof(DoubleLinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清楚脏数据
    memset(list->head, 0, sizeof(DoubleLinkNode) * 1);
    list->head->data = 0;
    list->head->next = NULL;
    // 前指针为null
    list->head->prev = NULL;

    // 初始化时尾指针等于头指针
    list->tail = list->head;

    // 链表长度为0
    list->len = 0;

    // 二级指针
    *pList = list;
    return ret;
}

// 链表头插
int DoubleLinkListHeadInsert(DoubleLinkList *pList, ELEMENTTPYE val)
{
    return DoubleLinkListAppointPosInsert(pList, 0, val);
}

// 链表尾插
int DoubleLinkListTailInsert(DoubleLinkList *pList, ELEMENTTPYE val)
{
    return DoubleLinkListAppointPosInsert(pList, pList->len, val);
}

//将结点封装为函数
static DoubleLinkNode *createDoubleLinkNode(ELEMENTTPYE val)
{
    DoubleLinkNode *newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(DoubleLinkNode) * 1);
    // 赋值
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->data = val;
    return newNode;
}

// 链表指定位置插入
int DoubleLinkListAppointPosInsert(DoubleLinkList *pList, int pos, ELEMENTTPYE val)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    // 新建新结点 封装为函数
    DoubleLinkNode *newNode = createDoubleLinkNode(val);
#if 0
    // 封装结点
    DoubleLinkNode *newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(DoubleLinkNode) * 1);
    // 赋值
    newNode->data = val;
#endif
#if 1
    // 从虚拟头结点开始
    DoubleLinkNode *travelNode = pList->head;
#else
    DoubleLinkNode *travelNode = pList->head->next;
#endif
    int flag = 0;
    // 这种情况需要改尾指针  链表为空 头插等于尾插
    if (pos == pList->len)
    {
        travelNode = pList->tail;
        flag = 1;
    }
    else
    {
        while (pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
        travelNode->next->prev = newNode;
    }
    newNode->next = travelNode->next;
    newNode->prev = travelNode;
    travelNode->next = newNode;

    if (flag == 1)
    {
        pList->tail = newNode;
    }
    // 更新链表长度
    (pList->len)++;
    return ret;
}

// 链表的头删
int DoubleLinkListHeadDel(DoubleLinkList *pList)
{
    return DoubleLinkListAppintPosDel(pList, 1);
}

// 链表的尾删
int DoubleLinkListTailDel(DoubleLinkList *pList)
{
    DoubleLinkListAppintPosDel(pList, pList->len);
}

// 链表的指定位置删除
int DoubleLinkListAppintPosDel(DoubleLinkList *pList, int pos)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
    DoubleLinkNode *trvaelNode = pList->head;
    DoubleLinkNode *needNode = NULL;
    if (pos = pList->len)
    {
        DoubleLinkNode *temNode = pList->tail;
        pList->tail = pList->tail->prev;
        needNode = temNode;
    }
    // DoubleLinkNode * trvaelNode = pList->head->next;
    while (--pos)
    {
        // 后移
        trvaelNode = trvaelNode->next;
        // pos--;
    }

    // needNode 需要删除的结点
    needNode = trvaelNode->next;
    trvaelNode->next = needNode->next;
    needNode->next->prev = trvaelNode;
    // trvaelNode->next = trvaelNode->next->next

    // 调整尾指针
    // 释放内存
    if (needNode != NULL)
    {
        free(needNode);
        needNode = NULL;
    }
    (pList->len)--;
    return ON_SUCCESS;
}

// 静态函数只给本源文件自己使用 不需要判断合法性
static int linkedListAccordAppointVal(DoubleLinkList *pList, ELEMENTTPYE val, int *pPos, int (*comparFunc)(ELEMENTTPYE, ELEMENTTPYE))
{
    int pos = 1;
#if 0
    DoubleLinkNode *trvaelNode = pList->head;
#else

    DoubleLinkNode *trvaelNode = pList->head->next;
#endif
    int cmp = 0;
    while (trvaelNode != NULL)
    {
#if 0
        if (trvaelNode->data == val)
        {
            *pPos =pos;
            return pos;
        }
#else
        cmp = comparFunc(val, trvaelNode->data);
        if (cmp == 0)
        {
            *pPos = pos;
            return pos;
        }
#endif
        trvaelNode = trvaelNode->next;
        pos++;
    }
    *pPos = NOT_FIND;
    return NOT_FIND;
}

// 链表删除指定数据
int DoubleLinkListDelAppointData(DoubleLinkList *pList, ELEMENTTPYE val, int (*comparFunc)(ELEMENTTPYE, ELEMENTTPYE))
{
    int pos = 0;
    int ret = 0;
    int size = 0;
    while (DoubleLinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        // 找到数据所在的位置
        linkedListAccordAppointVal(pList, val, &pos, comparFunc);
        // 指定位置删除
        DoubleLinkListAppintPosDel(pList, pos);
    }
    return ret;
}

// 获取链表的长度
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }
    if (pSize)
    {
        *pSize = pList->len;
    }
    return pList->len;
}

// 链表的销毁
int DoubleLinkListDestroy(DoubleLinkList *pList)
{ // 使用头删 释放链表
    int size = 0;
    while (DoubleLinkListGetLength(pList, &size))
    {
        DoubleLinkListHeadDel(pList);
    }

    if (pList->head != NULL)
    {
        free(pList->head);
        pList->head = NULL;
        pList->tail = NULL;
    }
}

// 链表的遍历
int linkedListForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTPYE))
// int linkedListForeach(DoubleLinkList *pList)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    //从头结点开始 travelNode 指向头结点
    DoubleLinkNode *travelNode = pList->head;
    while (travelNode->next  != NULL)
    {
        travelNode = travelNode->next;
        prinf("travelNode->data %d\t",travelNode->data); 
    }

#else

    // 从头结点开始
    DoubleLinkNode *travelNode = pList->head;

    // 从链表第一个结点开始（travelNode 指向第一个结点）
    // DoubleLinkNode *travelNode = pList->head->next;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
#if 0
        printf("travelNode->data %d\n", travelNode->data);
        // travelNode = travelNode->next;
#else
        // 包装器 回调函数
        //  调用这个函数
        printFunc(travelNode->data);
#endif
    }
#endif
    return ret;
}

// 逆序打印
int DoubleLinkListReverForeach(DoubleLinkList *pList, int (*printFunc)(ELEMENTTPYE))
{
    pList->tail = pList->len;
    DoubleLinkNode *travelNode = pList->tail;

    while (travelNode != pList->head)
    {
        printFunc(travelNode->data);
        travelNode = travelNode->prev;
    }

    return ON_SUCCESS;
}
