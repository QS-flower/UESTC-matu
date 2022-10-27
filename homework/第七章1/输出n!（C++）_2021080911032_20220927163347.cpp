#include<iostream>
int main(){
    using namespace std;
    int n,temp=1;
    cin>>n;
    if(n>12){
        cout<<"12!=479001600";
    }else{
        for(int i=1;i<=n;i++){
        temp*=i;
    }
        cout<<n<<"!="<<temp;
    }
    
}