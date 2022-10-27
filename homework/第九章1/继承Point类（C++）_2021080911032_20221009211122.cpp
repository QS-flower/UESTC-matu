#include"CPoint.h"
#define PI 3.14



Rectangle::Rectangle(float xx, float yy, float w, float h):Point(xx, yy)
{
	width = w;
	high = h;
}
Circle::Circle(float xx, float yy, float r): Point(xx,yy)
{
	radius = r;
}
float Rectangle::Area()
{
	float m;
	m = width * high;
	cout << m<<endl;
	return m;
}
float Circle::Area()
{
	float m;
	m = PI * radius*radius;
	cout << m<<endl;
	return m;
}

int main()
{
	Rectangle rect(1, 2, 3, 4);
	rect.Area();     //12
	Circle c(5, 6, 7);
	c.Area();      //153.86
	return 0;
}
