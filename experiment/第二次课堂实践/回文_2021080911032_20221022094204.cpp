#include<iostream>
#include<string.h>
using namespace std;
void palindrome(char *a){
    int n=strlen(a);
    char *b=new char[n+1];
    for(int i=0;i<n;i++){
        b[i]=a[n-i-1];
    }b[n]='\0';
    if(strcmp(a,b)==0){
        cout<<"true"<<endl;
        return;
    }
    else{
        cout<<"false"<<endl;
        return;
    }
}
int main(){
    char a[31];
    cin>>a;
    palindrome(a);
}