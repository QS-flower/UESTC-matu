#include<iostream>
using namespace std;
const int N=1000;
int a[N][N]={0};
int BestValue(int row[],int col[], int n){
    if(n<2){
        cout<<"error"<<endl;
        return -1;
    } 
    if(row==NULL||col==NULL){
        cout<<"error"<<endl;
        return -1;
    } 
    bool istrue=true;
    for(int i=0;i<n-1;i++){
        if(col[i]!=row[i+1]){
            istrue=false;
            break;
        }
    }if(!istrue){
        cout<<"error"<<endl;
        return -1;
    }
    int temp=0;
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j=i+l-1;
            a[i][j]=1e8;
            for(int d=i;d<j;d++){
                temp=a[i][d]+a[d+1][j]+row[i]*col[d]*col[j];
                if(temp<a[i][j]){
                    a[i][j]=temp;
                }
            }
        }
    }return a[0][n-1];
}