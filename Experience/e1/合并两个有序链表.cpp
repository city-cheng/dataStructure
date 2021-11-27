#include <iostream>
using namespace std;

//定义单链表
//带头结点的单链表
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 

//初始化空表（带头结点） 
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));
	//内存不足，分配失败 
	if(L == NULL){
		return false;
	}
	L->next = NULL;
	return true;
}

// 判断带头结点的单链表是否为空
bool isEmpty(LinkList &L){
	if(L->next == NULL){
		return true;
	}
	else{
		return false;
	}
} 


//插入到指定节点的后面
bool InsertNextNode(LNode *p,int e){
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL){
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
} 


//按位序插入
bool ListInsert(LinkList &L,int i, int e){
	if(i < 1){
		return false;
	}
	LNode *p;
	//p先指向头结点 
	p = L;
	int j = 0;
	while(p != NULL && j < i-1){
		p = p->next;
		j++;
	}
//	if(p == NULL){
//		return false;
//	}
//	LNode *s = (LNode *)malloc(sizeof(LNode));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//	return true;
	return InsertNextNode(p,e);
	
} 



//指定节点的前插操作
bool InsertPriorNode(LNode *p,int e){
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL){
		return false;
	}
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}


//按位序删除
bool ListDelete(LinkList &L,int i){
	if(i < 1){
		return false;
	}
	LNode *p;
	p = L;
	int j = 0;
	while(p!= NULL && j < j-1){
		p = p->next;
		j++;
	}
	if(p->next = NULL){
		return false;
	}
	LNode *q = p->next;
	p->next = q->next;
	free(q);
	return true;	
} 

//删除指定节点
bool DeleteNode(LNode *p){
	if(p == NULL){
		return false;
	}
	LNode *q = p->next;
	p->data = p->next->data;
	p->next = q->next;
	free(q);
	return true;
} 

//按位查找
LNode *GetElem(LinkList L,int i){
	LNode *p;
	p = L;
	int j = 0;
	while(p!= NULL && j < i){
		p = p->next;
		j++;
	}
	return p;
} 

//按值查找
LNode *LocateElem(LinkList L,int e){
	LNode *p = L->next;
	while(p != NULL || p->data != e){
		p = p->next;
	}
	return p;

}

int Length(LinkList L){
	LNode *p = L;
	int len = 0;
	while(p->next != NULL){
		p = p->next;
		len++;
	}
	return len;
} 


//尾插法建立单链表 
LinkList List_TailInsert(LinkList &L){
	int x;
	InitList(L);
	LNode *s,*r = L;
	scanf("%d",&x);
	while(x != 9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r->next = NULL;
	return L;
	
}
//打印链表 
void ShowList(LinkList L){
	LNode *p = L->next;
	while(p != NULL){
		printf("%d",p->data);
		p = p->next;
	}
}


//头插法建立单链表
 LinkList List_HeadInsert(LinkList &L){
 	InitList(L);
 	int x;
 	LNode *s = L;
 	scanf("%d",&x);
 	while(x != 9999){
 		s = (LNode *)malloc(sizeof(LNode));
 		s->data = x;
 		s->next = L->next;
 		L->next = s;
 		scanf("%d",&x);
	 }
	 return L;
 } 


 //合并两个有序链表（法1）
 LinkList mergeList(LinkList L1,LinkList L2){
	 LNode *p = L1->next;
	 LNode *q = L2->next;
	 LinkList L3;
	 InitList(L3);
	 LNode *result = L3;
	 while(p != NULL || q != NULL){
		if(p == NULL){
			InsertNextNode(result,q->data);
			q = q ->next;
			result = result->next;
		}else if(q == NULL){
			InsertNextNode(result,p->data);
			p = p->next;
			result = result->next;
		}else if(p->data <= q->data){
			InsertNextNode(result,p->data);
			p = p->next;
			result = result->next;
		}else if(p->data > q->data){
			InsertNextNode(result,q->data);
			q = q->next;
			result = result->next;
		}
	 }
		return L3;

 }


 int main(){
	LinkList L1;
	LinkList L2;
	
	List_TailInsert(L1);
	cout << "L1 = " << endl;
	ShowList(L1);
	cout << endl;
	List_TailInsert(L2);
	cout << "L2 = " << endl;
	ShowList(L2);
	cout << endl;
	cout << "L3 = " << endl;
	LinkList L3 = mergeList(L1,L2);
	ShowList(L3);


	return 0;	 
 }