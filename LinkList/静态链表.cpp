#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
//��̬����
//��ʽһ������ڵ㣬�ڳ�����ʹ�ýṹ������ 
struct Node{
	int data;
	int next;
}; 

void testLinkList(){
	struct Node a[MaxSize];
	printf("size1=%d\n",sizeof(a));
} 

//��ʽ����ֱ�ӽ��ṹ������typedef�� SLinkList
typedef struct {
	int data;
	int next;
}SLinkList[MaxSize]; 

int main(){
	testLinkList();
	SLinkList b;
	printf("size2=%d",sizeof(b));
}
//��ʽһ�Ƚϳ����� 
