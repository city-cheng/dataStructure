#include <stdio.h>
#include <stdlib.h> 

//二叉链表
typedef struct BitNode {
	int data;
	struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

bool InitTree(BitTree &root,int data){
	root = (BitTree)malloc(sizeof(BitNode));
	if(root == NULL){
		return false;
	}
	root->data = data;
	root->lchild = root->rchild = NULL;
	return true;
} 

void PrintBitNode(BitNode *t){
	printf("%d\t",t->data);
}

//前序遍历法 
bool PreOrder(BitTree t){
	while(t != NULL){
		PrintBitNode(t);
		if(t->lchild != NULL){
			PreOrder(t->lchild);		
		}
		if(t->rchild != NULL){
			PreOrder(t->rchild);
		}
	}
}




//链队列（带头结点）
typedef struct LinkNode {
	BitNode *data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
	LinkNode *rear,*front;
}LinkQueue;

bool InitQueue(LinkQueue &q){
	LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
	if(p == NULL){
		return false;
	}
	p->next = NULL;
	q.front = q.rear = p;
	return true;
}

//入队
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

//出队
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

bool isEmpty(LinkQueue q){
	return (q.front == q.rear);
}





//二叉树的层序遍历算法
void LevelOrder(BitTree T){
	LinkQueue q;
	InitQueue(q);
	BitTree t;
	InitTree(t,1);
	EnQueue(q,T);
	while(!isEmpty(q)){
		DeQueue(q,t);
		PrintBitNode(t);
		if(t->lchild != NULL){
		EnQueue(q,t->lchild);
		}
		if(t->rchild != NULL){
			EnQueue(q,t->rchild);
		}
	}
	
	
} 


int main(){
	return 0;
}












