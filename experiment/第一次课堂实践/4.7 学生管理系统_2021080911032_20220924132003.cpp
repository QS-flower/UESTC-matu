#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
class Student
{
private:
	string name;
	int gender;
	int birthday;
	double height;
	int CResult;
	int MathResult;
public:
	Student() {}
	Student(string n, int g, int b, double h,int C, int M);
	Student(Student &s);
	void print();
	int getCResult();
	int getMathResult();
};

Student::Student(string n, int g, int b, double h,int C, int M)
{
	name = n;
	gender = g;
	birthday = b;
	height = h;
	CResult = C;
	MathResult = M;
}

Student::Student(Student& s)
{
	name = s.name;
	gender = s.gender;
	birthday = s.birthday;
	height = s.height;
	CResult = s.CResult;
	MathResult = s.MathResult;
}

void Student::print()
{
	cout << name << " " << gender << " " << birthday << " " << setiosflags(ios::fixed)<<setprecision(2)<<height << " " << CResult << " " << MathResult;
	cout << endl;
}

int Student::getCResult()
{
	return CResult;
}

int Student::getMathResult()
{
	return MathResult;
}
int C_average(Student[] ,int);
int Math_average(Student[],int);
Student* C_max(Student[],int,int &);
Student* Math_max(Student[],int,int &);
int C_min(Student[],int);
int Math_min(Student[],int);

int main()
{
	int count = 0;
	int number;
	cin >> number;
	Student* ss = new Student[number];
	string name;
	int gender;
	int birthday;
	double height;
	int CResult;
	int MathResult;
	for (int i = 0; i < number; i++)
	{
		//cout << "请输入姓名";
		cin >> name;
		//cout << "请输入性别";
		cin >> gender;
		//cout << "请输入生日";
		cin >> birthday;
		//cout << "请输入身高";
		cin >> height;
		//cout << "请输入C成绩";
		cin >> CResult;
		//cout << "请输入微积分成绩";
		cin >> MathResult;
		ss[i] = Student(name, gender, birthday, height, CResult, MathResult);
	}
	cout << "C_average:"<<C_average(ss, number) << endl;;
	Student* temps1 = C_max(ss,number,count);
	cout << "C_max:"<<temps1[0].getCResult() << endl;
	for (int i = 0; i < count; i++)
	{
		temps1[i].print();
	}

	cout <<"C_min:"<<C_min(ss, number) << endl;
	cout << "Calculus_average:"<<Math_average(ss, number) << endl;
	Student* temps2 = Math_max(ss,number,count);
	cout << "Calculus_max:"<<temps2[0].getMathResult() << endl;
	for (int i = 0; i < count; i++)
	{
		temps2[i].print();
	}
	cout <<"Calculus_min:"<< Math_min(ss, number) << endl;
	return 0;
}

int C_average(Student s[],int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += s[i].getCResult();
	}
	return sum / n;
}

int Math_average(Student s[],int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += s[i].getMathResult();
	}
	return sum / n;
}

Student* C_max(Student s[],int n,int &count)
{
	count = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].getCResult() >= max)max = s[i].getCResult();
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i].getCResult() == max)count++;
	}
	Student* s1 = new Student[count];
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].getCResult() == max)
		{
			s1[count] = Student(s[i]);
			count++;
		}
	}
	return s1;
}

Student* Math_max(Student s[],int n,int &count)
{
	count = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].getMathResult() >= max)max = s[i].getMathResult();
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i].getMathResult() == max)count++;
	}
	Student* s2 = new Student[count];
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i].getMathResult() == max)
		{
			s2[count] = Student(s[i]);
			count++;
		}
	}
	return s2;
}

int C_min(Student s[],int n)
{
	int min = 200;
	for (int i = 0; i < n; i++)
	{
		if (s[i].getCResult() <= min)min = s[i].getCResult();
	}
	return min;
}

int Math_min(Student s[],int n)
{
	int min = 200;
	for (int i = 0; i < n; i++)
	{
		if (s[i].getMathResult() <= min)min = s[i].getMathResult();
	}
	return min;
}