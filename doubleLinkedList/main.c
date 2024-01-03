#include <stdio.h>
#include "doubleLinkedList.h"
#include <string.h>
// #define BUFFER_SIZE 3

#define BUFFER_SIEZE 5
#if 0
#define DEFAULT_SIZE 3

typedef struct stuInfo
{
    int age;
    int sex;
} stuInfo;

#if 0
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
    return num1 > num2 ? 1: 0;
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
        DoubleLinkListTailInsert(list,(void *)&buffer[idx]);
    }

    //尾删
    // DoubleLinkListTailDel(list);
    DoubleLinkListHeadDel(list);

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
#endif

/* 比较函数  */
int comparFunc( ELEMENTTPYE arg1, ELEMENTTPYE  arg2)
{
    int num1 = *(int *)arg1;
    int num2 = *(int *)arg2;
    if(num1 <= num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
    

    
}

/* 合并链表的函数*/
DoubleLinkList * mergeOrderLinkLisr(DoubleLinkList *Plist1, DoubleLinkList *Plist2)
{
    int ret = 0;
    /* 链表1为空 返回链表2 */
    DoubleLinkNode *Plist1Node = Plist1->head->next;
    if (Plist1 == NULL)
    {
        return Plist2;
    }

    /* 链表1和2都为空 就返回空 */
    if (Plist1 == NULL && Plist1 == NULL)
    {
        return NULL;
    }

    /* 链表2为空 返回链表1 */
    DoubleLinkNode *Plist2Node = Plist2->head->next;
    if (Plist2 == NULL)
    {
        return Plist1;
    }

    /* 用一个新的链表存放排好序的新链表 */
    DoubleLinkList *newLinkList = NULL;
    DoubleLinkListInit(&newLinkList);

    /* 链表1 和链表2 都不为空 */
    while (Plist1 != NULL && Plist1 != NULL)
    {
        if (comparFunc(Plist1Node, Plist2Node))
        {
            DoubleLinkListTailInsert(newLinkList, Plist1Node->data);
            Plist1Node = Plist1Node->next;
        }
        else
        {
            DoubleLinkListTailInsert(newLinkList, Plist2Node->data);
            Plist2Node = Plist2Node->next;
        }
    }
    /* 链表1结束*/
    if (Plist2 != NULL)
    {
        DoubleLinkListTailInsert(newLinkList, Plist2Node->data);
        Plist2Node = Plist2Node->next;
    }
    else if (Plist1 != NULL)
    {
        DoubleLinkListTailInsert(newLinkList, Plist1Node->data);
        Plist1Node = Plist1Node->next;
    }

    return NULL;
}

/* 用户自定义 */
int printfBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data %d\n", data);
    return 0;
}

int main()
{

    DoubleLinkList *Plist1 = NULL;
    DoubleLinkListInit(&Plist1);

    DoubleLinkList *Plist2 = NULL;
    DoubleLinkListInit(&Plist2);

    int array1[BUFFER_SIEZE] = {1, 3, 5, 6, 7};
    int array2[BUFFER_SIEZE] = {2, 4, 5, 6, 8};
    for (int idx = 0; idx < BUFFER_SIEZE; idx++)
    {
        DoubleLinkListHeadInsert(Plist1, (void *)&array1[idx]);
        DoubleLinkListHeadInsert(Plist2, (void *)&array2[idx]);
    }
#if 0
    // 获取长度
    int size = 0;
    DoubleLinkListGetLength(Plist1, &size);
    printf("size1 %d\n", size);

    DoubleLinkListGetLength(Plist2, &size);
    printf("size2 %d\n", size);

    // 逆序遍历
    DoubleLinkListReverForeach(Plist1, printfBasicData);
    printf("\n");
    DoubleLinkListReverForeach(Plist2, printfBasicData);
#endif
    DoubleLinkList *list = mergeOrderLinkLisr(Plist1, Plist2);
    int size = 0;
    DoubleLinkListGetLength(list, &size);
    printf("size3 %d\n", size);

    linkedListForeach(list, printfBasicData);

    return 0;
}
