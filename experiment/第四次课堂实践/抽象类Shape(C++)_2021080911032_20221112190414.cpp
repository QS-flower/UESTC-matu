#include<Shape.h>
class Rectangle:public Shape{
    private:
    double l,w;
    public:
    Rectangle(double l,double w){
        this->l=l;
        this->w=w;
    }double GetArea(){
        return l*w;
    }double GetPerimeter(){
        return 2*(l+w);
    }
};
class Circle :public Shape{
    private:
    double r;
    public:
    Circle(double r){
        this->r=r;
    }double GetArea(){
        return r*r*3.14;
    }double GetPerimeter(){
        return 2*r*3.14;
    }
};
Shape * Shape::createRectangle(double l,double w){return new Rectangle(l,w);}
Shape * Shape::createCircle(double r){return new Circle(r);}