#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
//动态定义顺序表 
typedef struct{
	int *data;
	int  MaxSize;
	int length;
}SeqList;

//初始化顺序表 
void InitList(SeqList &L){
	L.data = (int *)malloc(sizeof(int) * InitSize);
	L.length = 0;
	L.MaxSize = InitSize;
}
//增加表的最大长度 
void IncreaseSize(SeqList &L,int len){
	int *p = L.data;
	L.data  = (int *)malloc((L.MaxSize + len) * sizeof(int));
	for (int i = 0;i < L.length;i++){
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize + len;
	free(p);
}

//插入元素
bool ListInsert(SeqList &L,int i ,int e){
	if(i < 1 || i > L.length + 1){
		return false;
	}
	if(i > L.MaxSize){
		return false;
	}
	for(int j = L.length;j >= i;j--){
		L.data[j] = L.data[j-1];
	}
	L.data[i-1] = e;
	L.length++;
	return true;

} 

//删除元素
int ListDelete(SeqList &L,int i,int &e) {
	if(i < 1 || i >L.length){
		return false;
	}
	if(i > L.MaxSize){
		return false;
	}
	
	for(int j = i;j < L.length;j++){
		L.data[j-1] = L.data[j];
	}
	L.length--;
	return true;
}

//按位查找 
int GetElem(SeqList &L,int i){
	return L.data[i-1];
}


//按值查找
int LocateElem(SeqList &L,int e){
	for(int i=0;i <L.length;i++){
		if(L.data[i] == e){
			return i+1;
		}
		return -1;
	}	
} 

int main(){
	return 0;
}



