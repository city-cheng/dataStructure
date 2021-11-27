#include <iostream>
using namespace std;

#define MAXSIZE 100

//定义顺序表
typedef struct SeqList{
    int data[MAXSIZE];
    int length;
}SeqList;

//初始化顺序表
void initList(SeqList &L){
    L.length = 0;
}

//判断是否为空
bool isEmpty(SeqList L){
    return L.length == 0;
}

//按位序插入元素
bool listInsert(SeqList &L,int index,int e){
    if(index <= 0 || index > L.length + 1){
        return false;
    }
    if(index >= MAXSIZE){
        return false;
    }


    for (int i = L.length; i >= index; i--){
        L.data[i] = L.data[i - 1];
    }
    L.data[index - 1] = e;
    L.length++;
    return true;
}

//尾插元素
bool insertTail(SeqList &L,int e){
    if(L.length >= MAXSIZE){
        return false;
    }
    listInsert(L,L.length + 1,e);
    return true;
}


//按位序删除元素
bool listDelete(SeqList &L,int i){
    if(L.length == 0 || i > L.length || i <= 0){
        return false;
    }
    for(int j = i - 1;j < L.length - 1;j++){
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

//按位查找
int getElem(SeqList L,int i){
    if(L.length == 0 || i <=0 || i > L.length){
        return 0;
    }
    return L.data[i - 1];
}

//按值查找
int LocateElem(SeqList &L,int e){
	for(int i=0;i <L.length;i++){
		if(L.data[i] == e){
			return i+1;
		}
	}
		return -1;
}


//合并两个有序顺序表（数组）
SeqList mergeList(SeqList &L1,SeqList &L2){
    SeqList L;
    initList(L);
    int i = 1;
    int j = 1;
    while(i <= L1.length || j <= L2.length){
        if(i == L1.length + 1){
            insertTail(L,getElem(L2,j));
            j++;
        }else if(j == L2.length + 1){
            insertTail(L,getElem(L1,i));
            i++;
        }else if(getElem(L1,i) <= getElem(L2,j)){
            insertTail(L,getElem(L1,i));
            i++;
        }else if(getElem(L1,i) >= getElem(L2,j)){
            insertTail(L,getElem(L2,j));
            j++;
        }
    }
    return L;
}



int main(){
    SeqList L1;
    SeqList L2;
    initList(L1);
    initList(L2);
    listInsert(L1,1,1);
    listInsert(L1,2,3);
    listInsert(L1,3,5);
    listInsert(L1,4,7);
    listInsert(L2,1,2);
    listInsert(L2,2,4);
    listInsert(L2,3,6);
    listInsert(L2,4,8);

    SeqList L3 = mergeList(L1,L2);
    for(int i = 0;i < L3.length;i++){
		printf(" %d",L3.data[i]);
	} 
    return 0;


}

