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

};


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
        //初始化
        memset(pArray->data,0,sizeof(ELEMENTTYPE) * capacity);
        pArray->len = 0;
        pArray->capacity = capacity;
        return ON_SUCCESS;






    }

//动态数组插入数据 （默认在末尾插入数据）
    int dynamicArrayInsertData(dynamicArray *pArray,ELEMENTTYPE val );

//动态数组插入数据 （在指定位置插入数据    在插入后面的数据后移）
    int dynamicArrayAppointPosInsertData(dynamicArray *pArray,int pos,ELEMENTTYPE val);

// 动态数组修改指定位置的数据 
    int dynamicArrayModifyAppointPosData(dynamicArray *pArray,int pos,ELEMENTTYPE val);

//动态数组删除数据 (默认是删除末尾的数据)
    int dynamicArrayDeleteData(dynamicArray *pArray);

//动态数组删除数据  删除指定位置的数据 后面全部数据前移
    int dynamicArrayDeleteAppointPosData(dynamicArray *pArray,int pos);

//动态数组删除指定的元素
    int dynamicArrayDeleteAppointPosData(dynamicArray ELEMENTTYPE val);

//动态数组销毁
    int dynamicArrayDestroy(dynamicArray *pArray);

//动态数组 获取数组的大小
    int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

//动态数组 获取数组的容量
    int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);