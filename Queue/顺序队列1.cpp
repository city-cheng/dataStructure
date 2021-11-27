#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20

//队列的顺序实现
typedef struct SqQueue{
	int data[MaxSize];
	int rear;
	int front;
	int size;
}SqQueue;

//初始化队列(rear指向队尾元素)
bool InitQueue(SqQueue &q){
	q.rear = MaxSize - 1;
	q.front = 0;
	q.size = 0;
	return true;
} 

//入队操作
bool EnQueue(SqQueue &q,int e){
	if(((q.rear + 1) % MaxSize == q.front) && q.size == MaxSize - 1){
		return false;
	}
	q.rear = (q.rear + 1) % MaxSize;
	q.data[q.rear] = e;
	q.size = (q.size + 1) % MaxSize;
	return true;
}

//出队操作
bool DeQueue(SqQueue &q,int &x){
	if(((q.rear + 1) % MaxSize == q.front) && q.size == 0){
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	q.size = (q.size - 1) % MaxSize; 
	return true;
} 


int main(){
	SqQueue q;
	InitQueue(q);
	EnQueue(q,2);
	EnQueue(q,3);
	EnQueue(q,4);
	int x;
	DeQueue(q,x);
	printf("%d",x);
	return 0; 
} 
