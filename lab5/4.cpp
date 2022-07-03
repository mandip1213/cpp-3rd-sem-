#include<iostream>
#include<cmath>
#define endl '\n'
using std::cout;
class Date {
	private:
		int myear;
		int mmonth;
		int mday;
		int daysInMonth() {
			if (mmonth == 2) {
				return (myear % 4 == 0 ? 29 : 28);
			}
			else if ((mmonth <= 7 && mmonth % 2 == 1) || (mmonth > 7 && mmonth % 2 == 0)) {
				return 31;
			}
			else {
				return 30;
			}
		}
		void arrangeDate() {
			int dayinmonth = daysInMonth();
			if (mday > dayinmonth) {
				mmonth += mday / dayinmonth;
				mday %= dayinmonth;
				if (mmonth > 12) {
					myear += 1;
					mmonth -= 12;
				}
			}
		}
	public:
		Date() :myear{ 2000 }, mmonth{ 1 }, mday{ 1 } {

		}
		Date(int y, int m, int d) :myear{ y }, mmonth{ m }, mday{ d }{
			if (mmonth > 12) {
				cout << "month cannot be greate than 12." << endl;
				exit(EXIT_FAILURE);
			}
			arrangeDate();
		};
		Date& operator++() {
			//prefix
			mday++;
			arrangeDate();
			return *this;
		}
		Date operator++(int) {
			//postfix
			Date returndate{ *this };
			mday++;
			arrangeDate();
			return returndate;
		}

		friend std::ostream& operator<<(std::ostream& out, const Date& date);
};
std::ostream& operator<<(std::ostream& out, const Date& date) {
	out << " " << date.myear << "-" << date.mmonth << "-" << date.mday << " ";
	return out;
}
/*
   Write a class Date that overloads prefix and postfix operators to increase the Date object by one day, while causing appropriate increments to the month and year (use the
   appropriate condition for leap year). The prefix and postfix operators in the Date class should behave exactly like the built-in increment operators.
   */

int main() {
	Date date1{ 2012,2,28 };
	cout << date1 << endl;
	cout << date1++ << endl;
	cout << date1 << endl;
	cout << ++date1 << endl;
	cout << date1 << endl;
	return 0;
}
