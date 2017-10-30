#pragma once
#ifndef REC_H
#define REC_H
//工种类型
typedef struct {
	int Work_ID;//编号
	int Work_Num;  //招聘岗位数量
}Works;

//应聘者
typedef struct {
	int Person_ID;//求职者编号
	int Score;
	int First;//第一志愿
	int Second;//第二志愿
	int flag;  //判断第一志愿未录取的标记
}Person;

//链接
typedef struct {
	Person *base;
	int front;     //队列的头
	int rear;      //队列的尾
	int size;
}Queue;

#endif 