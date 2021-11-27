#include <stdio.h>
#include <stdlib.h>

//��ͨ������ 
typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode,*BitTree;


//����������
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;    //�����ı�־    0Ϊָ���ӣ�1Ϊָ��ǰ���ͺ�� 
}ThreadNode, *ThreadTree; 

//��ʼ������������
bool InitThreadTree(ThreadTree &tt){
	tt = (ThreadTree)malloc(sizeof(ThreadNode));
	if(tt == NULL){
		return false;
	}
	tt->lchild = tt->rchild = NULL;
	tt->ltag = tt->rtag = 0;    //�������е�ָ�붼ָ�������ĺ��ӽ�� 
	return true;
} 

 
 //�����ı�������
 void PrintNode(ThreadNode *t){
 	printf("%d",t->data);
 }
 
  
//���������������������
bool MidOrder(ThreadTree tt){
	if(tt != NULL){
		MidOrder(tt->lchild);
		PrintNode(tt);
		MidOrder(tt->rchild);
	}	
	return true;
} 



//ʹ����������ȡ��ǰ�ڵ�� ���� ǰ��
//������ȫ�ֱ���
ThreadNode *p;      //ָ��Ŀ��ڵ�
ThreadNode *pre = NULL;    //ָ��ǰ����ǰ�����
ThreadNode *final = NULL;  //ָ�����յĽ����� 
//��ȡǰ���ı�������
void visitPre(ThreadNode *q){
	if(q == p){
		final = pre;
	}
	else{
		pre = q;
	}
	
} 
//�����������ͬʱ������ǰ����� 
ThreadNode *PreNode(ThreadTree T){
	if(T != NULL){
		MidOrder(T);
		visitPre(T->lchild);
		MidOrder(T->rchild);
	}
	return final;
} 


//������������������ 
//ȫ�ֱ���pre
ThreadNode *pre = NULL; 
//�����������ı�������
void visit(ThreadNode *q){
	if(q->lchild == NULL){
		q->lchild = pre;
		q->ltag = 1;
	}
	if(pre != NULL &&pre->rchild == NULL){
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

//�����������ͬʱ������������ 
void InThread(ThreadTree T){
	if(T != NULL){
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
} 

//������������������
void CreateInThread(ThreadTree T){
	pre = NULL;
	if(T != NULL){        //�ǿն��������������� 
		InThread(T);
		if(pre->rchild = NULL){
			pre->rtag = 1;      //�������һ����� 
		}
	}
} 






