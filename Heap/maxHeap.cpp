#include <iostream>
using namespace std;

#define MAXSIZE 100

//堆是一个完全二叉树，可使用顺序存储
typedef struct{
    int data[MAXSIZE];
    int length;
}MaxHeap,SeqList;

//初始化顺序表 
void InitList(SeqList &L){
	L.length = 0;
	
}

//插入操作 
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

//堆元素s的下坠
void ShiftDown(MaxHeap &H,int s,int m){
    int rc = H.data[s];
    for(int i = 2 * s;i <= m;i *= 2){
        if(i < m && H.data[i + 1] > H.data[i]){
            i++;    //记录较大子节点的下标   注意如果i = m表示没有子节点了，就不比较了
        }
        if(rc >= H.data[i]){
            break;    //根节点大于子节点，无需操作
        }
        H.data[s] = H.data[i];
        s = i;   //子节点上来
    }
    H.data[s] = rc;   //最后空出的结点就是rc要沉入的结点
}

//堆元素s的上浮
void ShiftUp(MaxHeap &H,int s,int m){
    int rc = H.data[s];
    for(int i = s / 2;i>= m;i /= 2){
        if(rc <= H.data[i]){
            break;    //子节点比根节点小，不用调整
        }
        H.data[s] = H.data[i];
        s = i;
    }
    H.data[s] = rc;
}

//堆排序
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

