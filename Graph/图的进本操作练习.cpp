#include <stdio.h>
#include <stdlib.h>

//ʹ���ڽӾ���洢��ͼ
#define MaxVexNum 100
typedef struct{
	char Vex[MaxVexNum];
	int Edge[MaxVexNum][MaxVexNum];
}MGraph; 

//ʹ���ڽӱ�洢��ͼ
//������ 
typedef struct ArcNode{
	int adjVex;
	struct ArcNode *next;
}ArcNode;

//����/��������
typedef struct {
	char data;
	ArcNode *first;
}VNode,AdjList[MaxVexNum]; 

//ʹ���ڽӱ�洢��ͼ
typedef struct {
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph; 
