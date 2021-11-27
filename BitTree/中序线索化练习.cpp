#include <stdio.h>
#include <stdlib.h>

//线索二叉树
typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;
}ThreadNode, *ThreadTree;

//初始化线索二叉树 
bool InitTree(ThreadTree &T){
	T = (ThreadTree)malloc(sizeof(ThreadNode));
	if(T == NULL){
		return false;
	}
	T->lchild = T->rchild = NULL;
	T->ltag = T->rtag = 0;
	return true;
}

//正常的遍历操作，打印数据 
void PrintNode(ThreadNode *p){
	printf("%d\t",p->data);
}

//中序遍历法
bool MidOrder(ThreadTree T){
	if(T != NULL){
		MidOrder(T->lchild);
		PrintNode(T);
		MidOrder(T->rchild);
	}
	return true;
} 

//土方法找当前结点的前驱结点
//辅助的全局变量
ThreadNode *p;     //指向目标节点 
ThreadNode *pre = NULL;   //指向前驱结点
ThreadNode *final = NULL; //指向最后输出的结果结点
//找前驱结点的遍历操作
void PreVisit(ThreadNode *q){
	if(q = p){
		final = pre;
	}
	else{
		pre = q;
	}
}
//在中序遍历中寻找前驱结点
ThreadNode *PreNode(ThreadTree T){
	if(T != NULL){
		PreNode(T->lchild);
		PreVisit(T);
		PreNode(T->rchild);
	}
	return final;
}


//二叉树的中序线索化 
//全局变量pre
ThreadNode *pre = NULL;
//中序线索化的遍历操作 
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
//在中序遍历中线索化二叉树
bool InThread(ThreadTree T){
	if(T != NULL){
		InThread(T->lchild);
		ThreadVisit(T);
		InThread(T->rchild);
	}
	return true;
	
} 

//中序线索化的主函数
void CreateThread(ThreadTree T){
	if(T != NULL){
		InThread(T);
		if(pre->rchild == NULL){
			pre->rtag = 1;
		}
	}
} 











