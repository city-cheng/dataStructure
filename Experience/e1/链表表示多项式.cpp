#include <iostream>
using namespace std;

#include <vector>


//�����������洢����ʽ��ϵ����ָ��
//coef�洢һ�����ʽ��ϵ��
//exp�洢һ�����ʽ��ָ��
typedef struct LNode{
    int coef;
    int exp;
    struct LNode *next;
}LNode,*LinkList;

//��ʼ������(��ͷ���)
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL){
        return false;
    }
    L->next = NULL;
    return true;
}

//�жϿձ�
bool IsEmpty(LinkList L){
    return L->next == NULL;
}


//����ڵ�
bool InsertNextNode(LNode *p,int coefData,int expData){
    if(p == NULL){
        return false;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    if(q == NULL){
        return false;
    }
    q->coef = coefData;
    q->exp = expData;
    q->next = p->next;
    p->next = q;
    return true;
}

//ɾ��ָ���ڵ�
bool DeleteNode(LNode *p){
    if(p == NULL){
        return false;
    }
    int tempCoef = p->coef;
    int tempExp = p->exp;
    LNode *q = p->next;
    p->coef = q->coef;
    p->exp = q->exp;
    q->coef = tempCoef;
    q->exp = tempExp;
    
    p->next = q->next;
    free(q);
    return true;
}

//��ӡ����ʽ����
void showLinkList(LinkList L){
    LNode *p = L->next;
    while(p->next != NULL){
        if(p->exp == 1){
        cout << p->coef << "*X" << " + " ;
        }else{
        cout << p->coef << "*X^" << p->exp << " + " ;
        }
        p = p->next;

    }
    if(p->exp == 1){
        cout << p->coef << "*X" << endl;
        p = p->next;
    }else if(p->exp == 0){
        cout << p->coef << endl;
    }
}

//����ʽ�ӷ�
//�������ʽ���ݴ洢
LinkList PolyAdd(LinkList L1,LinkList L2){
    LNode *p = L1->next;
    LNode *q = L2->next;
    LinkList result;
    InitList(result);
    LNode *r = result;

    if(p == NULL){
        return L2;
    }else if(q == NULL){
        return L1;
    }

    while(p != NULL || q != NULL){
        if(p == NULL){
            InsertNextNode(r,q->coef,q->exp);
            q = q->next;
            r = r->next;
        }else if(q == NULL){
            InsertNextNode(r,p->coef,p->exp);
            p = p->next;
            r = r->next;
        }else if(p->exp == q->exp){
            //ָ�������ϵ�����
            InsertNextNode(r,p->coef + q->coef,p->exp);
            p = p->next;
            q = q->next;
            r = r->next;
        }else if(p->exp > q->exp){
            InsertNextNode(r,p->coef,p->exp);
            p = p->next;
            r = r->next;
        }else{
            InsertNextNode(r,q->coef,q->exp);
            q = q->next;
            r = r->next;
        }
    }
    return result;
}

//һ���������ʽ�ĳ˷�����
LinkList Multiply(LNode *p,LinkList L){
    LNode *q = L->next;
    LinkList result;
    InitList(result);
    LNode *r = result;
    
    while(q != NULL){
        //����ÿһ������ʽ�ڵ�Ԫ��,ϵ�����,ָ�����
        int coef = p->coef * q->coef;
        int exp = p->exp + q->exp;
        InsertNextNode(r,coef,exp);
        r = r->next;
        q = q->next;
    }
    return result;
}

//����ʽ�����ʽ�ĳ˷�
LinkList PolyMulti(LinkList L1,LinkList L2){
    LNode *p = L1->next;
    // LNode *q = L2->next;
    LinkList result;
    InitList(result);

    if(IsEmpty(L1) || IsEmpty(L2)){
        //��ʱresultΪ�գ�����ֱ�ӷ��ر�ʾ0
        return result;
    }

    while(p != NULL){
        LinkList L = Multiply(p,L2);
        result = PolyAdd(result,L);
        p = p->next;
    }
    return result;
}

//�������鹹������ʽ����
LinkList CreatePoly(int a[],int n){
    LinkList L;
    InitList(L);
    LNode *p = L;
    for(int i = 0;i < n;i += 2){
        InsertNextNode(p,a[i],a[i + 1]);
        p = p->next;
    }
    return L;

}

int main(){
    int a[] = {4,3,2,1,1,0};
    int b[] = {7,3,5,2,3,0};
    LinkList L1 = CreatePoly(a,6);
    showLinkList(L1);
    LinkList L2 = CreatePoly(b,6);
    showLinkList(L2);

    LinkList L3 = PolyAdd(L1,L2);
    showLinkList(L3);

    LinkList L4 = PolyMulti(L1,L2);
    showLinkList(L4);

    

}