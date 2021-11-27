#include <stdio.h>

#define MaxSize 5
//��̬˳���
typedef struct{
	int data[MaxSize];
	int length;
}SeqList; 
//��ʼ��˳��� 
void InitList(SeqList &L){
	L.length = 0;
	
}

//������� 
bool ListInsert(SeqList &L,int i,int e){
	if(i<1 || i > L.length+1){
		return false;
	}
	if(L.length >= MaxSize){
		return false;
	}
	for(int j = L.length;j >= i;j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true;
} 

//ɾ��Ԫ��
bool ListDelete(SeqList &L,int i,int &e){
	if(i < 1 || i > L.length){
		return false;
	}
	for(int j = i;j< L.length;j++){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
} 


// ��λ����
int GetElem(SeqList &L,int i){
	return L.data[i-1];
} 

// ��ֵ����
int LocateElem(SeqList &L,int e){
	for(int i=0;i <L.length;i++){
		if(L.data[i] == e){
			return i+1;
		}
	}
		return -1;
} 
int main(){
	SeqList L;
	InitList(L);
	ListInsert(L,1,5);
	ListInsert(L,2,6);
	ListInsert(L,3,8);
	ListInsert(L,4,9);
	ListInsert(L,5,0);
	for(int i = 0;i < L.length;i++){
		printf("%d",L.data[i]);
	} 
	return 0;
}
