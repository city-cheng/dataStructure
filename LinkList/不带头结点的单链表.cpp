#include <stdio.h>
#include <stdlib.h>

//不带头结点的单链表
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;


//初始化空表
bool InitList(LinkList &L){
	L = NULL;
	return true;
} 


//检查表是否为空表
bool Empty(LinkList &L){
	return (L == NULL); 
} 

int main(){
	
	return 0;
} 

//按位序插入
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

