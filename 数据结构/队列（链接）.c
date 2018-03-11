//���У����ӣ�
#include<stdio.h>
#include<stdlib.h>
#define Element int 
#define OK 1

typedef struct NodeQueue{
       Element  data;
	  struct NodeQueue *next;
 }NQueue;

typedef struct{
	struct NodeQueue *head,*tail;
	int len;
}Queue;

//��ʼ��
int InitNodeQueue(Queue *L){
       L->head=(NQueue *)malloc(sizeof(NQueue));
	   L->head->next=NULL;
	   L->tail=L->head;
	   L->len=0;
return OK;
}

	

//�п�
int IsEmpty(Queue *L){
	if(L->head==L->tail) return OK;
	else return 0;
return OK;
}



//����
int EnNodeQueue(Queue *L,Element e){
       NQueue *p=(NQueue *)malloc(sizeof(NQueue));
	   if(!p) exit(0);
	   p->data = e;
	   p->next=NULL;
	   L->tail->next=p;
	   L->tail=p;
	    L->len++;
       return OK;
}


//����
Element DeNodeQueue(Queue *L){
	Element e;
	if(IsEmpty(L)) {printf("����Ϊ��."); exit(10);}
    NQueue *p=L->head->next;
	if(p==L->tail){
	    e=p->data;
		L->head->next=NULL;
		L->tail=L->head;
	}
    else  	{
		 e=p->data;
		 L->head->next=p->next;
	}
	 L->len--;
		free(p);
return e;
}


//�����
int OutputNodeQueue(Queue *L){
         NQueue *p=L->head->next;
    int i=1;
	printf("���п�ʼ�����\n");
	for(i;i<L->len+1;i++){
		printf("[%d]=%d.\n",i,p->data);
		p=p->next;
	}
		printf("���������ɡ�\n");
   return OK;
}

int main(){
	   Queue Q;
	   Element e=0;
		InitNodeQueue(&Q);
		EnNodeQueue(&Q,1);
			EnNodeQueue(&Q,2);
				EnNodeQueue(&Q,3);
					EnNodeQueue(&Q,4);
						EnNodeQueue(&Q,5);
					OutputNodeQueue(&Q);
						printf("%d\n",DeNodeQueue(&Q));
						OutputNodeQueue(&Q);
	return 0;
}

