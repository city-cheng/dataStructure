#include <stdio.h> 
#include <stdlib.h>

#define MaxSize 20
//ջ��Ӧ��   ����ƥ�� 

//˳��ջ 
typedef struct SqStack{
	char data[MaxSize];
	int top;
}SqStack;

bool InitStack(SqStack &s){
	s.top = -1;
	return true;
}

//��ջ
bool Push(SqStack &s,char e){
	if(s.top == MaxSize - 1){
		return false;
	}
	s.data[++s.top] = e;
	return true;
} 

bool Pop(SqStack &s,char &x){
	if(s.top == -1){
		return false;
	}
	x = s.data[s.top--];
	return true;
}

//����ջ
bool EmptyStack(SqStack s){
	return s.top == -1;
} 


bool Check(char ss[],int length){
	SqStack s;
	InitStack(s);
	// char ss[MaxSize] = "()";
	for(int i = 0;i < length;i++){
		if(ss[i] == '(' || ss[i] == '[' || ss[i] == '{'){
			Push(s,ss[i]);
		}else{
			if(EmptyStack(s)){
				return false;
			}
			char a;
			Pop(s,a);
			if(ss[i] == ')' && a != '('){
				return false;
			}
			if(ss[i] == ']' && a != '['){
				return false;
			}
			if(ss[i] == '}' && a != '{'){
				return false;
			}
		}		
		
	}
	return EmptyStack(s);
}

int main(){
	char str[] = "(){}";
	if(Check(str,4)){
		printf("�﷨��ȷ��");
	}else{
		printf("�﷨����");
	}
	return 0;
}
	
	
	
