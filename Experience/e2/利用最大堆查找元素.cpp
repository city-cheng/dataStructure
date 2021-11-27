#include <iostream>
using namespace std;

#define MAXSIZE 200

//定义最大堆（完全二叉树 数组表示）
typedef struct{
    int data[MAXSIZE];
    int length;
}Heap;

void InitHeap(Heap &heap){
    heap.length = 0;
}

bool isEmpty(Heap heap){
    return heap.length == 0;
}

//插入节点
void InsertNode(Heap &heap,int x){
    int i;
    if(heap.length < MAXSIZE - 1){
        i = heap.length + 1;
        //当插入的元素大于根节点时，就让插入的元素作为根节点（或让根节点下来）
        while((i != 1) && (x > heap.data[i / 2])){
            heap.data[i] = heap.data[i / 2];
            i /= 2;
        }
        heap.data[i] = x;
        heap.length++;
    }
}

//删除最大节点(即根节点)，返回根节点的值
int DeleteMax(Heap &heap){
    int parent = 1,child = 2;
    int x,y;
    if(!isEmpty(heap)){
        x = heap.data[1];  //取出根节点的值
        //将最后节点补到根节点的位置
        y = heap.data[heap.length];
        heap.length--;
        //从上之下检查元素是否符合最大堆，并纠正
        while(child <= heap.length){
            //每次去较大的孩子作为根节点
            if((child < heap.length) && (heap.data[child] < heap.data[child + 1])){
                child = child + 1;
            }
            //如果已经根节点已经满足最大，则跳出循环
            if(y >= heap.data[child]){
                break;
            }
            //交换并更新根节点(parent)，同时更新child为新的根节点的子节点
            heap.data[parent] = heap.data[child];
            parent = child;
            child *= 2;
        }
        heap.data[parent] = y;
        return x;
    }
    return 0;
}

// //按值查找
// static int result = 1;
// int Find(Heap heap,int i,int e){
//     if(e == heap.data[i]){
//         return i;
//     }else if(e == heap.data[i + 1]){
//         return i + 1;
//     }
//     int p = (heap.data[i] > heap.data[i + 1])?heap.data[i]:heap.data[i + 1];//较大孩子
//     int q = (heap.data[i] < heap.data[i + 1])?heap.data[i]:heap.data[i + 1];//较小孩子
//     if(e > p){
//         return 0;
//     }
//     if(e < p){
//         result = Find(heap,p * 2,e);
//         result = Find(heap,q * 2,e);
//     }
//     if(e < q){
//         result =Find(heap,q * 2,e);
//     }
// }

bool FindVisit(Heap heap,int i,int e,int &result){
    if(heap.data[i] == e){
        result = i;
        return true;
    }
    if(heap.data[i] < e && heap.data[i + 1] < e){
        result = 0;
        return true;
    }
    return false;
}

int Find(Heap heap,int i,int e){
    static int result = 0;
    if(i <= heap.length){
        if(FindVisit(heap,i,e,result)){
            return result;
        }
        // cout << heap.data[i] << endl;
        if(Find(heap,i * 2,e)){
            return result;
        }
        if(Find(heap,i * 2 + 1,e)){
            return result;
        }
    }
    return result;
}


int main(){
    Heap heap;
    InitHeap(heap);
    InsertNode(heap,20);
    InsertNode(heap,25);
    InsertNode(heap,10);
    InsertNode(heap,5);
    InsertNode(heap,7);
    cout << Find(heap,1,5) << endl;
    cout << Find(heap,1,20) << endl;
    cout << Find(heap,1,50) << endl;
    return 0;
}