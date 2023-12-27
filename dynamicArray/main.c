#include <stdio.h>
#include "dynamicArray.h"
#include <string.h>

#define BUFFER_SIZE 10
#define DEFAULT_SIZE 3

typedef struct stuInfo
{
    int age;
    int sex;
} stuInfo;

int main()
{
    // 动态数组初始化
    dynamicArray array;
    dynamicArrayInit(&array, BUFFER_SIZE);

#if 0
    //插入数据 默认在末尾插入
    // int idx = 0;
    for(int idx = 0; idx < 3; idx++)
    {
        dynamicArrayInsertData(&array,(void *)&idx);
        
    }
    //获取动态数据的大小
     int size = 0;
    dynamicArrayGetSize(&array,&size);
    printf("size:%d\n",size);


    //修改指定位置的元素
    int pos = 0;
    int *val = NULL;
    dynamicArrayModifyAppointPosData(&array,pos,(void *)&val);

     int idx = 0; // 定义在外面  
    for(idx = 0; idx < DEFAULT_SIZE; idx++) //size为数组的大小
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        // printf("idx %d\n",idx);
        printf("val:%p\n",val);
    }
    // printf("%p\n", array.data);










//删除最后位置数据
 dynamicArrayDeleteAppointPosData(&array,size- 1);
    dynamicArrayGetSize(&array,&size);
    printf("size:%d\n",size);  


//删除指定位置的元素
    // int pos = 0;
    dynamicArrayDeleteAppointPosData(&array,pos);
    dynamicArrayGetSize(&array,&size);
    printf("size:%d\n",size);

#elif 1
    // 插入数据
    int buffer[DEFAULT_SIZE] = {1, 3, 3};
    for (int idx = 0; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }
   
    
#if 0
    //在指定位置插入元素
    for(int idx = 0; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayAppointPosInsertData(&array,idx,(void *)&buffer[idx]);
    }

    //修改指定位置的元素
    int tem = 4;
    dynamicArrayModifyAppointPosData(&array,1,(void *)&tem);

#endif

    // 删除数据（默认在末尾删除）
    // dynamicArrayDeleteData(&array);
   
    //  dynamicArrayDeleteAppointPosData(&array, 0);

//    删除数组里面指定元素 
    int tem = 3;
    dynamicArrayDeleteAppointData(&array,(void *)&tem);
  
    //获取动态数组的容量
    int capacity = 0;
    dynamicArrayGetCapacity(&array,&capacity);
    printf("capacity %d\n",capacity);


     //  获取动态数组的大小
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size %d\n", size);



    // 获取指定位置的元素
    int *val = NULL;
  
    for ( int idx = 0; idx < size ; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val: %d\n", *val);
    }

#elif 0
    int idx = 0;
    for (idx; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&idx);
    }
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size %d\n", size);

    int *val = NULL;
    for (int idx = 0; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val: %d\n", *val);
    }

#elif 0

    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';

    stuInfo buffer[DEFAULT_SIZE] = {stu1, stu2, stu3};
    for (int idx = 0; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }

    // dynamicArrayInsertData(&array,(void*)&stu2);
    // dynamicArrayInsertData(&array,(void*)&stu3);

    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size %d\n", size);

    stuInfo *info = NULL;
    // memset(&info, 0,sizeof(info));
    for (int idx = 0; idx < DEFAULT_SIZE; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&info);
        printf("info age %d\t, info sex %c\n", info->age, info->sex);
    }

#endif
    return 0;
}