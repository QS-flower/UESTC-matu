#include<CString.h>
#include<string.h>
int EditString::IsSubString(int start,const char *str){
    int n=strlen(str);
	if(start<0||len-start<n) return -1;
    for(int i=start;i+n-1<len;i++){
        int k=i,j;
        for(j=0;j<n;j++){
            if(mystr[k]==str[j]) k++;
            else break;
        }if(j==n) return i;
    }return -1;
}
void EditString::EditChar(char s,char d){
    for(int i=0;i<len;i++){
        if(mystr[i]==s) mystr[i]=d;
    }
}
void EditString::EditSub(char *subs,char *subd){
	if (String::IsSubString(subs))
	{
		char str[100]={0};
		int indexs=0;
		int indexd=0;
		for (int i=0; i<len; ++i)
		{
			if(i ==  IsSubString(i,subs))
			{
				for (indexs = 0;indexs < strlen(subd); ++indexs)
				{
					str[indexd++] = subd[indexs];
				}
				i+=strlen(subs)-1;
				continue;
			}
			str[indexd++] = mystr[i];
		}
		delete []mystr;
		mystr = new char[indexd+1];
		strcpy(mystr,str);
	}
}
void EditString::DeleteChar(char ch){
	int i=0;
    for(;i<len;i++){
        if(mystr[i]==ch){
            for(int j=i;j<len;j++){
                mystr[j]=mystr[j+1];
            }len--;
			i=0;
        }
    }
}
void EditString::DeleteSub(char *sub){
	int n=strlen(sub);
	int i=0;
	for(;i+n-1<len;i++){
        int k=i,j;
        for(j=0;j<n;j++){
            if(mystr[k]==sub[j]) k++;
            else break;
        }if(j==n){
			for(int t=i;t<len;t++){
				mystr[t]=mystr[t+n];
			}len-=n;
			i=0;
        }
    }
}