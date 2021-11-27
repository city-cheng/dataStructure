#include <iostream>
using namespace std;

#define MAXSIZE 100

//����һ����ȫ����������ʹ��˳��洢
typedef struct{
    int data[MAXSIZE];
    int length;
}MaxHeap,SeqList;

//��ʼ��˳��� 
void InitList(SeqList &L){
	L.length = 0;
	
}

//������� 
bool ListInsert(SeqList &L,int i,int e){
	if(i<1 || i > L.length+1){
		return false;
	}
	if(L.length >= MAXSIZE){
		return false;
	}
	for(int j = L.length + 1;j >= i;j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i] = e;
	L.length++;
	return true;
} 

//��Ԫ��s����׹
void ShiftDown(MaxHeap &H,int s,int m){
    int rc = H.data[s];
    for(int i = 2 * s;i <= m;i *= 2){
        if(i < m && H.data[i + 1] > H.data[i]){
            i++;    //��¼�ϴ��ӽڵ���±�   ע�����i = m��ʾû���ӽڵ��ˣ��Ͳ��Ƚ���
        }
        if(rc >= H.data[i]){
            break;    //���ڵ�����ӽڵ㣬�������
        }
        H.data[s] = H.data[i];
        s = i;   //�ӽڵ�����
    }
    H.data[s] = rc;   //���ճ��Ľ�����rcҪ����Ľ��
}

//��Ԫ��s���ϸ�
void ShiftUp(MaxHeap &H,int s,int m){
    int rc = H.data[s];
    for(int i = s / 2;i>= m;i /= 2){
        if(rc <= H.data[i]){
            break;    //�ӽڵ�ȸ��ڵ�С�����õ���
        }
        H.data[s] = H.data[i];
        s = i;
    }
    H.data[s] = rc;
}

//������
void HeapSort(SeqList &H){
    int temp;
    for(int i = H.length / 2;i > 0;i--){
        ShiftDown(H,i,H.length);
    }
    for(int i = H.length;i > 1;i--){
        temp = H.data[1];
        H.data[1] = H.data[i];
        H.data[i] = temp;
        ShiftDown(H,1,i - 1);
    }
}   


int main(){
    SeqList S;
    InitList(S);
    ListInsert(S,1,9);
    ListInsert(S,2,2);
    ListInsert(S,3,1);
    ListInsert(S,4,7);
    ListInsert(S,5,5);
    cout << S.length << endl;
    for(int i = 1;i <= S.length;i++){
		printf("%d",S.data[i]);
	} 
    HeapSort(S);
    for(int i = 1;i <= S.length;i++){
		printf("%d",S.data[i]);
	} 
    return 0;
}

