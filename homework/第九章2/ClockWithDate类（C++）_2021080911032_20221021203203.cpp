#include<ClockAndDate.h>
int Date::days(int year,int month){
    if(year%400==0||(year%4==0&&year%100!=0)){
        switch(month){
            case 1:case 3:case 5: case 7: case 8: case 10: case 12 :return 31;
            case 4:case 6:case 9: case 11:return 30;
            case 2:return 29;
        }
    }else{
        switch(month){
            case 1:case 3:case 5: case 7: case 8: case 10: case 12 :return 31;
            case 4:case 6:case 9: case 11:return 30;
            case 2:return 28;
        }
    }return 0;
}
void Date::NewDay(){
    this->day++;
    if(day>days(year,month)){
        this->day=1;
        this->month++;
    }
    if(month>12){
        this->year++;
        this->month=1;
    }
}
class ClockWithDate:public Clock,public Date{
    public:
    ClockWithDate(int hour,int minute,int second,int year,int month,int day):Clock(hour,minute,second),Date(year,month,day){}
    void showTime(){
        cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl<<year<<"-"<<month<<"-"<<day<<endl;
    }
    void run(){
        second = second+1;
		if (second>59)
		{
			second =0;
			minute+=1;
		}
		if (minute>59)
		{
			minute =0;
			hour+=1;
		}
		if (hour>23)
		{
			hour =0;
            NewDay();
		}
    }
};
Clock* Clock::createClockWithDate(int h,int m,int s,int year,int month,int day){
	return new ClockWithDate(h,m,s,year,month,day);
}