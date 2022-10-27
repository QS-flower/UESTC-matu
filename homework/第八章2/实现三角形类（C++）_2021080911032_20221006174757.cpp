#include<iostream>
#include<cmath>
using namespace std;
class Ctriangle{
    private:
    double a,b,c;
    public:
    Ctriangle(double a1,double b1,double c1);
    void display();
    double GetPerimeter();
    double GetArea();
};
Ctriangle::Ctriangle(double a1,double b1,double c1){
    a=a1;
    b=b1;
    c=c1;
}
void Ctriangle::display(){
    cout<<"Ctriangle:"<<"a="<<a<<","<<"b="<<b<<","<<"c="<<c<<endl;
}
double Ctriangle::GetPerimeter(){
    return a+b+c;
}
double Ctriangle::GetArea(){
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	Ctriangle T(a,b,c);
	T.display();
	cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
	cout<<"Area:"<<T.GetArea()<<endl;
	return 0;	 
}