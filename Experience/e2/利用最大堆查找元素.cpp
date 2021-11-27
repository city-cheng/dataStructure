#include <iostream>
using namespace std;

#define MAXSIZE 200

//�������ѣ���ȫ������ �����ʾ��
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

//����ڵ�
void InsertNode(Heap &heap,int x){
    int i;
    if(heap.length < MAXSIZE - 1){
        i = heap.length + 1;
        //�������Ԫ�ش��ڸ��ڵ�ʱ�����ò����Ԫ����Ϊ���ڵ㣨���ø��ڵ�������
        while((i != 1) && (x > heap.data[i / 2])){
            heap.data[i] = heap.data[i / 2];
            i /= 2;
        }
        heap.data[i] = x;
        heap.length++;
    }
}

//ɾ�����ڵ�(�����ڵ�)�����ظ��ڵ��ֵ
int DeleteMax(Heap &heap){
    int parent = 1,child = 2;
    int x,y;
    if(!isEmpty(heap)){
        x = heap.data[1];  //ȡ�����ڵ��ֵ
        //�����ڵ㲹�����ڵ��λ��
        y = heap.data[heap.length];
        heap.length--;
        //����֮�¼��Ԫ���Ƿ�������ѣ�������
        while(child <= heap.length){
            //ÿ��ȥ�ϴ�ĺ�����Ϊ���ڵ�
            if((child < heap.length) && (heap.data[child] < heap.data[child + 1])){
                child = child + 1;
            }
            //����Ѿ����ڵ��Ѿ��������������ѭ��
            if(y >= heap.data[child]){
                break;
            }
            //���������¸��ڵ�(parent)��ͬʱ����childΪ�µĸ��ڵ���ӽڵ�
            heap.data[parent] = heap.data[child];
            parent = child;
            child *= 2;
        }
        heap.data[parent] = y;
        return x;
    }
    return 0;
}

// //��ֵ����
// static int result = 1;
// int Find(Heap heap,int i,int e){
//     if(e == heap.data[i]){
//         return i;
//     }else if(e == heap.data[i + 1]){
//         return i + 1;
//     }
//     int p = (heap.data[i] > heap.data[i + 1])?heap.data[i]:heap.data[i + 1];//�ϴ���
//     int q = (heap.data[i] < heap.data[i + 1])?heap.data[i]:heap.data[i + 1];//��С����
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