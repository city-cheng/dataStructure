#include <stdio.h>
#include <stdlib.h>

//二叉链表
typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode ,*BitTree; 

bool InitTree(BitTree &root,int data){
	root = (BitTree)malloc(sizeof(BitNode));
	if(root == NULL){
		return false;
	}
	root->data = data;
	root->lchild = NULL;
	root->rchild = NULL;
	return true;
}

bool InsertNode(BitTree &root,int data){
	BitNode *p = (BitNode *)malloc(sizeof(BitNode));
	if(p == NULL){
		return false;
	}
	p->data = data;
	p->lchild = NULL;
	p->rchild = NULL;
	if(root->lchild == NULL){
		root->lchild = p;	
	}else{
		root->rchild = p;
	}
	return true;
}

void PrintNode(BitNode *t){
	printf("%d\t",t->data);
}

//前序遍历法
bool PreOrder(BitTree root){
	if(root != NULL){
		PrintNode(root);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
	return true;
} 

















