#include <iostream>
#include <cstring>
using namespace std;

#define maxVexNum 100

//�ڽӱ�洢ͼ  ������ͼΪ��
typedef struct ArcNode{
    int adjVex;  //ָ��Ķ�������
    // int weight;   //Ȩ��
    struct ArcNode *next; //ָ����һ����
}ArcNode;

typedef struct VNode{
    char data;  //������Ϣ
    ArcNode *first;  //ָ���һ���ڽӵĻ�
}VNode,AdjList[maxVexNum];

typedef struct{
    AdjList vertices;  //����
    int vexNum = 0,arcNum = 0;    
}ALGraph;

void InitArcNode(ArcNode *&p){
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->next = NULL;
    p->adjVex = -1;
}

void InitVNode(VNode *&p){
    p = (VNode *)malloc(sizeof(VNode));
    p->first = NULL;
}



//����x�ĵ�һ���ڽӵ�
int FirstNeighbor(ALGraph G,int x){
    if(x >= G.vexNum){
        return -1;
    }
    ArcNode *p = G.vertices[x].first;
    if(p != NULL){
        return p->adjVex;
    }
    return -1;
}

//����x�ĳ��˶���y�������һ���ڽӵ�
int NextNeighbor(ALGraph G,int x,int y){
    if(x >= G.vexNum || y >= G.vexNum){
        return -1;
    }
    ArcNode *p = G.vertices[x].first;
    while(p != NULL){
        if(p->adjVex == y && p->next != NULL){
            return p->next->adjVex;
        }
        p = p->next;
    }
    return -1;

}

//����ڵ�
bool InsertVex(ALGraph &G,char data){
    if(G.vexNum >= maxVexNum){
        return false;
    }
    VNode newVex;
    newVex.data = data;
    newVex.first = NULL;
    G.vertices[G.vexNum++] = newVex;
    return true;
}




//���뻡xy
bool InsertEdge(ALGraph &G,int x,int y){
    if(x >= G.vexNum){
        return false;
    }
    
    ArcNode *newArc1,*newArc2,*temp;
    InitArcNode(newArc1);
    InitArcNode(newArc2);
    InitArcNode(temp);

    newArc1->adjVex = x;
    temp = G.vertices[y].first;
    G.vertices[y].first = newArc1;
    newArc1->next = temp;

    newArc2->adjVex = y;
    temp = G.vertices[x].first;
    G.vertices[x].first = newArc2;
    newArc2->next = temp;

    return true;
}

int main(){
    ALGraph G;
    InsertVex(G,'a');
    InsertVex(G,'b');
    InsertVex(G,'c');
    InsertVex(G,'d');
    InsertVex(G,'e');

    InsertEdge(G,0,1);
    InsertEdge(G,0,4);
    InsertEdge(G,1,4);
    InsertEdge(G,1,3);
    InsertEdge(G,1,2);
    InsertEdge(G,2,3);
    InsertEdge(G,3,4);
    cout << FirstNeighbor(G,0) << endl;
    cout << NextNeighbor(G,0,4) << endl;
    return 0;
}