#ifndef __COMMOM_H_
#define  __COMMOM_H_

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