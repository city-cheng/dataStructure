#include <iostream>
using namespace std;

#define MAXSIZE 1000
//定义顺序栈
typedef struct SqStack{
    char data[MAXSIZE];
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
bool Push(SqStack &S,char x){
	//判断栈是否已满 
	if(S.top == MAXSIZE - 1){
		return false; 
	}
	//每次进栈都要移动top指针 
//	S.top++;
//	S.data[S.top] = x;
	S.data[++S.top] = x;
	return true;
} 

//出栈操作
bool Pop(SqStack &S,char &x){
	if(S.top == -1){
		return false;
	}
//	x = S.data[S.top];
//	S.top--;
	x = S.data[S.top--];
	return true;	
} 

//进制转换
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
