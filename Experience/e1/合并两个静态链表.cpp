#include <iostream>
using namespace std;

#define MAXSIZE 1000

//���徲̬����
typedef struct{
    int data;
    int next;
}SLNode,SLinkList[MAXSIZE];

//��ʼ����̬����
//���洢�������нڵ�����Ϊ����
void InitSLinkList(SLinkList &L){
    //�������еĸ����ڵ�����������L[0]Ϊͷ�ڵ�
    //NULL��0��ʾ
    for(int i = 0;i < MAXSIZE - 1;i++){
        L[i].next = i + 1;
    }
    L[MAXSIZE - 1].next = 0;
}

//�ӿ������л�ȡһ���ڵ�
int GetNode(SLinkList &L){
    //���������ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0
    int i = 0;
    if(L[0].next != 0){
        i = L[0].next;
        L[0].next = L[i].next;
    }
    return i;
}

//���ڵ�q�ͷţ������������
void FreeNode(SLinkList &L,int q){
    //���±�Ϊq�Ľ����������
    L[q].next = L[0].next;
    L[0].next = q;
}

//�ھ�̬����L��λ��Ϊp�ĺ����������Ϊx�Ľ��
bool InsertNextNode(SLinkList &L,int p,int x){
    int q = GetNode(L);
    //��������û�нڵ���
    if(q == 0){
        return false;
    }
    L[q].data = x;
    L[q].next = L[p].next;
    L[p].next = q;
    return true;
}

//ɾ����̬����L��λ��Ϊp�Ľ�����һ���ڵ�
bool Delete(SLinkList &L,int p){
    if(p == 0){
        return false;
    }
    int i = L[p].next;
    L[p].next = L[i].next;
    FreeNode(L,i);
    return true;
}

//��ͬһ���洢���е���������ϲ�
void Merge(SLinkList &L,int M,int N){
    //M,N�ֱ������������ͷ���
    //���ҵ�M��������һ���ڵ�
    int p = M;
    while(L[p].next != 0){
        p = L[p].next;
    }
    //��N������ӵ�M�ĺ���
    int q = L[N].next;
    L[q].next = L[p].next;
    L[p].next = q;
    //��N�����ͷ����ͷ�
    FreeNode(L,N);

}

int main(){
    SLinkList L;
    InitSLinkList(L);
    //������1ͷ�������Ϊhead1����������1
    int head1 = GetNode(L);
    L[head1].next = 0;
    for(int i = head1;i < head1 + 5;i++){
        InsertNextNode(L,i,i);
    }

    cout << L[1].next;
    cout << L[2].next;
    cout << L[3].next;


    //������2ͷ�������Ϊ head2,��������2
    int head2 = GetNode(L);
    L[head2].next = 0;
    for(int i = head2;i < head2 + 5;i++){
    InsertNextNode(L,i,i*10);
    }


    Merge(L,head1,head2);

}
