#include <stdio.h>
#include <stdlib.h>

//链栈
typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;

//链栈初始化（带头结点）
bool InitStack(LinkStack &S){
	S = (StackNode *)malloc(sizeof(StackNode));
	if(S == NULL){
		return false;
	}
	S->next = NULL;
	return true;
}

//链栈的入栈操作
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

//链栈的出栈操作
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

//获取栈顶元素
int GetTop(LinkStack S){
	return S->next->data;
} 

//判断栈空栈满
bool Empty(LinkStack S) {
	if(S->next == NULL){
		return true;
	}
	return false;
}










