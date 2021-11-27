#include <stdio.h>
#include <stdlib.h>

//��ջ
typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;

//��ջ��ʼ������ͷ��㣩
bool InitStack(LinkStack &S){
	S = (StackNode *)malloc(sizeof(StackNode));
	if(S == NULL){
		return false;
	}
	S->next = NULL;
	return true;
}

//��ջ����ջ����
bool Push(LinkStack &S,int e){
	StackNode *p = (StackNode *)malloc(sizeof(StackNode));
	if(p == NULL){
		return false;
	}
	p->data = e;
	p->next = S->next;
	S->next = p;
	return true;
}

//��ջ�ĳ�ջ����
bool Pop(LinkStack &S,int &x){
	if(S->next == NULL){
		return false;
	}
	StackNode *p = S->next;
	x = S->next->data;
	S->next = p->next;
	free(p);
	return true;
} 

//��ȡջ��Ԫ��
int GetTop(LinkStack S){
	return S->next->data;
} 

//�ж�ջ��ջ��
bool Empty(LinkStack S) {
	if(S->next == NULL){
		return true;
	}
	return false;
}










