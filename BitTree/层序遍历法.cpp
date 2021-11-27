#include <stdio.h>
#include <stdlib.h>

//二叉链表
typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

bool InitTree(BitTree root,int data){
	root = (BitTree)malloc(sizeof(BitNode));
	if(root == NULL){
		return false;
	}
	root->data = data;
	root->lchild = NULL;
	root->rchild = NULL;
	return true;
}

void printNode(BitNode *t){
	printf("%d\t",t->data);
} 


//链队列
typedef struct LinkNode{
	BitNode *data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
	LinkNode *front,*rear;
}LinkQueue;

bool InitQueue(LinkQueue &q){
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	if(p == NULL){
		return false;
	}
	q.front = q.rear = p;
	q.rear->next = NULL;
	return true;
}

bool isEmpty(LinkQueue q){
	return (q.front==q.rear);
}

bool EnQueue(LinkQueue &q,BitNode *e){
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	if(p == NULL){
		return false;
	}
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return true;	
}

bool DeQueue(LinkQueue &q,BitTree &x){
	if(q.front == q.rear){
		return false;
	}
	LinkNode *p = q.front->next;
	x = p->data;
	q.front->next = p->next;
	if(q.rear == p){
		q.rear = q.front;
	}
	free(p);
	return true;
}



//层序遍历法 
void LevelOrder(BitTree t){
	LinkQueue Q;
	InitQueue(Q);
	BitTree p;
	EnQueue(Q,t);
	while(!isEmpty(Q)){
		DeQueue(Q,p);
		printNode(p);
		if(p->lchild != NULL){
			EnQueue(Q,p->lchild);
		}
		if(p->rchild != NULL){
			EnQueue(Q,p->rchild);
		}
	}
}






