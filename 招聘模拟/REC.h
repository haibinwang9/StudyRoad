#pragma once
#ifndef REC_H
#define REC_H
//��������
typedef struct {
	int Work_ID;//���
	int Work_Num;  //��Ƹ��λ����
}Works;

//ӦƸ��
typedef struct {
	int Person_ID;//��ְ�߱��
	int Score;
	int First;//��һ־Ը
	int Second;//�ڶ�־Ը
	int flag;  //�жϵ�һ־Ըδ¼ȡ�ı��
}Person;

//����
typedef struct {
	Person *base;
	int front;     //���е�ͷ
	int rear;      //���е�β
	int size;
}Queue;

#endif 