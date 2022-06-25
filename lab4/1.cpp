#include<iostream>
#define endl '\n'
using std::cout;

class Time{
	private:
		int mhour{};
		int mminute{};
		int msecond{};
	public:
		Time(){
		}
		Time(int h,int m,int s):mhour{h},mminute{m},msecond{s}{
		}
		void displayin12()const{
			cout<<"12 hour format: "<<endl;
			cout<<mhour%12<<" : "<<mminute<<" : "<<msecond<<(mhour<12?" AM":" PM")<<endl;
		}
		void displayin24()const{
			cout<<"24 hour format: "<<endl;
			cout<<mhour<<" : "<<mminute<<" : "<<msecond<<(mhour<12?" AM":" PM")<<endl;
		}
		Time addTime(const Time& time)const{
			Time t{};
			t.msecond=msecond+time.msecond;

			t.mminute=mminute+time.mminute;
			t.mminute+=t.msecond/60;
			t.msecond%=60;

			t.mhour=mhour+time.mhour;
			t.mhour+=t.mminute/60;
			t.mminute%=60;
			t.mhour %= 24;

			return t;
		}

};



/* 
 *Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and secon
 *d to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the 
 *result as a time object. There should be functions to display time in 12-hour and 24-hour format.
 */
int main(){
	Time t1{13,20,35};
	Time t2{11,40,21};
	t1.displayin24();
	t1.displayin12();
	t2.displayin24();
	t2.displayin12();
	Time t3=t1.addTime(t2);
	t3.displayin24();
	t3.displayin12();
	return 0;
}


