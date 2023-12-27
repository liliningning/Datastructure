#ifndef __DOUBLE_LINKLIST_QUENU_H_
#define __DOUBLE_LINKLIST_QUENU_H_

#include "common.h"

typedef DoubleLinkList doubleLinkListQueue;

/*队列的初始化*/
int  doubleLinkListQueueInit(doubleLinkListQueue ** pQueue);

/*入队*/
int  doubleLinkListQueuePush(doubleLinkListQueue * pQueue,  ELEMENTTPYE val);


/*查看队头元素*/
int  doubleLinkListQueueTop(doubleLinkListQueue * pQueue,ELEMENTTPYE * pVal);

/*查看队尾元素*/
int  doubleLinkListQueueRear(doubleLinkListQueue * pQueue,ELEMENTTPYE * pVal);

/*出队*/
int  doubleLinkListQueuePop(doubleLinkListQueue * pQueue);

/*队列的大小*/
int  doubleLinkListQueueGetSize(doubleLinkListQueue * pQueue, int *pSize);

/*判断队列是否为空*/
int  doubleLinkListQueueIsEmpty(doubleLinkListQueue * pQueue);

/*队列的销毁*/
int  doubleLinkListQueueDestroy(doubleLinkListQueue * pQueue);

#endif