#include <stdio.h>
#include <stdlib.h>

//链队列 (带头结点) 
typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
	LinkNode *rear,*front;
}LinkQueue;

//初始化链队列(带头结点)
bool InitQueue(LinkQueue &q){
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	q.rear = q.front = p;
	q.rear->next = NULL;
	return true;
}

//链队列的入队操作(带头结点)
bool EnQueue(LinkQueue &q,int e) {
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return true;
}


//链队列的出队操作(带头结点)
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


