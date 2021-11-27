#include <iostream>
using namespace std;

//双向链表
typedef struct DLNode{
    int data;
    struct DLNode *next,*prior;
}DLNode,*DLinkList;

//初始化双向链表(带头结点)
bool InitList(DLinkList &L){
    L = (DLNode *)malloc(sizeof(DLinkList));
    if(L == NULL){
        return false;
    }
    L->next = NULL;
    L->prior = NULL;
    return true;
}

//判断双链表是否为空 
bool Empty(DLinkList L){
	if(L->next == NULL){
		return true;
	}
	return false;
}


//插入节点
bool InsertNextNode(DLNode *p,int e){
    if(p == NULL){
        return false;
    }
    DLNode *s = (DLNode *)malloc(sizeof(DLNode));
    if(s == NULL){
        return false;
    }
    s->data = e;

    s->next = p->next;
    p->next = s;
    s->prior = p;
    if(s->next != NULL){
        s->next->prior = s;
    }
    return true;

}

//删除p节点的后继节点
bool DeleteNextNode(DLNode *p){
    if(p == NULL){
        return false;
    }
    DLNode *q = p->next;
    if(q == NULL){
        return false;
    }
    p->next = q->next;
    if(q->next != NULL){
        q->next->prior = p;
    }
    free(q);
    return true;
}

//按值查找
DLNode *LocateNode(DLinkList L,int e){
    DLNode *p = L->next;
    while(p != NULL){
        if(p->data == e){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//查找并交换
int Swap(DLinkList &L,int x){
    DLNode *p = LocateNode(L,x);
    if(p == NULL){
        return 0;
    }
    DLNode *q = p->prior;
    if(q == NULL){
        //如果第一个节点是要找的节点，那么没有前驱节点可供交换，返回0
        return 0;
    }
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
    return 1;
}


//打印双向链表
void ShowList(DLinkList L){
    DLNode *p = L->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    DLinkList L;
    InitList(L);
    DLNode *p = L;
    for(int i = 0;i < 10;i++){
        InsertNextNode(p,i);
        p = p->next;
    }
    ShowList(L);

    int a = Swap(L,3);
    cout << a << endl;
    ShowList(L);
    
}
