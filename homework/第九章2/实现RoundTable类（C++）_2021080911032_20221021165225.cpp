#include<iostream>
#include<string.h>
#define pi 3.14
using namespace std;
class Table{
    protected:
    float high;
    public:
    Table(float h=0){
        high=h;
    }
    float GetHigh(){
        return high;
    }
};
class Circle{
    protected:
    float radius;
    public:
    Circle(float r=0){
        radius=r;
    }
    float GetArea(){
        return radius*radius*pi;
    }
};
class RoundTable:public Circle, public Table{
    protected:
    char color[20];
    public:
    RoundTable(float r,float h,char *c){
        this->high=h;
        this->radius=r;
        strcpy(this->color,c);
    }
    char *GetColor(){
        return color;
    }
};

int main(){
    float radius,high;
	char color[20];
	cin>>radius>>high>>color;
	
	RoundTable RT(radius,high,color);
	cout<<"Area:"<<RT.GetArea()<<endl;
	cout<<"High:"<<RT.GetHigh()<<endl;
	cout<<"Color:"<<RT.GetColor()<<endl;
	return 0;
}
