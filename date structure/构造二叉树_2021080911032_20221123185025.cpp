#include<map>
using namespace std;
int size=0;
map<int,int> inv;
void SwapTree(int n,int *preOrder,int *inOrder,int *outOrder,int *head){
    int p=*preOrder;
    int i=inv[p]-(inOrder-head)+1;
    outOrder[size++]=p;
    if(n-i>0)
    SwapTree(n-i,preOrder+i,inOrder+i,outOrder,head);
    if(i>1)
    SwapTree(i-1,preOrder+1,inOrder,outOrder,head);
}
void solve(int n,int *preOrder,int *inOrder,int *outOrder){
    int *head=inOrder;
    for(int i=0;i<n;i++){
        inv[inOrder[i]]=i;
    }
    SwapTree(n,preOrder,inOrder,outOrder,head);
}