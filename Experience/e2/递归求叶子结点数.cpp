#include <iostream>
using namespace std;

//�����������
typedef struct BitNode{
    int data;
    struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

//��ʼ��������
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


//����µĽ��
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

//��ӡ���
void PrintNode(BitNode *p){
    if(p == NULL){
        return;
    }else{
        cout << p->data << " ";
    }
    cout << endl;
}

//ǰ�����
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


//�ݹ���Ҷ�ӽ����
void LeafNumVisit(BitNode *p,int &num){
    if(p->rchild == NULL && p->lchild == NULL){
        num++;
    }
}


int LeafNum(BitTree root){
    static int num = 0;  //ȫ�ֱ���������¼Ҷ�ӽ�������
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
