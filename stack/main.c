#include "dynamicArrayStack.h"
#include <stdio.h>
#include "commom.h"
#define BUFFER_SIZE 5

int main()
{
    dynamicArrayStack stack;

    dynamicArrayStackInit(&stack);

    int buffer[BUFFER_SIZE]= {5, 12, 34, 56, 87};
    for(int idx = 1; idx <= BUFFER_SIZE; idx++)
    {
        dynamicArrayStackPush(&stack, &buffer[idx]);
    }

    /*获取栈的大小*/
    int size = 0;
    dynamicArrayStackGetSize(&stack, &size);
    printf("size: %d\n", size);

    int *val = NULL;
    while (!dynamicArrayStackIsEmply(&stack))
    {
       dynamicArrayStacKTop(&stack, (void**)&val);
       printf("val:%d\n",*val);
       dynamicArrayStackPop(&stack);
    }

     /*栈的销毁*/
    dynamicArrayStackDestroy(&stack);


    return 0;
}