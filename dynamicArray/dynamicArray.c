#include "dynamicArray.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEFAULT_SIZE 10
//状态码

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,

};


//动态数组扩容 静态函数前置声明 只能在这个文件里面使用

static expandDynamicCapacity(dynamicArray * pArray);

//动态数组扩容 静态函数前置声明 只能在这个文件里面使用
static shrinkDynamicCapacity(dynamicArray * pArray);


//动态数组的初始化
    int dynamicArrayInit(dynamicArray *pArray , int capacity)
    {
        if(pArray == NULL)
        {
            return NULL_PTR;
        }

       //避免传入非法值
        if(capacity < 0)
        {

            capacity = DEFAULT_SIZE;
        }
        //分配空间
        pArray->data =(ELEMENTTYPE * ) malloc(sizeof(ELEMENTTYPE) * capacity);
        if (pArray->capacity == NULL)
        {
          return MALLOC_ERROR;
        }
        //初始化  定义的空间 大小 数量
        memset(pArray->data,0,sizeof(ELEMENTTYPE) * capacity);
        pArray->len = 0;
        pArray->capacity = capacity;
        return ON_SUCCESS;

    }

//动态数组扩容
static expandDynamicCapacity(dynamicArray * pArray)
{
    int ret = 0;

    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);

    //备份指针 防止原始数据丢失
    ELEMENTTYPE * temPtr = pArray->data;
   pArray->data=(ELEMENTTYPE *)  malloc(sizeof(ELEMENTTYPE) * needExpandCapacity);
   // 判断malloc 分配是否成功
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    // 拷贝之前的数据
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = temPtr[idx];
    }
    //  释放以前的内存 避免内存泄漏
    if(temPtr != NULL)
    {
        free(temPtr);
        temPtr =NULL;
    }
    //更新动态数组的容量
    pArray->capacity = needExpandCapacity;

    return ret;
}


//动态数组插入数据 （默认在末尾插入数据）
    int dynamicArrayInsertData(dynamicArray *pArray,ELEMENTTYPE val )
    {
        dynamicArrayAppointPosInsertData(pArray,pArray->len,val);

    }

//动态数组插入数据 （在指定位置插入数据    在插入后面的数据后移）
    int dynamicArrayAppointPosInsertData(dynamicArray *pArray,int pos,ELEMENTTYPE val)
    {
        //指针判空  避免
        if(pArray == NULL)
        {
            return NULL_PTR;
        }

        //判断位置的合法性  越界
        if(pos < 0 || pos > pArray->len)
        {
            return INVALID_ACCESS;
        }

        if((pArray->len + (pArray->len >> 1)) >= pArray.capacity)
        {
             //开始扩容  动态数组扩容： 要到达临界值时开始扩容 
            expandDynamicCapacity(pArray);
        }

       //数据后移  留出pos的位置 插入
        for(int idx = pArray->len; idx > pos; idx--)
        {
            pArray->data[idx] = pArray->data[idx - 1];
        }

#if 0        
        for(int idx = 1; idx < pArray->len; idx++)
        {
            pArray->data[idx + 1]
        }
#endif
        //找对应的值 写入数组中
        pArray->data = val;
        //数组大小加1
        (pArray->len)++;
        return ON_SUCCESS;


    }

// 动态数组修改指定位置的数据 
    int dynamicArrayModifyAppointPosData(dynamicArray *pArray,int pos,ELEMENTTYPE val)

    {
        if(pArray == NULL)
        {
            return NULL_PTR;
        }
        //判断位置的合法性
        if(pos < 0 || pos >= pArray->len)
        {
            return INVALID_ACCESS;
        } 
        //更新该位置的数据
        pArray->data[pos] = val;
        return ON_SUCCESS;

    }

//动态数组的缩容  
static shrinkDynamicCapacity(dynamicArray * pArray)
{
    int needShrinkCapacity = pArray->capacity  - (pArray->capacity >> 1);

    //备份指针 防止原始数据丢失
    ELEMENTTYPE * temPtr = pArray->data;
    pArray->data =  (ELEMENTTYPE *)  malloc(sizeof(ELEMENTTYPE) * needShrinkCapacity);

   // 判断malloc 分配是否成功
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    
    // 拷贝之前的数据
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = temPtr[idx];
    }
    //  释放以前的内存 避免内存泄漏
    if(temPtr != NULL)
    {
        free(temPtr);
        temPtr =NULL;
    }
    //更新动态数组的容量
    pArray->capacity = needShrinkCapacity;

    return ON_SUCCESS;
}



//动态数组删除数据 (默认是删除末尾的数据)
    int dynamicArrayDeleteData(dynamicArray *pArray)
    {
        dynamicArrayDeleteAppointPosData();



    }

//动态数组删除数据  删除指定位置的数据 后面全部数据前移
    int dynamicArrayDeleteAppointPosData(dynamicArray *pArray,int pos)
    {
        if(pArray == NULL)
        {
            return NULL_PTR;
        }
        if(pos < 0 || pos >= pArray->len)
        {
            return INVALID_ACCESS;
        } 
        // 缩容： 
        if(pArray->len  < (pArray->capacity >> 1))
        {
              shrinkDynamicCapacity(pArray);
        }

        //数据前移
        for(int idx = pos; idx < pArray->len; idx++)
        {
            pArray->data[idx] = pArray->data[idx + 1];
        }
        //更新数组大小
        (pArray->len)--;
        return ON_SUCCESS;
    }

//动态数组删除指定的元素
    int dynamicArrayDeleteAppointData(dynamicArray *pArray ELEMENTTYPE val)
    {
        

    }

//动态数组销毁
    int dynamicArrayDestroy(dynamicArray *pArray);

//动态数组 获取数组的大小
    int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

//动态数组 获取数组的容量
    int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);