#include <iostream>
#include <cstring>
using namespace std;

#include<queue>

#define maxVertexNum 100   //最大顶点数
//邻接矩阵存储图
typedef struct{
    char vex[maxVertexNum];
    int edge[maxVertexNum][maxVertexNum];
    int vexNum = 0,arcNum = 0;
}MGraph;


//列出结点x邻接的边
void Neighbors(MGraph G,char x){}

//插入节点
bool InsertVex(MGraph &G,char x){
    if(G.vexNum >= maxVertexNum){
        return false;
    }
    G.vex[G.vexNum] = x;
    G.vexNum++;
    return true;
}

//删除节点
bool DeleteVex(MGraph &G,char x){
    if(G.vexNum == 0){
        return false;
    }
    G.vexNum--;
    return true;
}

//顶点x的第一个邻接点，如果不存在返回-1  这里
int FirstNeighbor(MGraph G,int x){
    if(x >= G.vexNum){
        return -1;
    }
    for(int i = 0;i < G.vexNum;i++){
        if(G.edge[x][i]){
            return i;
        }
    }
    return -1;
}

//返回顶点x，除了顶点y外的下一个邻接点
int NextNeighbor(MGraph G,int x,int y){
    if(x >= G.vexNum || y>= G.vexNum){
        return -1;
    }
    for(int i = y + 1;i < G.vexNum;i++){
        if(G.edge[x][i]){
            return i;
        }
    }
    return -1;
}

//访问顶点
void visit(int i){
    cout << i << " ";
}



//深度优先遍历
bool visited[maxVertexNum];
void DFS(MGraph G,int v){
    visit(v);
    visited[v] = true;
    for(int j = FirstNeighbor(G,v);j >= 0;j = NextNeighbor(G,v,j)){
        if(!visited[j])
            DFS(G,j);
    }
}

void DFSTraverse(MGraph G){
    for(int i = 0;i < maxVertexNum;i++){
        visited[i] = false;
    }
    for(int i = 0;i < G.vexNum;i++){
        if(!visited[i]){
            DFS(G,i);
        }
    }
}

//广度优先遍历
queue<int> Q;
void BFS(MGraph G,int v){
    Q.push(v);
    visit(v);
    visited[v] = true;
    while(!Q.empty()){
        int j = Q.front();
        Q.pop();
        for(int w = FirstNeighbor(G,j);w >= 0;w = NextNeighbor(G,j,w)){
            if(!visited[w]){
                visit(w);
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

void BFSTraverse(MGraph G){
    for(int i = 0;i < maxVertexNum;i++){
        visited[i] = false;
    }
    for(int i = 0;i < G.vexNum;i++){
        if(!visited[i]){
            BFS(G,i);
        }
    }
}





int main(){
    int a[5][5] = {{0,1,0,1,0},{1,0,1,0,1},{0,1,0,1,1},{1,0,1,0,0},{0,1,1,0,0}};
    MGraph G;
    G.vexNum = 5;
    G.arcNum = G.vexNum * G.vexNum;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            G.edge[i][j] = a[i][j];
        }
    }
    strcpy(G.vex,"abcde");

    cout << FirstNeighbor(G,2) << endl;

    cout << NextNeighbor(G,2,1) << endl;

    DFSTraverse(G);
    cout << endl;
    BFSTraverse(G);

    return 0;
}
