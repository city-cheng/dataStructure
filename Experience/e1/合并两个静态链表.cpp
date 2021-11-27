#include <iostream>
using namespace std;

#define MAXSIZE 1000

//定义静态链表
typedef struct{
    int data;
    int next;
}SLNode,SLinkList[MAXSIZE];

//初始化静态链表
//将存储池中所有节点设置为空闲
void InitSLinkList(SLinkList &L){
    //将数组中的各个节点先连起来，L[0]为头节点
    //NULL用0表示
    for(int i = 0;i < MAXSIZE - 1;i++){
        L[i].next = i + 1;
    }
    L[MAXSIZE - 1].next = 0;
}

//从空闲链中获取一个节点
int GetNode(SLinkList &L){
    //若空闲链非空，则返回分配的节点下标，否则返回0
    int i = 0;
    if(L[0].next != 0){
        i = L[0].next;
        L[0].next = L[i].next;
    }
    return i;
}

//将节点q释放，即加入空闲链
void FreeNode(SLinkList &L,int q){
    //将下标为q的结点加入空闲链
    L[q].next = L[0].next;
    L[0].next = q;
}

//在静态链表L中位置为p的后面添加数据为x的结点
bool InsertNextNode(SLinkList &L,int p,int x){
    int q = GetNode(L);
    //空闲链中没有节点了
    if(q == 0){
        return false;
    }
    L[q].data = x;
    L[q].next = L[p].next;
    L[p].next = q;
    return true;
}

//删除静态链表L中位置为p的结点的下一个节点
bool Delete(SLinkList &L,int p){
    if(p == 0){
        return false;
    }
    int i = L[p].next;
    L[p].next = L[i].next;
    FreeNode(L,i);
    return true;
}

//将同一个存储池中的两个链表合并
void Merge(SLinkList &L,int M,int N){
    //M,N分别是两个链表的头结点
    //先找到M链表的最后一个节点
    int p = M;
    while(L[p].next != 0){
        p = L[p].next;
    }
    //将N链表添加到M的后面
    int q = L[N].next;
    L[q].next = L[p].next;
    L[p].next = q;
    //将N链表的头结点释放
    FreeNode(L,N);

}

int main(){
    SLinkList L;
    InitSLinkList(L);
    //将链表1头结点设置为head1，构建链表1
    int head1 = GetNode(L);
    L[head1].next = 0;
    for(int i = head1;i < head1 + 5;i++){
        InsertNextNode(L,i,i);
    }

    cout << L[1].next;
    cout << L[2].next;
    cout << L[3].next;


    //将链表2头结点设置为 head2,构建链表2
    int head2 = GetNode(L);
    L[head2].next = 0;
    for(int i = head2;i < head2 + 5;i++){
    InsertNextNode(L,i,i*10);
    }


    Merge(L,head1,head2);

}
