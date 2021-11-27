#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//��������˳��洢
typedef struct{
	int data;
	bool isEmpty;
}TreeNode;

TreeNode t[MAXSIZE];
bool InitTree(TreeNode t[]) {
	for(int i = 0;i < MAXSIZE;i++){
		t[i].isEmpty = true;
	}
	return true;
} 

//����������ʽ�洢����������
typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode, *BitTree;

//����һ�������
BitTree root = NULL;

//��ʼ��������
bool InitBitTree(BitTree root){
	root = (BitTree)malloc(sizeof(BitNode));
	if(root == NULL){
		return false;
	}
	root->data = 1;
	root->lchild = NULL;
	root->rchild = NULL;
	return true;
} 

//�����½ڵ㣨���ӣ�
bool InsertNode(BitNode root,int data){
	BitNode *p = (BitNode *)malloc(sizeof(BitNode));
	if(p == NULL){
		return false;
	}
	p->data = data;
	p->lchild = NULL;
	p->rchild = NULL;
	root.lchild = p;
	return true;
} 


//���и��ڵ�ָ�����ʽ�洢����������
typedef struct BitNode_{
	int data;
	struct BitNode_ *lchild,*rchild;
	struct BitNode_ *parent;
}BitNode_,*BitTree_;





 




