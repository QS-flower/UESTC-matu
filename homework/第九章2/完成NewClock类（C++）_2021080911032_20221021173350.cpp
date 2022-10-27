#include<Clock.h>
class NewClock:public Clock{
    int hour,minute,second;
    public:
    NewClock(int h,int m,int s):Clock(h,m,s){
        hour =getHour();
	    minute =getMinute();
	    second =getSecond();
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
		}
	}
    void showTime(){
        if(hour>11){
            cout<<"Now:"<<hour-12<<":"<<minute<<":"<<second<<"PM"<<endl;
        }else{
            cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<"AM"<<endl;
        }
    }
};
Clock* Clock::createNewClock(int h,int m,int s){
	Clock *p= new NewClock(h,m,s);
    return p;
}