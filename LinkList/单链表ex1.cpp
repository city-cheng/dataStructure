#include <stdio.h>
#include <stdlib.h>

//��ͷ���ĵ�����
typedef struct LNode
{
	int data;
	LNode *next;
} LNode, *LinkList;

//��ʼ��
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

//�Ƿ�Ϊ��
bool IsEmpty(LinkList &L)
{
	return L->next == NULL;
}

//����Ԫ�ص�ָ���ڵ�ĺ���
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

//��λ�����
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

//ָ���ڵ��ǰ�����
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



//��λ��ɾ��
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


//ɾ��ָ���ڵ�
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

//��λ����
LNode *GetElem(LinkList L,int i){
	LNode *p = L;
	int j = 0;
	while(p != NULL && j <i){
		p = p->next;
		j++;
	}
	return p;
}


//��ֵ����
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


//���
int Length(LinkList L){
	LNode *p = L;
	int i = 0;
	while(p != NULL){
		i++;
	}
	return i;
}

//β�巨
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