#include <stdio.h>
#include <stdlib.h>

//带头结点的单链表
typedef struct LNode
{
	int data;
	LNode *next;
} LNode, *LinkList;

//初始化
bool InitList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));

	if (L == NULL)
	{
		return false;
	}
	L->next = NULL;
	return true;
}

//是否为空
bool IsEmpty(LinkList &L)
{
	return L->next == NULL;
}

//插入元素到指定节点的后面
bool InsertNextNode(LNode *p, int e)
{
	LNode *q = (LNode *)malloc(sizeof(LNode));
	if (q == NULL)
	{
		return false;
	}
	q->data = e;
	q->next = p->next;
	p->next = q;
	return true;
}

//按位序插入
bool InsertByIndex(LinkList &L, int i, int e)
{
	if (i < 1)
	{
		return false;
	}
	LNode *p = L;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

	// LNode *q = (LNode *)malloc(sizeof(LNode));
	// q->data = e;
	// q->next = p->next;
	// p->next = q;
	// return true;
	return InsertNextNode(p, e);
}

//指定节点的前插操作
bool InsertPriorNode(LNode *p, int e)
{
	if (p == NULL)
	{
		return false;
	}
	LNode *q = (LNode *)malloc(sizeof(LNode));
	if (q == NULL)
	{
		return false;
	}
	q->next = p->next;
	p->next = q;
	q->data = p->data;
	p->data = e;
	return true;
}



//按位序删除
bool DeleteByIndex(LinkList &L,int i,int e){
	if(i < 1){
		return false;
	}

	LNode *p = L;
	int j = 0;
	while(p != NULL && j < i - 1){
		p = p->next;
		j++;
	}
	if(p->next == NULL){
		return false;
	}
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;

}


//删除指定节点
bool DeleteNode(LNode *p){
	if(p == NULL){
		return false;
	}

	LNode *q = p->next;
	q->data = p->data;
	p->next = q->next;
	free(q);
	return true;
}

//按位查找
LNode *GetElem(LinkList L,int i){
	LNode *p = L;
	int j = 0;
	while(p != NULL && j <i){
		p = p->next;
		j++;
	}
	return p;
}


//按值查找
LNode *LocateElem(LinkList L,int e){
	LNode *p = L;
	while(p != NULL){
		if(p->data == e){
			break;
		}else{
			p = p->next;
		}
	}
	return p;
}


//求表长
int Length(LinkList L){
	LNode *p = L;
	int i = 0;
	while(p != NULL){
		i++;
	}
	return i;
}

//尾插法
LinkList ListTailInsert(LinkList &L){
	int x;
	InitList(L);
	LNode *q;
	LNode *p = L;
	for(int i = 0;i < 10;i++){
		q = (LNode *)malloc(sizeof(LNode));
		q->data = i;
		p->next = q;
		p = q;
	}

	p->next = NULL;
	return L;

}