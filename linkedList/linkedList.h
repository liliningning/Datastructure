#ifndef __LINKEDLIST_H_
#define __LINKEDLIST_H_

#define ELEMENTTPYE int
// 链表结点
typedef struct LinkNode
{
    ELEMENTTPYE data;
    // 指向下一个结点的指针
    struct LinkNode *next;
} LinkNode;

// 链表
typedef struct LinkList
{   // 链表的虚拟头结点
    LinkNode * head;
    //链表长度
    int len;
}LinkList;

//链表初始化
    int  LinkListInit(LinkList ** pList);

//链表头插
    int LinkListHeadInsert(LinkList * pList, ELEMENTTPYE val);

//链表尾插
    int LinkListTailInsert(LinkList * pList, ELEMENTTPYE val);

//链表指定位置插入
    int LinkListAppointPosInsert(LinkList * pList, int pos, ELEMENTTPYE val);

//链表的头删
    int LinkListHeadDel(LinkList * pList);

//链表的尾删
    int LinkListTailDel(LinkList * pList);

//链表的指定位置删除
    int LinkListAppintPosDel(LinkList * pList, int pos);

//链表删除指定数据
    int LinkListDelAppointData(LinkList * pList, ELEMENTTPYE val);

//获取链表的长度
    int LinkListGetLength(LinkList * pList, int *pSize);

// 链表的销毁
    int LinkListDestroy(LinkList * pList);



#endif
