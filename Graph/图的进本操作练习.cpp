#include <stdio.h>
#include <stdlib.h>

//使用邻接矩阵存储的图
#define MaxVexNum 100
typedef struct{
	char Vex[MaxVexNum];
	int Edge[MaxVexNum][MaxVexNum];
}MGraph; 

//使用邻接表存储的图
//边链表 
typedef struct ArcNode{
	int adjVex;
	struct ArcNode *next;
}ArcNode;

//顶点/顶点数组
typedef struct {
	char data;
	ArcNode *first;
}VNode,AdjList[MaxVexNum]; 

//使用邻接表存储的图
typedef struct {
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph; 
