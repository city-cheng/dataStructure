#include <stdio.h>
#include <stdlib.h>

//普通二叉树 
typedef struct BitNode{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode,*BitTree;


//线索二叉树
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;    //线索的标志    0为指向孩子，1为指向前驱和后继 
}ThreadNode, *ThreadTree; 

//初始化线索二叉树
bool InitThreadTree(ThreadTree &tt){
	tt = (ThreadTree)malloc(sizeof(ThreadNode));
	if(tt == NULL){
		return false;
	}
	tt->lchild = tt->rchild = NULL;
	tt->ltag = tt->rtag = 0;    //先让所有的指针都指向真正的孩子结点 
	return true;
} 

 
 //正常的遍历操作
 void PrintNode(ThreadNode *t){
 	printf("%d",t->data);
 }
 
  
//中序遍历（线索）二叉树
bool MidOrder(ThreadTree tt){
	if(tt != NULL){
		MidOrder(tt->lchild);
		PrintNode(tt);
		MidOrder(tt->rchild);
	}	
	return true;
} 



//使用土方法获取当前节点的 中序 前驱
//辅助的全局变量
ThreadNode *p;      //指向目标节点
ThreadNode *pre = NULL;    //指向当前结点的前驱结点
ThreadNode *final = NULL;  //指向最终的结果结点 
//获取前驱的遍历操作
void visitPre(ThreadNode *q){
	if(q == p){
		final = pre;
	}
	else{
		pre = q;
	}
	
} 
//在中序遍历的同时，更新前驱结点 
ThreadNode *PreNode(ThreadTree T){
	if(T != NULL){
		MidOrder(T);
		visitPre(T->lchild);
		MidOrder(T->rchild);
	}
	return final;
} 


//二叉树的中序线索化 
//全局变量pre
ThreadNode *pre = NULL; 
//中序线索化的遍历操作
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

//在中序遍历的同时线索化二叉树 
void InThread(ThreadTree T){
	if(T != NULL){
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
} 

//中序线索化的主函数
void CreateInThread(ThreadTree T){
	pre = NULL;
	if(T != NULL){        //非空二叉树才能线索化 
		InThread(T);
		if(pre->rchild = NULL){
			pre->rtag = 1;      //处理最后一个结点 
		}
	}
} 






