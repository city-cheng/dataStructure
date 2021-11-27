#include <stdio.h>

#define MaxSize 10
//顺序栈
typedef struct{
	int data[MaxSize];
	int top;
}SqStack; 

//初始化顺序栈 
bool InitStack(SqStack &S){
	S.top = -1;
	return true;
}

//判断空栈
bool Empty(SqStack S){
	if(S.top == -1){
		return true;
	}
	return false;
} 

//进栈操作
bool Push(SqStack &S,int x){
	//判断栈是否已满 
	if(S.top == MaxSize - 1){
		return false; 
	}
	//每次进栈都要移动top指针 
//	S.top++;
//	S.data[S.top] = x;
	S.data[++S.top] = x;
	return true;
} 

//出栈操作
bool Pop(SqStack &S,int &x){
	if(S.top == -1){
		return false;
	}
//	x = S.data[S.top];
//	S.top--;
	x = S.data[S.top--];
	return true;	
} 
 
 
 

