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
    ELEMENTTPYE len;
}LinkList;

//链表初始化
    int  LinkListInit();

//链表头插
    int LinkListHeadInsert();

//链表尾插
    int LinkListTailInsert();

//链表指定位置插入
    int LinkListAppointPosInsert();

//链表的头删
    int LinkListHeadDel();

//链表的尾删
    int LinkListTailDel();

//链表的指定位置删除
    int LinkListAppintPosDel();

//删除指定元素
    int LinkListDelAppointData();

//获取链表的长度
    int LinkListGetLength();

// 链表的销毁
    int LinkListDestroy();



#endif
