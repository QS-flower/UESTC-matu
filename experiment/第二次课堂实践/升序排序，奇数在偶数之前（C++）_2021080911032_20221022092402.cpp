#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a,num=0,num1=0,num2=0;
    int j[10],o[10];
    while(num<10){
        cin>>a;
        if(a<0) break;
        if(a%2==0){
            o[num2++]=a;
        }if(a%2==1){
            j[num1++]=a;
        }num++;
        if(num==10) break;
    }sort(j,j+num1);
    sort(o,o+num2);
    for(int i=0;i<num1;i++){
        cout<<j[i]<<" ";
    }for(int i=0;i<num2;i++){
        cout<<o[i]<<" ";
    }
}