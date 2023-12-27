#ifndef __DOUBLELINKEDLIST_H_
#define __DOUBLELINKEDLIST_H_

#include "common.h"

//链表初始化
    int  DoubleLinkListInit(DoubleLinkList ** pList);

//链表头插
    int DoubleLinkListHeadInsert(DoubleLinkList * pList, ELEMENTTPYE val);

//链表尾插
    int DoubleLinkListTailInsert(DoubleLinkList * pList, ELEMENTTPYE val);

//链表指定位置插入
    int DoubleLinkListAppointPosInsert(DoubleLinkList * pList, int pos, ELEMENTTPYE val);

//链表的头删
    int DoubleLinkListHeadDel(DoubleLinkList * pList);

//链表的尾删
    int DoubleLinkListTailDel(DoubleLinkList * pList);

//链表的指定位置删除
    int DoubleLinkListAppintPosDel(DoubleLinkList * pList, int pos);

//链表删除指定数据
    int DoubleLinkListDelAppointData(DoubleLinkList * pList, ELEMENTTPYE val,  int ( *comparFunc)(ELEMENTTPYE, ELEMENTTPYE));

//获取链表的长度
    int DoubleLinkListGetLength(DoubleLinkList * pList, int *pSize);

// 链表的销毁
    int DoubleLinkListDestroy(DoubleLinkList * pList);

//链表的遍历 回调函数
    int linkedListForeach(DoubleLinkList * pList, int(*printFunc)(ELEMENTTPYE));
    
    //链表的遍历 int
    // int linkedListForeach(DoubleLinkList * pList);

//逆序打印 
    int DoubleLinkListReverForeach(DoubleLinkList *pList, int(*printFunc)(ELEMENTTPYE));

//获取指定位置的值
    int DoubleLinkListGetAppintPosdData(DoubleLinkList *pList, int pos, ELEMENTTPYE * pVal);

//获取 头的值
    int DoubleLinkListGetTopData(DoubleLinkList *pList, ELEMENTTPYE * pVal);

//获取尾的值
     int DoubleLinkListGetRearData(DoubleLinkList *pList, ELEMENTTPYE * pVal);


#endif
