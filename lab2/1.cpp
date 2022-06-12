#include<iostream>
#define endl '\n'
using std::cout;
typedef struct {
	int year;
	int month;
	int day;
}Date;

std::ostream& operator<<(std::ostream& out,const  Date& date) {
	cout << date.month << " / " << date.day << " / " << date.year;
	return out;
};

int main() {
	/*
	 *Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by
	 *function. Pass the structure to the function
	 */
	Date date{2000,11,26};
	cout << "The date is: " << date;

	return 0;
}

