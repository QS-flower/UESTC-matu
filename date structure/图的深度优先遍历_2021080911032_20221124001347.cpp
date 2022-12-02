#include<iostream>
using namespace std;
const int N=3005;
bool visited[N]={false};
bool visited1[N]={false};
int arcs[N][N]={0};
typedef struct Node{
    int date;
    struct Node *next;
}Node;
Node arc[N];
int size1=0;
int size2=0;
void DFSA(int n,int m,int out[]){
    out[size1++]=m;
    visited[m]=true;
    for(int i=0;i<n;i++){
        if(arcs[m][i]!=0&&!visited[i])
        DFSA(n,i,out);
    }
}
void solveA(int n,int m,int e[][2],int out[]){
    for(int i=0;i<m;i++){
        arcs[e[i][0]][e[i][1]]=arcs[e[i][1]][e[i][0]]=1;
    }DFSA(n,0,out);
}
void insert(int n,int m){
    Node *p=&(arc[n]);
    while(p->next){
        p=p->next;
    }Node *q=new Node;
    q->date=m;
    q->next=NULL;
    p->next=q;
}
void DFSB(int m,int out[]){
    out[size2++]=m;
    visited1[m]=true;
    Node *p=arc[m].next;
    while(p){
        if(!visited1[p->date])
        DFSB(p->date,out);
        p=p->next;
    }
}
void solveB(int n,int m,int e[][2],int out[]){
    for(int i=0;i<N;i++){
        arc[i].next=NULL;
    }
    for(int i=0;i<m;i++){
        insert(e[i][0],e[i][1]);
        insert(e[i][1],e[i][0]);
    }DFSB(0,out);
}