#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_
/* 动态数组： 容量  大小 空间大小   */


typedef int ELEMENTTYPE; //方便修改

   typedef   struct  dynamicArray
{
   ELEMENTTYPE *data;    //数组的空间
   int len;              //大小
   int capacity;        // 容量


} dynamicArray;

/* API： 接口*/
//动态数组的初始化
    int dynamicArrayInit( );

//动态数组插入数据 （默认在末尾插入数据）
    int dynamicArrayInsertData();

//动态数组插入数据 （在指定位置插入数据    在插入后面的数据后移）
    int dynamicArrayAppointPosInsertData();

// 动态数组修改指定位置的数据 
    int dynamicArrayModifyAppointPosData();

//动态数组删除数据 (默认是删除末尾的数据)
    int dynamicArrayDeleteData();

//动态数组删除数据  删除指定位置的数据 后面全部数据前移
    int dynamicArrayDeleteAppointPosData();

//动态数组销毁
    int dynamicArrayDestroy();

//动态数组 获取数组的大小
    int dynamicArrayGetSize();

//动态数组 获取数组的容量
    int dynamicArrayGetCapacity();

#endif