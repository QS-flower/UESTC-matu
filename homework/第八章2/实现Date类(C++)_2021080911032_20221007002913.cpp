#include <iostream>
#include <cmath>
using namespace std;

class Date{
 public:
       Date(int y = 1996,int m = 1,int d = 1);
       int days(int year,int month);
       void NewDay();
       void display()
       {
            cout<<year<<"-"<<month<<"-"<<day<<endl;
       }
 private:
      int year; //年
      int month; //月
      int day;  // 日
};

Date::Date(int y,int m ,int d)
{
    if(m<1||m>12)
    {
        cout<<"Invalid month!"<<endl;
        month=1;
    }
    else
    {
        month=m;
    }
    if(d>days(year,month))
    {
        cout<<"Invalid day!"<<endl;
        day=1;
    }
    else {
        day=d;
    }
    year=y;
}
void Date::NewDay()
{
    day++;
    if(day>days(year,month))//上面的day++之后，再来判断加一天之后的天数是否超出了这个月的天数（因为days函数里面已经判断了是什么年，该返回多少天，所以这里完全不需要担心报其他错误）
    {
        month++;
        day=1;
        if(month>12)
        {
            year++;
            month=1;
        }
    }
}

int  Date::days(int year,int month)//这里面是返回的天数
{
    switch (month)
    {
    case 1: case 3:case 5: case 7: case 8: case 10: case 12:   return 31;
    case 2:
        if((year%4==0 && year%100!=0)||year%400==0)//判断是否是闰年
        {
            return 29;
        }
        else
        {
            return 28;
        }
    case 4: case 6: case 9: case 11: return 30;
    default: break;
    }
}

