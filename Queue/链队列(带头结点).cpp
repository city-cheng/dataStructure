#include <stdio.h>
#include <stdlib.h>

//������ (��ͷ���) 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
	LinkNode *rear,*front;
}LinkQueue;

//��ʼ��������(��ͷ���)
bool InitQueue(LinkQueue &q){
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	q.rear = q.front = p;
	q.rear->next = NULL;
	return true;
}

//�����е���Ӳ���(��ͷ���)
bool EnQueue(LinkQueue &q,int e) {
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return true;
}


//�����еĳ��Ӳ���(��ͷ���)
bool DeQueue(LinkQueue &q,int &x){
	if(q.front == q.rear){
		return false;
	}
	LinkNode *p = q.front->next;
	x = p->data;
	q.front->next = p->next; 
	if(q.rear == p){
		q.rear = q.front;
	}
	free(p);
	return true;
}


