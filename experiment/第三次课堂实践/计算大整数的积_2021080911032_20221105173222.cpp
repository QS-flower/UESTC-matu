#include<iostream>
#include<cstring>
#include<cstdlib>
#define maxn 1000

using namespace std;
int a[maxn], b[maxn];

void mul(char str1[], char str2[])
{
	int i = 0, j = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
    for(i = len1 - 1, j = 0; i >= 0; i--)
        a[j++] = str1[i] - '0';
    for(i = len2 - 1, j = 0; i >= 0; i--)
        b[j++] = str2[i] - '0';
   
	int c[maxn]={0};     for(int i=len1-1;i>=0;i--){         for(int j=len2-1;j>=0;j--){             c[i+j]+=a[i]*b[j];         }     }     for(int i=len1+len2-1;i>0;i--){         c[i-1]+=c[i]/10;         c[i]=c[i]%10;     }if(c[0]==0) cout<<"0";     else{             for(int i=0;i<len1+len2-1;i++){             cout<<c[i];         }     }
}

int main(void)
{
    char str1[maxn], str2[maxn];
	cin >> str1 >> str2;
    mul(str1, str2);
    return 0;
}
