#include <stdio.h>

#define MaxSize 10
//˳��ջ
typedef struct{
	int data[MaxSize];
	int top;
}SqStack; 

//��ʼ��˳��ջ 
bool InitStack(SqStack &S){
	S.top = -1;
	return true;
}

//�жϿ�ջ
bool Empty(SqStack S){
	if(S.top == -1){
		return true;
	}
	return false;
} 

//��ջ����
bool Push(SqStack &S,int x){
	//�ж�ջ�Ƿ����� 
	if(S.top == MaxSize - 1){
		return false; 
	}
	//ÿ�ν�ջ��Ҫ�ƶ�topָ�� 
//	S.top++;
//	S.data[S.top] = x;
	S.data[++S.top] = x;
	return true;
} 

//��ջ����
bool Pop(SqStack &S,int &x){
	if(S.top == -1){
		return false;
	}
//	x = S.data[S.top];
//	S.top--;
	x = S.data[S.top--];
	return true;	
} 
 
 
 

