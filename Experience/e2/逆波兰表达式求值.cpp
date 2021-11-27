#include <iostream>
using namespace std;

#include <stack>
#define MaxSize 10


//�����������
typedef struct BitNode{
    char data;
    struct BitNode *lchild,*rchild;
}BitNode,*BitTree;

//��ʼ��������
bool InitTree(BitTree &root){
    root = (BitNode *)malloc(sizeof(BitNode));
    if(root == NULL){
        return false;
    }
    root->data = ' ';
    root->lchild = NULL;
    root->rchild = NULL;
    return true;
}


//����µĽ��
bool InsertNode(BitNode *root,char data){
    if(root == NULL){
        return false;
    }

    BitNode *p = (BitNode *)malloc(sizeof(BitNode));
    if(p == NULL){
        return false;
    }
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    if(root->lchild == NULL){
        root->lchild = p;   
    }else if(root->rchild == NULL){
        root->rchild = p;
    }else{
        return false;
    }
    return true;
    
}

//��ӡ���
void PrintNode(BitNode *p,string &express1){
    if(p == NULL){
        return;
    }else{
        express1.push_back(p->data);
    }
}

//�������
bool TailOrder(BitTree root,string &express1){
    if(root != NULL){
        TailOrder(root->lchild,express1);
        TailOrder(root->rchild,express1);
        PrintNode(root,express1);
    }else{
        return true;
    }
    return false;
}



//˳��ջ
typedef struct{
	BitNode *data[MaxSize];
	int top;
}SqStack; 

//��ʼ��˳��ջ 
bool InitStack(SqStack &S){
	S.top = -1;
	return true;
}

//�жϿ�ջ
bool Empty(SqStack S){
	if(S.top == -1){
		return true;
	}
	return false;
} 

//��ջ����
bool Push(SqStack &S,BitNode *x){
	//�ж�ջ�Ƿ����� 
	if(S.top == MaxSize - 1){
		return false; 
	}
	//ÿ�ν�ջ��Ҫ�ƶ�topָ�� 
//	S.top++;
//	S.data[S.top] = x;
	S.data[++S.top] = x;
	return true;
} 

//��ջ����
bool Pop(SqStack &S,BitTree &x){
	if(S.top == -1){
		return false;
	}
//	x = S.data[S.top];
//	S.top--;
	x = S.data[S.top--];
	return true;	
} 


//���ʽת���ɶ�����

//���������������ڵ�ѹ�������ջ
void CreateSubTree(SqStack &cals,SqStack &nums){
    BitNode *elemCal,*elemNum1,*elemNum2;
    Pop(cals,elemCal);
    Pop(nums,elemNum2);
    Pop(nums,elemNum1);
    elemCal->lchild = elemNum1;
    elemCal->rchild = elemNum2;
    Push(nums,elemCal);
}

void Create(SqStack &cals,SqStack &nums,char elem){
    //��װ�ɽ��
    BitNode *p = (BitNode *)malloc(sizeof(BitNode)),*q = NULL;
    p->data = elem;
    p->lchild = p->rchild = NULL;

    //��������
    if((elem >= '0') && (elem <= '9')){
        Push(nums,p);
    }
    if(elem == '+' || elem == '-'){
        while(!Empty(cals)){
            if((cals.data[cals.top]->data == '(')){
                break;
            }
            CreateSubTree(cals,nums);
        }
            Push(cals,p);
    }
    if(elem == '*' || elem == '/'){
        if((cals.data[cals.top]->data != '*') && (cals.data[cals.top]->data != '/')){
            Push(cals,p);
        }else{
            while( ((cals.data[cals.top]->data == '*') || (cals.data[cals.top]->data == '/')) && (!Empty(cals)) ){
            CreateSubTree(cals,nums);
        }
            Push(cals,p);
        }
    }
    if(elem == '('){
        Push(cals,p);
    }
    if(elem == ')'){
        while((cals.data[cals.top]->data != '(') && (!Empty(cals)) ){
            CreateSubTree(cals,nums);
        }
        Pop(cals,q);  
    }
}


BitTree convert(string express){
    BitTree T;
    SqStack cals,nums;
    InitStack(cals);
    InitStack(nums);
    BitNode *p;
    int i = 0;
    char elem = express[0];
    while(elem != '\0'){
        Create(cals,nums,elem);
        elem = express[++i];
    }
    while(!Empty(cals)){
        CreateSubTree(cals,nums);
        Pop(nums,T);
    }
    return T;
}

//��׺���ʽ��ֵ
double computer(BitTree T){
    string express1;
    TailOrder(T,express1);
    stack<double> nums;
    double num1,num2,result;
    char elem;
    for(int i = 0;i < express1.size();i++){
        elem = express1[i];
        if(elem >= '0' && elem <= '9'){
            nums.push(elem - '0');
        }else{
            num2 = nums.top();
            nums.pop();
            num1 = nums.top();
            nums.pop();
            switch (elem)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                break;
            }
            nums.push(result);
        }
    }
    return nums.top();
}



int main(){
    string express1;
    string express = "2+3*(5+8)/4-5";
    BitTree T = convert(express);
    TailOrder(T,express1);
    cout << express1 << endl;
    cout << computer(T);
    return 0;
}