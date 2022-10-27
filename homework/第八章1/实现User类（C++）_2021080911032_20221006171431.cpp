#include<iostream>
#include<string.h>
using namespace std;
const int N=10;
int temp=0;
class User{
    private:
    char *name[N],*pass[N];
    public:
    User(char *name1,char *pass1);
    void AddUser(char *name1,char *pass1);
    int login(char *name1,char *pass1); 
};
User::User(char *name1,char *pass1){
    AddUser(name1,pass1);
}
void User::AddUser(char *name1,char *pass1){
    name[temp]=name1;
    pass[temp]=pass1;
    temp++;
}
int User::login(char *name1,char *pass1){
    for(int i=0;i<temp;i++){
        if(strcmp(name[i],name1)==0&&strcmp(pass[i],pass1)==0){
            return i;
        }
    }return -1;
}
int main(){
	char name[10],name1[10],pass[10],pass1[10];
	cin>>name>>pass>>name1>>pass1;
	User user("LiWei","liwei101");
	user.AddUser(name,pass);
	if (user.login(name1,pass1) >=0)
	{
		cout<<"Success Login!"<<endl;
	}
	else{
		cout<<"Login failed!"<<endl;
	}
	  return 0;
}