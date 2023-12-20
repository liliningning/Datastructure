#include <stdio.h>
#include "linkedList.h"
#include <string.h>

#define BUFFER_SIZE 3

#define DEFAULT_SIZE 3

#if 0
typedef struct stuInfo
{
    int age;
    int sex;
} stuInfo;

//自定义打印
 int printfStruct(void * arg)
 {
         stuInfo *info  = (stuInfo*)arg;
         printf("age :%d\t, sex%d\t",info->age,info->sex);
 }


int printfBasicData(void * arg)
{
    int data = *(int *)arg;
    printf("data %d\n",data); 
}
#endif
int main()
{

    LinkList *list = NULL;
    // 初始化链表
    LinkListInit(&list);
#if 1

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        // 插入数据 头插
        LinkListHeadInsert(list, idx);

        //尾插
        // LinkListTailInsert(list, idx);

        //指定位置插入
        // LinkListAppointPosInsert(list, idx,3);
    }
    // LinkListHeadInsert(list, 3);

    //头删
    // LinkListHeadDel(list);

    //尾删
    // LinkListTailDel(list);

    //指定位置删除
    // LinkListAppintPosDel(list,2);

    //删除指定的元素
    LinkListDelAppointData(list,1);

    // 获取链表长度
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size %d\n", size);

    //遍历输出结点值
    linkedListForeach(list);

#endif
#if 0

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

    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListHeadInsert(list,(void*)&buffer[idx]);
    }


    int size = 0;
    LinkListGetLength(list, &size);
    printf("size %d\n",size);

    //遍历
    // linkedListForeach(list, printfStruct);
    linkedListForeach(list, printfBasicData);

#endif

    return 0;
}