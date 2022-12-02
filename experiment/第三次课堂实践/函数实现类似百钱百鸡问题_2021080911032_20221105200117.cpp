#include<iostream>
using namespace std;
int howMany(int money,int m,int cockMoney,int henMoney,int chickenMoney,int *cockNum,int *henNum,int *chickenNum){
    if(money<0||m<0||cockMoney<0||chickenMoney<0||henMoney<0||money<m||cockNum==NULL||henNum==NULL||chickenNum==NULL) return -1;
    for(int i=0;i<=money/cockMoney;i++){
        for(int j=0;j<=(money-cockMoney*i)/henMoney;j++){
            if(i*cockMoney+j*henMoney+(m-i-j)*chickenMoney==money){
                *cockNum=i;
                *henNum=j;
                *chickenNum=m-i-j;
                return 1;
            }
        }
    }return 0;
}
int main(){
    int money,m,cockMoney,henMoney,chickenMoney;
    cin>>money>>m>>cockMoney>>henMoney>>chickenMoney;
    int cockNum,henNum,chickenNum;
    howMany(money,m,cockMoney,henMoney,chickenMoney,&cockNum,&henNum,&chickenNum);
}