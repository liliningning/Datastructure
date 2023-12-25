#ifndef __DYNAMIC_ARRAY_STACK_H
#define __DYNAMIC_ARRAY_STACK_H


/*调用动态数组的文件*/
// #include "dynamicArray.h" 
#include "commom.h"

typedef dynamicArray dynamicArrayStack;


/* 栈的初始化*/
int dynamicArrayStackInit(dynamicArrayStack * pStack);

/*压栈*/
int dynamicArrayStackPush(dynamicArrayStack * pStack, ELEMENTTYPE val);

/*查看栈顶元素*/
int dynamicArrayStacKTop(dynamicArrayStack * pStack, ELEMENTTYPE *pVal );

/*出栈*/
int dynamicArrayStackPop(dynamicArrayStack * pStack);

/*获得栈的大小*/
int dynamicArrayStackGetSize(dynamicArrayStack * pStack, int *pSize);

/*栈的销毁*/
int dynamicArrayStackDestroy(dynamicArrayStack * pStack);

/*判断栈是否为空*/
int dynamicArrayStackIsEmply(dynamicArrayStack * pStack);

#endif