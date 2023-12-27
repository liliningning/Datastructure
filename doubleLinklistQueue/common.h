#ifndef __COMMON_H_
#define __COMMON_H_

//  #define ELEMENTTPYE int
#define ELEMENTTPYE void*

// 链表结点
typedef struct DoubleLinkNode
{
    ELEMENTTPYE data;
    // 指向下一个结点的指针
    struct DoubleLinkNode *next;
    //指向前一个结点
    struct DoubleLinkNode *prev;
} DoubleLinkNode;

// 链表
typedef struct DoubleLinkList
{   // 链表的虚拟头结点
    DoubleLinkNode * head;
    //尾指针
    DoubleLinkNode * tail;  //为什么尾指针不需要分配空间？
    //链表长度
    int len;

} DoubleLinkList;

#endif