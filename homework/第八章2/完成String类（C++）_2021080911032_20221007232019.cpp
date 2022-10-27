#include <iostream>
#include<string.h>
#include<cmath>
using namespace std;
const int N=100;
class String{
private:
	char *mystr;    //×Ö·û´®
	int len;    //×Ö·û´®³¤¶È
public:
	String(){
		len =0;
		mystr =NULL;
	}
	String(const char* p){
		len = strlen(p);
		mystr = new char[len+1];
		strcpy(mystr,p);
	}
	String(String &s){
		len = s.len;
		if (len !=0)
		{
			mystr = new char[len+1];
			strcpy(mystr,s.mystr);
		}
	}
	~String(){
         if (mystr != NULL)
         {
			 delete []mystr;
			 mystr =NULL;
			 len = 0;
         }
	}

	char *GetStr(){return mystr;}
	void ShowStr(){cout<<mystr;}

        bool IsSubstring(const char *str);
	bool IsSubstring(const String &str);
	int str2num();
	void toUppercase();
};
bool String::IsSubstring(const char *str){
    int n=strlen(mystr);
    int m=strlen(str);
    for(int i=0;i+m-1<n;i++){
        int k=i,j;
        for(j=0;j<m;j++){
            if(mystr[k]==str[j]) k++;
            else break;
        }if(j==m) return true;
    }return false;
}
bool String::IsSubstring(const String &str){
    int n=strlen(mystr);
    int m=strlen(str.mystr);
    for(int i=0;i+m-1<n;i++){
        int k=i,j;
        for(j=0;j<m;j++){
            if(mystr[k]==str.mystr[j]) k++;
            else break;
        }if(j==m) return true;
    }return false;
}
int String::str2num(){
    int n=strlen(mystr);
    int temp[N],k=0;
    for(int i=0;i<n;i++){
        int count=mystr[i]-'0';
        if(count>-1&&count<10){
            temp[k]=count;
            k++;
        }
    }int count=0,m=k;
    for(int i=0;i<m;i++){
        count+=temp[i]*pow((float)10.0,(float)k-1);
        k--;
    }return count;
}
void String::toUppercase(){
    int n=strlen(mystr);
    for(int i=0;i<n;i++){
        if(mystr[i]>=97&&mystr[i]<=122){
            mystr[i]-=32;
        }
    }
}
