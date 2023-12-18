#include <stdio.h>
#include "dynamicArray.h"

#define BUFFER_SIZE 10
#define DEFAULT_SIZE 5


typedef struct stuInfo
{
    int age;
    int sex;
} stuInfo ;





int main()
{   
    dynamicArray array;
    dynamicArrayInit(&array,BUFFER_SIZE);

#if 0
    //插入数据
    dynamicArrayInsertData(&array, 3);
    for(int idx = 0; idx <= DEFAULT_SIZE; idx++)
    {
         dynamicArrayInsertData(&array,21);
    }


    //获取动态数据的大小
    int size = 0;
    dynamicArrayGetSize(&array,&size);
    printf("size:%d\n",size);


    int val = 0;
    for(int idx = 0; idx <size ;idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val:%d\n",val);
    }
//删除最后位置数据
    dynamicArrayDeleteData(&array);
    dynamicArrayGetSize(&array,&size);
    printf("size:%d\n",size);  


//删除指定位置的元素
    int pos = 0;
    dynamicArrayDeleteAppointPosData(&array,pos);

#endif

    stuInfo stu1,stu2,stu3;
    memset(&stu1,0,sizeof(stu1));
    memset(&stu2,0,sizeof(stu2));
    memset(&stu3,0,sizeof(stu3));


    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';

    dynamicArrayInsertData(&array,);
    dynamicArrayInsertData(&array,);
    dynamicArrayInsertData(&array,);



    return 0;
}