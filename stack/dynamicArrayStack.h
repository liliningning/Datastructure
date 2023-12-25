#ifndef __DYNAMIC_ARRAY_STACK_H
#define __DYNAMIC_ARRAY_STACK_H

/* 栈的初始化*/
int dynamicArrayStackInit();

/*压栈*/
int dynamicArrayStackPush();

/*查看栈顶元素*/
int dynamicArrayStacKTop();

/*出栈*/
int dynamicArrayStackPop();

/*获得栈的大小*/
    int dynamicArrayStackSize();

/*栈的销毁*/
    int dynamicArrayStackDestroy();

/*判断栈是否为空*/
    int  dynamicArrayStackIsEmply();


#endif