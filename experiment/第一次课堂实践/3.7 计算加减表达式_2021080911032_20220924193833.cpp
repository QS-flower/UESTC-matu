#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;

int main()
{
    int  stop = 1;
    double ans = 1;
    double a;
    cin >> ans;
    while (stop) {
        switch (getchar()) {
        case '+':
            cin >> a;
            ans += a;
            break;
        case '-':
            cin >> a;
            ans -= a;
            break;
        case ';':
            stop = 0;
            break;
        default:
            cout<<"error";
            return 1;
        }
    }
    
    cout << fixed << setprecision(6) << ans << endl;
	system("pause");

	return 0;
}