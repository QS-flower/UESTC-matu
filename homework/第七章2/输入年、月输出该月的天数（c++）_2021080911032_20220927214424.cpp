#include <iostream>
int main()
{
    using namespace std;
    int year, month, days = 0;
    cin >> year >> month;
    if (year % 400 == 0||(year%4==0&&year%100!=0))
    {
        while (month > 12)
        {
            month -= 12;
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            cout << "days:31";
        }
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            cout << "days:30";
        }
        if (month == 2)
        {
            cout << "days:29";
        }
    }
    else
    {
        while (month > 12)
        {
            month -= 12;
        }
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            cout << "days:31";
        }
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            cout << "days:30";
        }
        if (month == 2)
        {
            cout << "days:28";
        }
    }
    return 0;
}