#include<iostream>
#include<string.h>
using namespace std;
void count(char *str){
    int n=strlen(str);
    int num1=0,num2=0,num3=0;
    for(int i=0;i<n;i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')) num1++;
        if(str[i]>='0'&&str[i]<='9') num2++;
        if(str[i]==' ') num3++;
    }cout<<num1<<","<<num2<<","<<num3<<endl;
}