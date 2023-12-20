#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

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
static int linkedListAccordAppointVal(LinkList *pList, ELEMENTTPYE val, int *pPos);

// 链表初始化
int LinkListInit(LinkList **pList)
{
    int ret = 0;
    // 链表开辟空间
    LinkList *list = (ELEMENTTPYE *)malloc(sizeof(LinkList) * 1);
    if (list == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清楚脏数据
    memset(list, 0, sizeof(LinkList) * 1);
    // 头结点开辟空间
    list->head = (ELEMENTTPYE *)malloc(sizeof(LinkNode) * 1);
    if (list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    // 清楚脏数据
    memset(list->head, 0, sizeof(LinkNode) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    // 初始化时尾指针等于头指针
    list->tail = list->head;

    // 链表长度为0
    list->len = 0;

    // 二级指针
    *pList = list;
    return ret;
}

// 链表头插
int LinkListHeadInsert(LinkList *pList, ELEMENTTPYE val)
{
    return reLinkListAppointPosInsert(pList, 0, val);
}

// 链表尾插
int LinkListTailInsert(LinkList *pList, ELEMENTTPYE val)
{
    return reLinkListAppointPosInsert(pList, len, val);
}

// 链表指定位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTPYE val)
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

    // 封装结点
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if (newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(LinkNode) * 1);
    // 赋值
    newNode->data = val;
#if 1
    // 从虚拟头结点开始
    LinkNode *travelNode = pList->head;
#else
    LinkNode *travelNode = pList->head->next;
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
    }
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    if (flag = 0)
    {
        pList->tail = newNode;
    }
    // 更新链表长度
    (pList->len)++;
    return ret;
}

// 链表的头删
int LinkListHeadDel(LinkList *pList)
{
    return LinkListAppintPosDel(pList, 1);
}

// 链表的尾删
int LinkListTailDel(LinkList *pList)
{
    LinkListAppintPosDel(pList, pList->len);
}

// 链表的指定位置删除
int LinkListAppintPosDel(LinkList *pList, int pos)
{
    if (pList == NULL)
    {
        return NULL_PTR;
    }

    if (pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    int flag = 0;
    if (pos = pList->len)
    {
        flag = 1;
    }

    LinkNode *trvaelNode = pList->head;
    // LinkNode * trvaelNode = pList->head->next;
    while (--pos)
    {
        // 后移
        trvaelNode = trvaelNode->next;
        // pos--;
    }
    // needNode 需要删除的结点
    LinkNode *needNode = trvaelNode->next;
    trvaelNode->next = needNode->next;
    // trvaelNode->next = trvaelNode->next->next

    // 调整尾指针
    if (flag = 1)
    {
        pList->tail = trvaelNode;
    }
    // 释放内存
    if (needNode != NULL)
    {
        free(needNode);
        needNode = NULL;
    }
    pList->len--;
    return ON_SUCCESS;
}

// 静态函数只给本源文件自己使用 不需要判断合法性
static int linkedListAccordAppointVal(LinkList *pList, ELEMENTTPYE val, int *pPos)
{
    int ret;
#if 1
    LinkList *trvaelNode = pList->head;
#else
    int pos = 1;
    LinkList *trvaelNode = pList->head->next;
#endif
    while (trvaelNode != NULL)
    {
        if (trvaelNode->data == val)
        {
            *pPos = pos;
            return pos;
        }
        trvaelNode = trvaelNode->next;
        pos++;
    }
    return NOT_FIND;
}

// 链表删除指定数据
int LinkListDelAppointData(LinkList *pList, ELEMENTTPYE val)
{
    int pos = 0;
    int ret = 0;
    int size = 0;
    while (LinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        // 找到数据所在的位置
        linkedListAccordAppointVal(pList, val, &pos);
        // 指定位置删除
        LinkListAppintPosDel(pList, pos);
        LinkListAppintPosDel()
    }
    return ret;
}

// 获取链表的长度
int LinkListGetLength(LinkList *pList, int *pSize)
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
int LinkListDestroy(LinkList *pList)
{ // 使用头删 释放链表
    int size = 0;
    while (LinkListGetLength(pList, size))
    {
        LinkListHeadDel(pList);
    }

    if (pList->head != NULL)
    {
        free(pList->head);
        pList.head = NULL;
        pList->tail = NULL;
    }
}

// 链表的遍历
int linkedListForeach(LinkList *pList)
{
    int ret = 0;
    if (pList == NULL)
    {
        return NULL_PTR;
    }

#if 0
    //从头结点开始 travelNode 指向头结点
    LinkNode *travelNode = pList->head;
    while (travelNode->next  != NULL)
    {
        travelNode = travelNode->next;
        prinf("travelNode->data %d\t",travelNode->data); 
    }

#else
    // 从链表第一个结点开始（travelNode 指向第一个结点）
    LinkNode *travelNode = pList->head->next;
    while (travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        prinf("travelNode->data %d\t", travelNode->data);
        travelNode = travelNode->next
    }
#endif
    return ret;
}
