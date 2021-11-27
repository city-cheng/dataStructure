#include <stdio.h>
#include <stdlib.h>

//����������
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;
}ThreadNode, *ThreadTree;

//��ʼ������������ 
bool InitTree(ThreadTree &T){
	T = (ThreadTree)malloc(sizeof(ThreadNode));
	if(T == NULL){
		return false;
	}
	T->lchild = T->rchild = NULL;
	T->ltag = T->rtag = 0;
	return true;
}

//�����ı�����������ӡ���� 
void PrintNode(ThreadNode *p){
	printf("%d\t",p->data);
}

//���������
bool MidOrder(ThreadTree T){
	if(T != NULL){
		MidOrder(T->lchild);
		PrintNode(T);
		MidOrder(T->rchild);
	}
	return true;
} 

//�������ҵ�ǰ����ǰ�����
//������ȫ�ֱ���
ThreadNode *p;     //ָ��Ŀ��ڵ� 
ThreadNode *pre = NULL;   //ָ��ǰ�����
ThreadNode *final = NULL; //ָ���������Ľ�����
//��ǰ�����ı�������
void PreVisit(ThreadNode *q){
	if(q = p){
		final = pre;
	}
	else{
		pre = q;
	}
}
//�����������Ѱ��ǰ�����
ThreadNode *PreNode(ThreadTree T){
	if(T != NULL){
		PreNode(T->lchild);
		PreVisit(T);
		PreNode(T->rchild);
	}
	return final;
}


//������������������ 
//ȫ�ֱ���pre
ThreadNode *pre = NULL;
//�����������ı������� 
void ThreadVisit(ThreadNode *q){
	if(q->rchild == NULL){
		q->lchild = pre;
		q->ltag = 1;
	}
	if(pre != NULL && pre->rchild == NULL){
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}
//�����������������������
bool InThread(ThreadTree T){
	if(T != NULL){
		InThread(T->lchild);
		ThreadVisit(T);
		InThread(T->rchild);
	}
	return true;
	
} 

//������������������
void CreateThread(ThreadTree T){
	if(T != NULL){
		InThread(T);
		if(pre->rchild == NULL){
			pre->rtag = 1;
		}
	}
} 











