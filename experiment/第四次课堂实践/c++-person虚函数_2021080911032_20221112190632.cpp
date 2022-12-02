#include<iostream>
#include<cstring>
using namespace std;
class PersonFactory
{
	int id;
	char name[50];
	int age;
	public:
	PersonFactory(int i = 0, char * nm = 0, int a = 15);//i:id;nm:name;a:age
	virtual ~PersonFactory() {};

	virtual void PrintInfo() 
	{
 		cout << id << endl;
		cout << name << endl;
		cout << age << endl;
	};
	PersonFactory * CreateStudent(int id, char *name, int age, int  grade);
	PersonFactory * CreateTeacher(int id, char *name, int age, char *department);
};

PersonFactory::PersonFactory(int i , char * nm , int a ){     this->id=i;     if(!nm) this->name[0]='\0';     else strcpy(this->name,nm);     this->age=a; } class Student:public PersonFactory{     int grade;     public:     Student(int i, char * nm , int a ,int g=1):PersonFactory(i,nm,a){     this->grade=g;     }     ~Student() {}     void PrintInfo()    {     PersonFactory::PrintInfo();     cout<<grade<<endl;    }; }; class Teacher:public PersonFactory{     char department[50];     public:     Teacher(int i , char * nm , int a ,char *de=0):PersonFactory(i,nm,a){     if(!de) this->department[0]='\0';     else strcpy(this->department,de);     }     ~Teacher() {}     void PrintInfo()    {     PersonFactory::PrintInfo();     cout<<department<<endl;    }; }; PersonFactory * PersonFactory::CreateStudent(int id, char *name, int age, int grade){     return new Student(id,name,age,grade); };    PersonFactory * PersonFactory:: CreateTeacher(int id, char *name, int age, char *department){     return new Teacher(id,name,age,department);   };

int main()
{
	PersonFactory vn;
	PersonFactory *ps,*pt;
	int id,age,grade;
	char name[50],department[50];
	cin>>id>>name>>age>>department;
	ps=vn.CreateTeacher (id,name,age,department);
	ps->PrintInfo ();
	cin>>id>>name>>age>>grade;
	ps=vn.CreateStudent (id,name,age,grade);
	ps->PrintInfo ();
	return 0;
}
