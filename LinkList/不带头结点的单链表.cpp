#include <stdio.h>
#include <stdlib.h>

//����ͷ���ĵ�����
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;


//��ʼ���ձ�
bool InitList(LinkList &L){
	L = NULL;
	return true;
} 


//�����Ƿ�Ϊ�ձ�
bool Empty(LinkList &L){
	return (L == NULL); 
} 

int main(){
	
	return 0;
} 

//��λ�����
bool ListInsert(LinkList &L,int i ,int e){
	if(i < 1){
		return false;
	}
	if(i == 1){
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->data = e;
		s->next = L;
		L = s;
		return true;
	}
	LNode *p;
	p = L;
	int j = 1;
	
	while(p!= NULL && j < i-1){
		p = p->next;
		j++;
	}
	if(p != NULL){
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true; 
	
} 

