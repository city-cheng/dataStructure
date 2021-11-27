#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//二叉树的顺序存储实现
struct TreeNode {
	int value;
	bool isEmpty;
};

TreeNode t[MAXSIZE];

bool InitTree(TreeNode t[]){
	for(int i = 0;i <MAXSIZE;i++){
		t[i].isEmpty = true;
	}
	return true;
}


//二叉链表
typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode, *BitTree; 
//创建空的根节点 
BitTree root = NULL;
//初始化二叉树 
bool InitBitTree(BitTree root){
	root = (BitTree) malloc(sizeof(BitNode));
	if(root == NULL){
		return false;
	}
	root->data = 1;
	root->lchild = NULL;
	root->rchild = NULL;
	return true;
}

//插入新的结点（左孩子） 
bool InsertNode(BitNode *root,int data){
	BitNode *p = (BitNode *)malloc(sizeof(BitNode));
	if(p == NULL){
		return false;
	}
	p->data = data;
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;
	return true;
}


//带有父节点指针的链式存储（三叉链表）
typedef struct BitNode_{
	int data;
	BitNode_ *lchild,*rchild;
	BitNode_ *parent; 
}BitNode_,*BitTree_;








