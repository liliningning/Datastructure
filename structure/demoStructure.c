//提交在github 上面 修改错误后
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIEZE 10
#define DEFALUT_SIZE 2

/*结构体
1.什么是结构体：将不同类型的属性封装成一个类型
2. 结构体定义：
3.字节对齐： 读取速度快 浪费空间
4.什么是变长结构体？
5.结构体位域?
6. 结构体必须用指针 省内存空间

 */
//取别名
typedef struct stuInfo stu
{
    int age;
    int height;
    int weight;
    int sex;
    char name[BUFFER_SIEZE];
    char *address;  // 自己没有空间 是指向一个空间   需要给其分配空间 （malloc）  其存的是一个地址 没有分配空间
};


stu.address = (char *)malloc(sizeof(char)  * BUFFER_SIEZE);
//开辟空间 要进行判空
if(stu.address == NULL)
{

    return NULL;
}

#if 0
//值传递   结构体函数  
int  printStruct( stuInfo stu)
{

     printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%d\t,stu.weight:%d\t,stu.name:%d\t",
     stu.age,stu.height,stu.name,stu.sex,stu.weight);


return 0;

}

#endif

// 传入参数 ： 不能改变值
#if 1
int printStruct(const stuInfo *stu)
{
    int ret = 0;
    int len = sizeof(stu);
    // stu-> age = 100;
    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%d\t,stu.weight:%d\t,stu.name:%d\t",
           stu.age, stu.height, stu.name, stu.sex, stu.weight);

    return 0;
}

#endif

#if 0

int     printStructBuffer( stuInfo * stu, int stuSize)
{
    for(int idx = 0; idx < stuSize; idx++)
    {
        
        printf("buffer[0].age:%d\t,buffer[0].height:%d\t,buffer[0].sex :%d\t,buffer[0].weight:%d\t,buffer[0].name:%d\t",
       stu[0].age,stu[0].height,stu[0].sex ,stu[0].weight ,stu[0].name);


    }


    return 0;
}

#endif


int main()
{

#if 0

    // 怎么使用结构体：

 struct stuInfo stu;
// 结构体大小
//  int len = sizeof((stu));
//  printf("len %d\n",len);

// 结构体使用
#if 0
    stu.age = 10;
    stu.height = 170;
    stu.sex = 'm';
    stu.weight = 100;
    strncpy(stu.name,"zhangsan,",sizeof(stu.name) - 1);
 printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%d\t,stu.weight:%d\t,stu.name:%d\t",stu.age,stu.height,stu.name,stu.sex,stu.weight)

#endif

// 结构体数组
#if 0
 stuInfo buffer[DEFALUT_SIZE];

buffer[0].age = 10;
buffer[0].height = 170;
buffer[0].sex = 'm';
buffer[0].weight = 100;
strncpy(buffer[0].name,"zhangsan,",sizeof(buffer[0].name) - 1);


buffer[1].age = 10;
buffer[1].height = 170;
buffer[1].sex = 'm';
buffer[1].weight = 100;
strncpy(buffer[1].name,"zhangsan,",sizeof(buffer[1].name) - 1);

 printf("buffer[0].age:%d\t,buffer[0].height:%d\t,buffer[0].sex :%d\t,buffer[0].weight:%d\t,buffer[0].name:%d\t",
 buffer[0].age,buffer[0].height,buffer[0].sex ,buffer[0].weight ,buffer[0].name);

 printf("buffer[1].age:%d\t,buffer[1].height:%d\t,buffer[1].sex :%d\t,buffer[1].weight:%d\t,buffer[1].name:%d\t",
 buffer[1].age,buffer[1].height,buffer[1].sex ,buffer[1].weight ,buffer[1].name);

#endif

#if 1

//结构体指针

stu.age = 10;
stu.height = 170;
stu.sex = 'm';
stu.weight = 100;
strncpy(stu.name,"zhangsan,",sizeof(stu.name) - 1);

// stuInfo *info = &stu;

//结构体指针 读数据 取数据 都是 -> 

info->age = 30;
printf("info->age:%d\n",info->age);

printStruct(stu);
printf("stu:%d\n",stu);

#endif

#if 0

    stuInfo buffer[DEFALUT_SIZE];

    buffer[0].age = 10;
    buffer[0].height = 170;
    buffer[0].sex = 'm';
    buffer[0].weight = 100;
    strncpy(buffer[0].name, "zhangsan,", sizeof(buffer[0].name) - 1);

    buffer[1].age = 10;
    buffer[1].height = 170;
    buffer[1].sex = 'm';
    buffer[1].weight = 100;
    strncpy(buffer[1].name, "zhangsan,", sizeof(buffer[1].name) - 1);

    printStructBuffer(buffer,sizeof(buffer)/ sizeof(buffer[0]));

#endif

#endif

    return 0;
}