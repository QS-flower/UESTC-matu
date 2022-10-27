#include<iostream>
#include<string>
#define max 100
int main(){
    using namespace std;
    char s1[max];
    cin>>s1;
    char s2[max];
    int i=0;
    while(s1[i]!='\0'){
        s2[i]=s1[i];
    ++i;
    }
    s2[i]='\\';
    s2[i+1]='0';
    cout<<s2;
}