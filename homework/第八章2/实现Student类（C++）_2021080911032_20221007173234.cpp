#include<iostream>
#include<string>
using namespace std;
const int N=100;
double count=0,grade_1=0,grade_2=0,grade_3=0;
class Student{
    private:
    string name;
    string num;
    int grade1;
    int grade2;
    int grade3;
    public:
    Student(string num,string name,int grade1,int grade2,int grade3);
    void display();
    double average1();
    double average2();
    double average3();
};
Student::Student(string num,string name,int grade1,int grade2,int grade3){
    this->num=num;
    this->name=name;
    this->grade1=grade1;
    this->grade2=grade2;
    this->grade3=grade3;
    count++;
    grade_1+=grade1;
    grade_2+=grade2;
    grade_3+=grade3;
}
void Student::display(){
    cout<<num<<" "<<name<<" "<<grade1<<" "<<grade2<<" "<<grade3<<endl;
}
double Student::average1(){
    return grade_1/count;
}
double Student::average2(){
    return grade_2/count;
}
double Student::average3(){
    return grade_3/count;
}
int main(){
	Student *stu1,*stu2,*stu3;
	char name1[10],name2[10],name3[10];
	char num1[12],num2[12],num3[12];
	int grade1[3],grade2[3],grade3[3];
	cin>>name1>>num1>>grade1[0]>>grade1[1]>>grade1[2];
	cin>>name2>>num2>>grade2[0]>>grade2[1]>>grade2[2];
	cin>>name3>>num3>>grade3[0]>>grade3[1]>>grade3[2];
	stu1 = new Student(name1,num1,grade1[0],grade1[1],grade1[2]);
	stu2 = new Student(name2,num2,grade2[0],grade2[1],grade2[2]);
	stu3 = new Student(name3,num3,grade3[0],grade3[1],grade3[2]);

	stu1->display();
	stu2->display();
	stu3->display();

    cout<<"The average grade of course1:"<<stu2->average1()<<endl;
	 cout<<"The average grade of course2:"<<stu2->average2()<<endl;
	  cout<<"The average grade of course3:"<<stu2->average3()<<endl;
	  return 0;
}