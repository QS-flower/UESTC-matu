#include<iostream>
using namespace std;
int days(int year,int month){
    month=month%12;
    if(year%400==0||(year%4==0&&year%100!=0)){
        switch(month){
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
            case 4:case 6:case 9:case 11:return 30;
            case 2:return 29;
        }
    }else{
        switch(month){
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
            case 4:case 6:case 9:case 11:return 30;
            case 2:return 28;
        }
    }
    return 0;
}
int main(){
    int year,month;
    cin>>year>>month;
    cout<<"days:"<<days(year,month)<<endl;
}