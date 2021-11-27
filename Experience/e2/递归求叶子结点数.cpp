#include <iostream>
using namespace std;

//定义二叉链表
typedef struct BitNode{
    int data;
    struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

//初始化二叉树
bool InitTree(BitTree &root){
    root = (BitNode *)malloc(sizeof(BitNode));
    if(root == NULL){
        return false;
    }
    root->data = 0;
    root->lchild = NULL;
    root->rchild = NULL;
    return true;
}


//添加新的结点
bool InsertNode(BitNode *root,int data){
    if(root == NULL){
        return false;
    }

    BitNode *p = (BitNode *)malloc(sizeof(BitNode));
    if(p == NULL){
        return false;
    }
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    if(root->lchild == NULL){
        root->lchild = p;   
    }else if(root->rchild == NULL){
        root->rchild = p;
    }else{
        return false;
    }
    return true;
    
}

//打印结点
void PrintNode(BitNode *p){
    if(p == NULL){
        return;
    }else{
        cout << p->data << " ";
    }
    cout << endl;
}

//前序遍历
bool PreOrder(BitTree root){
    if(root != NULL){
        PrintNode(root);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }else{
        return true;
    }
    return false;
}


//递归求叶子结点数
void LeafNumVisit(BitNode *p,int &num){
    if(p->rchild == NULL && p->lchild == NULL){
        num++;
    }
}


int LeafNum(BitTree root){
    static int num = 0;  //全局变量用来记录叶子结点的数量
    if(root == NULL){
        return 0;
    }
    LeafNumVisit(root,num);
    if(root->lchild != NULL){
        LeafNum(root->lchild);
    }
    if(root->rchild != NULL){
        LeafNum(root->rchild);
    }

    return num;
}

int main(){
    BitTree T;
    InitTree(T);
    InsertNode(T,1);
    InsertNode(T,2);
    InsertNode(T->lchild,3);
    InsertNode(T->lchild,4);
    InsertNode(T->rchild,5);
    InsertNode(T->rchild,6);

    int num;
    num = LeafNum(T);
    cout << num << endl;
}
