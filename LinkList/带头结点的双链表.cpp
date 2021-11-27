#include <stdio.h>
#include <stdlib.h>

//˫����
typedef struct DLinkNode{
	int data;
	struct DLinkNode *prior;    //ָ��ǰ���ڵ��ָ�� 
	struct DLinkNode *next;     //ָ���̽ڵ��ָ�� 
}DLinkNode,*DLinkList;

//˫�����ʼ��
bool InitList(DLinkList &L){
	//������һ��ͷ��� 
	L = (DLinkList)malloc(sizeof(DLinkList));
	if(L == NULL){
		return false;
	}
	L->prior = NULL;      //˫����ͷ����ǰ��ָ����Զָ��NULL
	L->next = NULL;
	return true; 
} 

//�ж�˫�����Ƿ�Ϊ�� 
bool Empty(DLinkList L){
	if(L->next == NULL){
		return true;
	}
	return false;
}


//������
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
	//Ҫ���Ǻ����һ���ڵ����� 
	if(s->next != NULL){
		s->next->prior = s;
	}
	return true;
} 

//ɾ��p�ڵ�ĺ�̽ڵ�
bool DeleteNextNode(DLinkNode *p){
	if(p == NULL){
		return false;
	}
	DLinkNode *q = p->next;
	//��p֮��û�нڵ� 
	if(q == NULL){
		return false;
	}
	p->next = q->next;
	//��ɾ����p�ĺ�̽ڵ�֮��p��Ϊ���һ���ڵ� ����qû�к�̽ڵ㣩 
	if(q->next != NULL){
		q->next->prior = p;
	}
	free(q);
	return true;
} 





