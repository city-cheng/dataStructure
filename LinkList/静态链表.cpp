#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
//静态链表
//方式一：定义节点，在程序中使用结构体数组 
struct Node{
	int data;
	int next;
}; 

void testLinkList(){
	struct Node a[MaxSize];
	printf("size1=%d\n",sizeof(a));
} 

//方式二：直接将结构体数组typedef成 SLinkList
typedef struct {
	int data;
	int next;
}SLinkList[MaxSize]; 

int main(){
	testLinkList();
	SLinkList b;
	printf("size2=%d",sizeof(b));
}
//方式一比较常见。 
