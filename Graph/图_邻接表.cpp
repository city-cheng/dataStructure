#include <iostream>
#include <cstring>
using namespace std;

#define maxVexNum 100

//邻接表存储图  以无向图为例
typedef struct ArcNode{
    int adjVex;  //指向的顶点索引
    // int weight;   //权重
    struct ArcNode *next; //指向下一条弧
}ArcNode;

typedef struct VNode{
    char data;  //顶点信息
    ArcNode *first;  //指向第一个邻接的弧
}VNode,AdjList[maxVexNum];

typedef struct{
    AdjList vertices;  //顶点
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



//顶点x的第一个邻接点
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

//顶点x的除了顶点y以外的下一个邻接点
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

//插入节点
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




//插入弧xy
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