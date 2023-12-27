#include "doubleLinklistQueue.h"
#include <stdio.h>
#define BUFFER_SIZE 4

int main()
{
    doubleLinkListQueue * queue = NULL;
    doubleLinkListQueueInit(&queue);

   int  buffer[BUFFER_SIZE] = {111, 222, 333, 444};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListQueuePush(queue,(void *)buffer[idx]);
    }

    int size = 0;
    doubleLinkListQueueGetSize(queue, &size);
    printf("size:%d\n", size);
   

    // int *val = NULL;
    // while (!doubleLinkListQueueIsEmpty(queue))
    // {
    //    doubleLinkListQueueTop(queue, (void**)&val);
    //    printf("val:%d\n",*val);
    //    doubleLinkListQueuePop(queue);
    // }

    //  /*栈的销毁*/
    // doubleLinkListQueueDestroy(queue);


    return 0;

    return 0;
}