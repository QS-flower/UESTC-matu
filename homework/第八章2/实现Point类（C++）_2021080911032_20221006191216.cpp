#include<iostream>
#include<cmath>
using namespace std;
class Point{
    private:
    double x,y;
    public:
    double Distance(const Point &p){
        x-=p.x;
        y-=p.y;
        return sqrt(x*x+y*y);
    }
    Point(double x,double y){
        this->x=x;
        this->y=y;
    }
};
int main(){
    double a,b,c,d;
	cin>>a>>b>>c>>d;
	Point A(a,b),B(c,d);
	cout<<A.Distance(B)<<endl;
	return 0;
}
