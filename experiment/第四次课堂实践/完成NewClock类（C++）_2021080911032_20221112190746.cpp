#include <iostream>
using namespace std;

class Clock {
public:
    Clock(int h, int m, int s) {
        hour = (h>23 ? 0 : h);
        minute = (m>59 ? 0 : m);
        second = (s>59 ? 0 : m);
    }
    virtual void run() {
        second = second + 1;
        if (second>59)
        {
            second = 0;
            minute += 1;
        }
        if (minute>59)
        {
            minute = 0;
            hour += 1;
        }
        if (hour>23)
        {
            hour = 0;
        }
    }
    virtual void showTime() {
        cout << "Now:" << hour << ":" << minute << ":" << second << endl;
    }
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }

    Clock * createNewClock(int h, int m, int s);
private:
    int hour;
    int minute;
    int second;
};

class NewClock:public Clock{     int hour,minute,second;     public:     NewClock(int h,int m,int s):Clock(h,m,s){         hour =getHour(); 	    minute =getMinute(); 	    second =getSecond();     }     void run(){ 		second = second+1; 		if (second>59) 		{ 			second =0; 			minute+=1; 		} 		if (minute>59) 		{ 			minute =0; 			hour+=1; 		} 		if (hour>23) 		{ 			hour =0; 		} 	}     void showTime(){         if(hour>11){             cout<<"Now:"<<hour-12<<":"<<minute<<":"<<second<<"PM"<<endl;         }else{             cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<"AM"<<endl;         }     } }; Clock* Clock::createNewClock(int h,int m,int s){ 	Clock *p= new NewClock(h,m,s);     return p; }

int main()
{
	int type;
	cin>>type;
	Clock C(1,1,1);
	Clock *NC = C.createNewClock(23,59,59);
	Clock *NC1 = C.createNewClock(11,59,59);
	switch(type){
	case 1:
		NC->showTime();
		break;
	case 2:
		NC->run();
		NC->showTime();
		break;
	case 3:
		NC1->run();
		NC1->showTime();
	}
	return 0;
}
