#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
//顺序（循环）队列 
typedef struct SqQueue{
	int data[MaxSize];
	int rear;
	int front;
	int tar;
}SqQueue;

//初始化队列
bool InitQueue(SqQueue &q){
	q.tar = 0;
	q.rear = q.front = 0;
	return true;
} 

//入队操作
bool EnQueue(SqQueue &q,int e){
	if(q.front == q.rear && q.tar == 1){
		return false;
	}
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % MaxSize;
	q.tar = 1;
	return true;
} 

//出队操作
bool DeQueue(SqQueue &q,int &x){
	if(q.front == q.rear && q.tar == 0){
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	q.tar = 0;
	return true;
} 

//判断队列是否为空
bool QueueEmpty(SqQueue q){
	return (q.front == q.rear && q.tar == 0);
} 

//判断队列是否已满 
bool QueueFull(SqQueue q){
	return (q.front == q.rear && q.tar == 1);
}

int main(){
	SqQueue q;
	InitQueue(q);
	EnQueue(q,6);
	EnQueue(q,7);
	EnQueue(q,8);
	EnQueue(q,9);
	int x;
	DeQueue(q,x);
	printf("%d	",x);
	DeQueue(q,x);
	printf("%d",x);
	return 0;
}

