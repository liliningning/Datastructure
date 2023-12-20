#include "linkedList.h"
#include <stdlib.h>
#include <string.h>


// 状态码
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,

};


//链表初始化
    int  LinkListInit(LinkList ** pList)
    {
        int ret = 0;
        //链表开辟空间
        LinkList * list =(ELEMENTTPYE *) malloc(sizeof(LinkList) * 1);
        if(list == NULL)
        {
            return MALLOC_ERROR;
        }
        //清楚脏数据 
        memset(list, 0, sizeof(LinkList) * 1);
        //头结点开辟空间
        list->head = (ELEMENTTPYE *) malloc(sizeof(LinkNode) * 1);
         if(list->head == NULL)
        {
            return MALLOC_ERROR;
        }
        //清楚脏数据 
         memset(list->head, 0, sizeof(LinkNode) * 1);
         list->head->data = 0;
         list->head->next = NULL;

        //链表长度为0
        list->len = 0;

        //二级指针
        *pList = list;
        return ret;



    }

//链表头插
    int LinkListHeadInsert(LinkList * pList, ELEMENTTPYE val)
    {

    }

//链表尾插
    int LinkListTailInsert(LinkList * pList, ELEMENTTPYE val)
    {

    }

//链表指定位置插入
    int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTPYE val)
    {

    }

//链表的头删
    int LinkListHeadDel(LinkList * pList)
    {

    }

//链表的尾删
    int LinkListTailDel(LinkList * pList)
    {

    }

//链表的指定位置删除
    int LinkListAppintPosDel(LinkList * pList, int pos)
    {

    }

//链表删除指定数据
    int LinkListDelAppointData(LinkList * pList, ELEMENTTPYE val)
    {

    }

//获取链表的长度
    int LinkListGetLength(LinkList * pList, int *pSize)
    {

    }

// 链表的销毁
    int LinkListDestroy(LinkList * pList)
    {

    }

//链表的遍历
    int linkedListForeach(LinkList * pList)
    {

    }
