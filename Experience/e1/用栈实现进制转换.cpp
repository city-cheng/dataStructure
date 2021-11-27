#include <iostream>
using namespace std;

#define MAXSIZE 1000
//����˳��ջ
typedef struct SqStack{
    char data[MAXSIZE];
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
bool Push(SqStack &S,char x){
	//�ж�ջ�Ƿ����� 
	if(S.top == MAXSIZE - 1){
		return false; 
	}
	//ÿ�ν�ջ��Ҫ�ƶ�topָ�� 
//	S.top++;
//	S.data[S.top] = x;
	S.data[++S.top] = x;
	return true;
} 

//��ջ����
bool Pop(SqStack &S,char &x){
	if(S.top == -1){
		return false;
	}
//	x = S.data[S.top];
//	S.top--;
	x = S.data[S.top--];
	return true;	
} 

//����ת��
void convert(int num,SqStack &S,int n){
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int a,b;
    while(num != 0){
        b = num % n;
        if(b >= 10){
            Push(S,str[b - 10]);
        }else{
            Push(S,(char)(b + 48));
        }
        num = (num - b) / n;
    }
}

int main(){
    SqStack S;
    InitStack(S);
    convert(31,S,16);
    char x;
    while(Pop(S,x)){
        cout << x;
    }
    cout <<endl;

}
