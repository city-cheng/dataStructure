#include <iostream>
using namespace std;

//线索二叉树
typedef struct ThreadNode{
    int data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;   //0表示指向孩子，1表示指向前驱和后继
}ThreadNode,*ThreadTree;

//初始化线索二叉树
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


//线索二叉树的中序后继
ThreadNode *InNext(ThreadNode *p){
    if(p == NULL){
        return NULL;
    }
    //有线索返回线索
    if(p->rtag == 1){
        return p->rchild;
    }

    //没有线索找右子树的最左下角
    ThreadNode *q = p->rchild;
    //由于rtag默认为0，所以右子树可能为NULL
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

//线索二叉树中序前驱
ThreadNode *InPrior(ThreadNode *p){
    if(p == NULL){
        return NULL;
    }

    //有线索返回线索
    if(p->ltag == 1){
        return p->lchild;
    }

    //没有线索找左子树的最右下角
    ThreadNode *q = p->lchild;
    //由于ltag默认为0，所以右左子树可能为NULL
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



//中序线索二叉树的左孩子插入
bool LInsert(ThreadNode *p,ThreadNode *q){
    if(p == NULL){
        return false;
    }
    //先正常插入
    q->lchild = p->lchild;
    q->ltag = p->ltag;

    p->lchild = q;
    p->ltag = 0;

    q->rchild = p;
    q->rtag = 1;
    //如果原来的结点有左孩子，则需要将原来节点的前驱节点的后继线索改为新节点
    if(q->ltag == 0){
        ThreadNode *s = InPrior(q);
    //由于ltag默认为0，所以左孩子可能为NULL
        if(s == NULL){
            return true;
        }
        s->rchild = q;
    }
    return true;
}

//中序线索二叉树的右孩子插入
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

    //如果原来结点有右孩子（此时变成了新节点的右孩子！！），则需要将原来结点的后继结点的前驱线索改为新节点
    if(q->rtag == 0){
        ThreadNode *s = InNext(q);
    //由于rtag默认为0，所以右孩子可能为NULL
        if(s == NULL){
            return true;
        }
        s->lchild = q;
    }
    return true;
}

//利用线索进行中序遍历
void PrintNode(ThreadNode *p){
    cout << p->data << " ";
}

//首先需要找到最左下的结点
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