#include<iostream>
#include<math.h>
using namespace std;
int find(int);
int main()
{
    int n;
    cin >> n;
    cout<< find(n);
}

int find(int n) {
    if (n < 100 || n>999)return 0;
    int count = 0;
    for (int i = 100; i <= n; i++) 
    {
        int ge = i % 10;
        int shi = i / 10 % 10;
        int bai = i / 100 % 10;
        if (pow((double)ge, (double)3) + pow((double)shi, (double)3) + pow((double)bai, (double)3) == i)
        {
            count++;
        }
    }
    return count;
}