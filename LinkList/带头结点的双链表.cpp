#include <stdio.h>
#include <stdlib.h>

//双链表
typedef struct DLinkNode{
	int data;
	struct DLinkNode *prior;    //指向前驱节点的指针 
	struct DLinkNode *next;     //指向后继节点的指针 
}DLinkNode,*DLinkList;

//双链表初始化
bool InitList(DLinkList &L){
	//分配了一个头结点 
	L = (DLinkList)malloc(sizeof(DLinkList));
	if(L == NULL){
		return false;
	}
	L->prior = NULL;      //双链表头结点的前驱指针永远指向NULL
	L->next = NULL;
	return true; 
} 

//判断双链表是否为空 
bool Empty(DLinkList L){
	if(L->next == NULL){
		return true;
	}
	return false;
}


//后插操作
bool InsertNextNode(DLinkNode *p,int e){
	if(p == NULL){
		return false;
	} 
	DLinkNode *s;
	s = (DLinkNode *)malloc(sizeof(DLinkNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	s->prior = p;
	//要考虑好最后一个节点的情况 
	if(s->next != NULL){
		s->next->prior = s;
	}
	return true;
} 

//删除p节点的后继节点
bool DeleteNextNode(DLinkNode *p){
	if(p == NULL){
		return false;
	}
	DLinkNode *q = p->next;
	//若p之后没有节点 
	if(q == NULL){
		return false;
	}
	p->next = q->next;
	//若删除了p的后继节点之后，p成为最后一个节点 （即q没有后继节点） 
	if(q->next != NULL){
		q->next->prior = p;
	}
	free(q);
	return true;
} 





