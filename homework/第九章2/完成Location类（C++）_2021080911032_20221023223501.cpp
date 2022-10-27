#include<Location.h>
Location &Location::operator+(Location &offset){
    this->x+=offset.getX();
    this->y+=offset.getY();
    return *this;
}
Location &Location::operator-(Location &offset){
    this->x-=offset.getX();
    this->y-=offset.getY();
    return *this;
}