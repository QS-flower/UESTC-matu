#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int);
int main()
{
	int c;
	cin >> c;
    if (c < 4)
    {
        cout << "error";
        return 0;
    }
    else if (isPrime(c))
    {
        cout << "yes";
    }
    else if (!isPrime(c)) { cout << "no"; }
    
}
bool isPrime(int a)
{
    for (int i = 2; i <= pow(a, 0.5); i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}