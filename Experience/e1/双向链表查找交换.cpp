#include <iostream>
using namespace std;

//˫������
typedef struct DLNode{
    int data;
    struct DLNode *next,*prior;
}DLNode,*DLinkList;

//��ʼ��˫������(��ͷ���)
bool InitList(DLinkList &L){
    L = (DLNode *)malloc(sizeof(DLinkList));
    if(L == NULL){
        return false;
    }
    L->next = NULL;
    L->prior = NULL;
    return true;
}

//�ж�˫�����Ƿ�Ϊ�� 
bool Empty(DLinkList L){
	if(L->next == NULL){
		return true;
	}
	return false;
}


//����ڵ�
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

//ɾ��p�ڵ�ĺ�̽ڵ�
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

//��ֵ����
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

//���Ҳ�����
int Swap(DLinkList &L,int x){
    DLNode *p = LocateNode(L,x);
    if(p == NULL){
        return 0;
    }
    DLNode *q = p->prior;
    if(q == NULL){
        //�����һ���ڵ���Ҫ�ҵĽڵ㣬��ôû��ǰ���ڵ�ɹ�����������0
        return 0;
    }
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
    return 1;
}


//��ӡ˫������
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
