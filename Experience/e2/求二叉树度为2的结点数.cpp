#include <iostream>
using namespace std;

#include <queue>



//���������(��ʽ�洢)
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

//���������
//ʹ��STL��queue����
bool LevelOrder(BitTree root){
    if(root == NULL){
        return false;
    }
    queue<BitNode *> Q;
    Q.push(root);
    while(!Q.empty()){
        BitNode *p = Q.front();
        Q.pop();
        PrintNode(p);
        if(p->lchild != NULL){
            Q.push(p->lchild);
        }
        if(p->rchild != NULL){
            Q.push(p->rchild);
        }
    }
    return true;
}

//���Ϊ2�Ľ����
void Count2Visit(BitNode *p,int &num){
    if(p->lchild != NULL && p->rchild != NULL){
        num += 1;
    }
}

// bool PreOrderCount2(BitTree root,int &num){
//     if(root != NULL){
//         Count2Visit(root,num);
//         PreOrderCount2(root->lchild,num);
//         PreOrderCount2(root->rchild,num);
//     }else{
//         return true;
//     }
//     return false;
// }


// int Count2(BitTree root){
//     static int num = 0;
//     PreOrderCount2(root,num);
//     return num;
// }


int Count2(BitTree root){
    static int num = 0;
    if(root == NULL){
        return 0;
    }
    Count2Visit(root,num);
    if(root->lchild != NULL){
        Count2(root->lchild);
    }
    if(root->rchild != NULL){
        Count2(root->rchild);
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
    num = Count2(T);
    cout << num << endl;
}