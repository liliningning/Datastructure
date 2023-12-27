#include <stdio.h>
#include "doubleLinkedList.h"
#include <string.h>

#define BUFFER_SIZE 3

#define DEFAULT_SIZE 3

typedef struct stuInfo
{
    int age;
    int sex;
} stuInfo;

#if 1
//自定义打印 用户定义是什么类型 就用什么类型
 int printfStruct(void * arg)
 {
         stuInfo *info  = (stuInfo*)arg;
         printf("age :%d\t, sex :%c\n",info->age,info->sex);
 }


int comparFunc (ELEMENTTPYE arg1, ELEMENTTPYE arg2)
{
    int num1 = *(int *)arg1;
    int num2 = *(int *)arg2;
    return num1 == num2 ? 1: 0;
}
#else
// 用户自定义
int printfBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data %d\n", data);
    return 0;
}
#endif
int main()
{

    DoubleLinkList *list = NULL;
    // 初始化链表
    DoubleLinkListInit(&list);
    // int buffer[BUFFER_SIZE] = {1, 2, 3};
#if 0

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        // 插入数据 头插
        // DoubleLinkListHeadInsert(list, idx);
        DoubleLinkListHeadInsert(list, (void *)&buffer[idx]);


        // 尾插
        //  DoubleLinkListTailInsert(list, idx);

        // 指定位置插入
        //  DoubleLinkListAppointPosInsert(list, idx,3);
    }
    // DoubleLinkListHeadInsert(list, 3);

    // 头删
    //  DoubleLinkListHeadDel(list);

    // 尾删
    //  DoubleLinkListTailDel(list);

    // 指定位置删除
    //  DoubleLinkListAppintPosDel(list,2);

    // 删除指定的元素
    // DoubleLinkListDelAppointData(list, 1);

    // 获取链表长度
    int size = 0;
    DoubleLinkListGetLength(list, &size);
    printf("size %d\n", size);

    // 遍历输出结点值
    // linkedListForeach(list);
    linkedListForeach(list,printfBasicData);

#endif
#if 1

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
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        DoubleLinkListHeadInsert(list, (void *)&buffer[idx]);
        // DoubleLinkListTailInsert(list,(void *)&buffer[idx]);
    }

    //尾删
    DoubleLinkListTailDel(list);

    //指定数据删除
    // DoubleLinkListDelAppointData (list, (void *)&buffer[1] , comparFunc);

    //获取长度
    int size = 0;
    DoubleLinkListGetLength(list, &size);
    printf("size %d\n", size);

    //逆序遍历
    DoubleLinkListReverForeach(list, printfStruct);

#endif

        return 0;
}