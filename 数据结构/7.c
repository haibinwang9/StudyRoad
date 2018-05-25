#include<stdio.h>
#include<stdlib.h>
#define ElemType unsigned int;//存储值为正整数 采用无符号整型（宏定义） //我用的在线编译器有点问题 没有使用这个 你可以自己修改一下

//结点结构定义
typedef struct {
   unsigned int data;      //存储数据
   struct Node  *next;    //指向下一个节点
}Node,*NodePtr;

//带头节点的单链表结构定义（头节点不储存值）
typedef struct {
    NodePtr head;   //头节点
    unsigned int length;//链表长度
}List,*ListPtr;

/*
 *函数说明：初始化链表
 *参数说明：L 链表,data 需要插入的数据
 *return：返回一个链表
 */
ListPtr initList(){
    ListPtr list =(List*)malloc(sizeof(List));  //申请一个List内存空间 list 指向该内存空间
    list->head=NULL;   //初始化 头指针置NULL
    list->length=0;     //初始化链表长度为 0
    return list;       //返回一个listPtr 指针
}


/*
 *函数说明：向链表中 <头部> 插入数据
 *参数说明：L 链表,data 需要插入的数据
 *return：1 代表成功， 0代表失败
 */
int insertListInHead(ListPtr L,unsigned int data){
   NodePtr da = (Node*)malloc(sizeof(Node)); //申请一个Node型的内存地址，da指向改内存地址
   if(!da) return 0;  //判断申请是否成功，失败返回0；
   da->data=data;    //储存数据

     //判断是否为第一个值
    if(L->head==NULL){    //是
        L->head=da;      //头结点指向需要插入的结点
        L->length++;    //链表长度加一
       return 1;        
    }
  else{  //否
      da->next=L->head;   //存储原先的头指针指向的结点
      L->head=da;          //头指针指向需要插入的结点
      L->length++;       //链表长度加一
      return 1;
    }//if
}



//输入链表函数（可选）测试未用到
void inputList(ListPtr L){
    unsigned int i;
    unsigned int length=0;
    unsigned int data;
    printf("请输入原始链表长度：\n");
    scanf("%d",&length);
    for(i=0;i<length;i++){
        printf("输入第%d个数据:/n");
        scanf("%d",&data);
        insertListInHead(L,data);
    }//for
}

//输出链表函数
void outputList(ListPtr L){
    NodePtr p=L->head;//指针p指向头指针指向的结点
    while(p){   //只要p指向的结点不为空 ，则执行输出代码
        printf("%d   ",p->data); //输出
        p=p->next;//指向下一个结点
    }
    printf("\n");    //换行
}



/*函数说明： 链表分裂为从下到到大的奇偶链表
 *参数说明： 传入三个参数，L1为原始数据链表，L2存储偶数链表,L3存储奇数链表
 *return 成功返回 1， 失败返回 0
 *
 */
int split(ListPtr L1,ListPtr L2,ListPtr L3){
    NodePtr p=L1->head;         //指针p指向头指针指向的结点
    if(p==NULL) return 0;       //头结点为空，链表为空 返回0 失败
    while(p){   //判断是否p为NULL，不为NULL执行以下代码
        
        //判断值奇偶性， 一个正整数除以2取余数，奇数为1,偶数为0. 
        if(p->data%2) insertListInHead(L3,p->data);  //奇数插入L3
        else insertListInHead(L2,p->data);   //偶数插入L2
        p=p->next;   //下一个结点
    }
    return 1;
}

//测试用
void demo(ListPtr L){
     insertListInHead(L,1);
     insertListInHead(L,2);
     insertListInHead(L,3);
     insertListInHead(L,4);
    insertListInHead(L,5); 
    insertListInHead(L,6);
    insertListInHead(L,7);
     insertListInHead(L,8);
     insertListInHead(L,9);
     insertListInHead(L,10);
    
}


int main(void) {
    //需要循环显示，可以使用一个while(1)死循环， 利用break或者exit()(好像需要导入system.h头文件。有点忘了)结束
        //初始化
        ListPtr listOne=initList();
        ListPtr listTwo=initList();
        ListPtr listThr=initList();
    
        /*unsigned int flag=1;
        printf("是否开始输入数据？（1代表是，0代表否）\n");
        if(flag==0) return 0;
        else inputList(listOne);*/
   
        demo(listOne); //测试数据
        split(listOne,listTwo,listThr);
        printf("原始数据为:\n");
        outputList(listOne);
        outputList(listTwo);
        outputList(listThr);
    return 0;
}
