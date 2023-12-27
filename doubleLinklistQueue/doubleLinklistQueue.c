#include "doubleLinklistQueue.h"

/*队列的初始化*/
int doubleLinkListQueueInit(doubleLinkListQueue **pQueue)
{
    return DoubleLinkListInit(pQueue);
}

/*入队*/
int doubleLinkListQueuePush(doubleLinkListQueue *pQueue, ELEMENTTPYE val)
{
    return DoubleLinkListTailInsert(pQueue, val);
}

/*查看队头元素*/
int doubleLinkListQueueTop(doubleLinkListQueue *pQueue, ELEMENTTPYE *pVal)
{
    return DoubleLinkListGetTopData(pQueue, pVal);
}

/*查看队尾元素*/
int doubleLinkListQueueRear(doubleLinkListQueue *pQueue, ELEMENTTPYE *pVal)
{
    return DoubleLinkListGetRearData(pQueue, pVal);
}

/*出队*/
int doubleLinkListQueuePop(doubleLinkListQueue *pQueue)
{
    return DoubleLinkListHeadDel(pQueue);
}

/*队列的大小*/
int doubleLinkListQueueGetSize(doubleLinkListQueue *pQueue, int *pSize)
{
    return DoubleLinkListGetLength(pQueue, pSize);
}

/*判断队列是否为空*/
int doubleLinkListQueueIsEmpty(doubleLinkListQueue *pQueue)
{
    int size = 0;
    DoubleLinkListGetLength(pQueue, &size);
    return size = 0 ? 1 : 0;
}

/*队列的销毁*/
int doubleLinkListQueueDestroy(doubleLinkListQueue *pQueue)
{
    return DoubleLinkListDestroy(pQueue);
}
