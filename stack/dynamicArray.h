#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_
#include "commom.h"
/* 动态数组： 容量  大小 空间大小   */
#if 0
#define ELEMENTTYPE void*
//  typedef void * ELEMENTTYPE; //方便修改
//  typedef int ELEMENTTYPE;

   typedef   struct  dynamicArray
{
   ELEMENTTYPE *data;    //数组的数
   int len;              //大小
   int capacity;        // 容量


} dynamicArray;
#endif

/* API： 接口*/
//动态数组的初始化
    int dynamicArrayInit(dynamicArray *pArray, int capacity );

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

//动态数组删除指定的元素  里面存在的所有指定的元素
    int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE *val);

//动态数组销毁
    int dynamicArrayDestroy(dynamicArray *pArray);

//动态数组 获取数组的大小
    int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

//动态数组 获取数组的容量
    int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);

//获取指定位置的数据元素
    int dynamicArrayGetAppointPosVal(dynamicArray *pArray,int pos, ELEMENTTYPE *pVal);



#endif