#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int count=1;
	double pi = 0.0;
	while (1.0/(count*2-1)>1e-8)
	{
		if(count%2!=0){
        pi+=1.0/(count*2-1);
        }else{
            pi-=1.0/(count*2-1);
        }
        ++count;
	}
	pi = pi * 4;
	cout<<"steps="<<count<<" ";
    cout<<"PI="<<setiosflags(ios::fixed)<<setprecision(5)<<pi;
}
