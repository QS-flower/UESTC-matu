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
      int year; //��
      int month; //��
      int day;  // ��
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
    if(day>days(year,month))//�����day++֮�������жϼ�һ��֮��������Ƿ񳬳�������µ���������Ϊdays���������Ѿ��ж�����ʲô�꣬�÷��ض����죬����������ȫ����Ҫ���ı���������
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

int  Date::days(int year,int month)//�������Ƿ��ص�����
{
    switch (month)
    {
    case 1: case 3:case 5: case 7: case 8: case 10: case 12:   return 31;
    case 2:
        if((year%4==0 && year%100!=0)||year%400==0)//�ж��Ƿ�������
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

