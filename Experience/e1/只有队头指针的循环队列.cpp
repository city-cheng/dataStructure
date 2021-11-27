#include <iostream>
using namespace std;

#define MAXSIZE 100

//����ѭ�����У�ֻ�ж�ͷָ��
//����˳��洢��ʽ
typedef struct Queue{
    int data[MAXSIZE];
    int front;
    int count;
}Queue;

//��ʼ��ѭ������
void InitQueue(Queue &Q){
    Q.front = 0;
    Q.count = 0;
}

//�ж϶���
bool IsFull(Queue Q){
    return Q.count == MAXSIZE;
}

//�ж϶ӿ�
bool IsEmpty(Queue Q){
    return Q.count == 0;
}

//���
bool EnQueue(Queue &Q,int e){
    if(IsFull(Q)){
        return false;
    }
    Q.data[(Q.front + Q.count) % MAXSIZE] = e;
    Q.count++;
    return true;
}

//����
bool DeQueue(Queue &Q,int &x){
    if(IsEmpty(Q)){
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    Q.count--;
    return true;
}


int main(){
    Queue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    EnQueue(Q,4);


    int x;
    DeQueue(Q,x);
    cout << x;
    DeQueue(Q,x);
    cout << x;
    DeQueue(Q,x);
    cout << x;
}

