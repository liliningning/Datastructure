#include "dynamicArrayStack.h"
#include "dynamicArray.h"

#define DEFAULT_SIZE 10

/* 栈的初始化*/
int dynamicArrayStackInit(dynamicArrayStack *pStack)
{
    return dynamicArrayInit(pStack, DEFAULT_SIZE);
}

/*压栈*/
int dynamicArrayStackPush(dynamicArrayStack *pStack, ELEMENTTYPE val)
{
    /*调用动态数组的尾插*/
    return dynamicArrayInsertData(pStack, val);
}

/*查看栈顶元素*/
int dynamicArrayStacKTop(dynamicArrayStack *pStack, ELEMENTTYPE *pVal)
{
    /*调用动态数组的指定位置获取数据接口*/
    return dynamicArrayGetAppointPosVal(pStack, pStack->len - 1 , pVal);
}

/*出栈*/
int dynamicArrayStackPop(dynamicArrayStack *pStack)
{
    return dynamicArrayDeleteData(pStack);
}

/*获得栈的大小*/
int dynamicArrayStackGetSize(dynamicArrayStack *pStack, int *pSize)
{
    #if 1
    return dynamicArrayGetSize(pStack, pSize);
    #else
    if(pSize)
    {
        return *pSize;
    }
    #endif
}

    /*栈的销毁*/
    int dynamicArrayStackDestroy(dynamicArrayStack *pStack)
    {
        /*调用动态数组的销毁*/
        return dynamicArrayDestroy(pStack);
    }

    /*判断栈是否为空*/
    int dynamicArrayStackIsEmply(dynamicArrayStack *pStack)
    {
        int size = 0;
        dynamicArrayGetSize(pStack, &size);
        return size = 0 ? 1 : 0;

    }