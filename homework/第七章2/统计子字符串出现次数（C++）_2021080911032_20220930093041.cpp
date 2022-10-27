#include<iostream>
#include<string.h>
using namespace std;
int SubStrNum(char *str, char *substr){
    int num=0;
    int n=strlen(str);
    int m=strlen(substr);
    for(int i=0;i+m-1<n;++i){
        int k=i,j;
        for(j=0;j<m;++j){
            if(str[k]==substr[j]) ++k;
            else break;
        }if(j==m){
            ++num;
            i=k-1;
        }
    }
    cout<<"match times="<<num;
    return num;
}