#include <iostream>
using namespace std;

//����������
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;   //0��ʾָ���ӣ�1��ʾָ��ǰ���ͺ��
}ThreadNode,*ThreadTree;

//��ʼ������������
bool InitThreadTree(ThreadTree &T){
    T = (ThreadNode *)malloc(sizeof(ThreadNode));
    if(T == NULL){
        return false;
    }
    T->data = 0;
    T->lchild = T->rchild  = NULL;
    T->ltag = T->rtag = 0;
    return true;
}


//������������������
ThreadNode *InNext(ThreadNode *p){
    if(p == NULL){
        return NULL;
    }
    //��������������
    if(p->rtag == 1){
        return p->rchild;
    }

    //û���������������������½�
    ThreadNode *q = p->rchild;
    //����rtagĬ��Ϊ0����������������ΪNULL
    if(q == NULL){
        return NULL;
    }
    if(p->rtag == 0){
        while(q->ltag == 0){
            q = q->lchild;
        }
    }
    return q;
}

//��������������ǰ��
ThreadNode *InPrior(ThreadNode *p){
    if(p == NULL){
        return NULL;
    }

    //��������������
    if(p->ltag == 1){
        return p->lchild;
    }

    //û���������������������½�
    ThreadNode *q = p->lchild;
    //����ltagĬ��Ϊ0������������������ΪNULL
    if(q == NULL){
        return NULL;
    }
    if(p->ltag == 0){
        while(q->rtag == 0){
            q = q->rchild;
        }
    }
    return q;
}



//�������������������Ӳ���
bool LInsert(ThreadNode *p,ThreadNode *q){
    if(p == NULL){
        return false;
    }
    //����������
    q->lchild = p->lchild;
    q->ltag = p->ltag;

    p->lchild = q;
    p->ltag = 0;

    q->rchild = p;
    q->rtag = 1;
    //���ԭ���Ľ�������ӣ�����Ҫ��ԭ���ڵ��ǰ���ڵ�ĺ��������Ϊ�½ڵ�
    if(q->ltag == 0){
        ThreadNode *s = InPrior(q);
    //����ltagĬ��Ϊ0���������ӿ���ΪNULL
        if(s == NULL){
            return true;
        }
        s->rchild = q;
    }
    return true;
}

//�����������������Һ��Ӳ���
bool RInsert(ThreadNode *p,ThreadNode *q){
    if(p == NULL){
        return false;
    }
    q->rchild = p->rchild;
    q->rtag = p->rtag;

    p->rchild = q;
    p->rtag = 0;

    q->lchild = p;
    q->ltag = 1;

    //���ԭ��������Һ��ӣ���ʱ������½ڵ���Һ��ӣ�����������Ҫ��ԭ�����ĺ�̽���ǰ��������Ϊ�½ڵ�
    if(q->rtag == 0){
        ThreadNode *s = InNext(q);
    //����rtagĬ��Ϊ0�������Һ��ӿ���ΪNULL
        if(s == NULL){
            return true;
        }
        s->lchild = q;
    }
    return true;
}

//�������������������
void PrintNode(ThreadNode *p){
    cout << p->data << " ";
}

//������Ҫ�ҵ������µĽ��
ThreadNode *FirstNode(ThreadTree root){
    ThreadNode *p = root;
    while(p->ltag == 0 && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

bool InOrder(ThreadTree root){
    if(root == NULL){
        return false;
    }
    for(ThreadNode *p = FirstNode(root);p != NULL;p = InNext(p)){
        PrintNode(p);
    }
    return false;
}

int main(){
    ThreadTree root;
    InitThreadTree(root);
    for(int i = 1;i < 4;i++){
        ThreadNode *p = (ThreadNode *)malloc(sizeof(ThreadNode));
        p->data = i;
        p->lchild = p->rchild = NULL;
        LInsert(root,p);
    }
    for(int i = 1;i < 4;i++){
        ThreadNode *q = (ThreadNode *)malloc(sizeof(ThreadNode));
        q->data = i;
        q->lchild = q->rchild = NULL;
        RInsert(root,q);
    }
    InOrder(root);
    return 0;
}