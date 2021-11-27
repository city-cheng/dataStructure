#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//��������˳��洢ʵ��
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


//��������
typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode, *BitTree; 
//�����յĸ��ڵ� 
BitTree root = NULL;
//��ʼ�������� 
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

//�����µĽ�㣨���ӣ� 
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


//���и��ڵ�ָ�����ʽ�洢����������
typedef struct BitNode_{
	int data;
	BitNode_ *lchild,*rchild;
	BitNode_ *parent; 
}BitNode_,*BitTree_;








