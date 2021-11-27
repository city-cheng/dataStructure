#include <stdio.h>
#include <stdlib.h>

//带头结点的单链表
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 

//初始化空表（带头结点） 
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));
	//内存不足，分配失败 
	if(L == NULL){
		return false;
	}
	L->next = NULL;
	return true;
}

//尾插法建立单链表 
LinkList List_TailInsert(LinkList &L){
	int x;
	InitList(L);
	LNode *s,*r = L;
	scanf("%d",&x);
	while(x != 9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return L;
	
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
	InitList(L);
	int x;
	scanf("%d",&x);
	LNode *p = L;
	while(x != 9999){
		p = (LNode *)malloc(sizeof(LNode));
		p->data = x;
		p->next = L->next;
		L->next = p;
		scanf("%d",&x);
	}
	return L;
} 

//打印链表 
void ShowList(LinkList L){
	LNode *p = L->next;
	while(p != NULL){
		printf("%d\t",p->data);
		p = p->next;	
	}
}


int main(){
	LinkList L = NULL;
	LinkList L_reversed = NULL;
	InitList(L_reversed);
	L = List_TailInsert(L);
	ShowList(L);	
	LNode *p = L->next;
	LNode *s;
	while(p != NULL){
		s = (LNode *)malloc(sizeof(LNode));
		int x = (*p).data;
		s->data = x;
		s->next = L_reversed->next;
		L_reversed->next = s;
		p = p->next;
	} 
	printf("\n");
	ShowList(L_reversed);
	return 0;
	
} 
