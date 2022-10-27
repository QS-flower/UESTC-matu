#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%2==0||n<1||n>80){
        cout<<"error";
    }else{
        for(int i=n;i>=1;i=i-2){
            for(int j=1;j<=(n-i)/2;j++){
                cout<<" ";
            }for(int j=1;j<=i;j++){
                cout<<"*";
            }cout<<endl;
        }
    }return 0;
}