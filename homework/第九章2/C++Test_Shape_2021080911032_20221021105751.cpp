#include<iostream>
#include<ShapeFactory.h>
using namespace std;
#define pi 3.14
/* class ShapeFactory
{
public:
	 ShapeFactory(){};
	 virtual ~ShapeFactory(){};
	 virtual float Circumstance(){return 0;};
	 ShapeFactory *Create(float a,float b,float c);
	 ShapeFactory *Create(float a,float b,float c,float d);
	 ShapeFactory *Create(float r);
}; */
class Triangle : public ShapeFactory{
    private:
    float a,b,c;
    public:
    Triangle(float a1,float b1,float c1){
        a=a1;
        b=b1;
        c=c1;
    }
    float Circumstance(){
        return a+b+c;
    }
};
class Quadrangular : public ShapeFactory{
    private:
    float a,b,c,d;
    public:
    Quadrangular(float a1,float b1,float c1,float d1){
        a=a1;
        b=b1;
        c=c1;
        d=d1;
    }
    float Circumstance(){
        return a+b+c+d;
    }
};
class Circle : public ShapeFactory{
    private:
    float r;
    public:
    Circle(float r1){
        r=r1;
    }
    float Circumstance(){
        return 2*r*pi;
    }
};
ShapeFactory * ShapeFactory::Create(float a,float b,float c)
{
	
	ShapeFactory *p=new Triangle(a,b,c);
	return p;
}
ShapeFactory * ShapeFactory::Create(float a,float b,float c,float d)
{
	
	ShapeFactory *p=new Quadrangular(a,b,c,d);
	return p;
}
ShapeFactory * ShapeFactory::Create(float r)
{
	
	ShapeFactory *p=new Circle(r);
	return p;
}