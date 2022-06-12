#include<iostream>
#define endl '\n'
using std::cout;
void increaseSalary(float& currSalary, int increment = 10) {
	currSalary += increment / 100.0 * currSalary;
}
enum {
	CEO_INCREMENT = 9,
	IO_INCREMENT = 10,
	SA_INCREMENT = 12,
	PGM_INCREMENT = 12,
};
int main() {
	/*
	*Write a program that displays the current monthly salary of chief executive officer, information officer, and system analyst, programmer that has been increased by 9, 10,
	*12, and 12 percentages respectively in year 2010. Let us assume that the salaries in year 2009 are
*Chief executive officer Rs. 35000/m
*Information officer Rs. 25000/m
*System analyst Rs. 24000/m
*Programmer Rs. 18000/m
*Make a function that takes two arguments; one salary and the other increment. Use proper default argument.
	*/
	float ceo_salary{ 35000 };
	float io_salary{ 35000 };
	float sa_salary{ 35000 };
	float pgm_salary{ 1000 };

	cout << "The salary in 2009 was: " << endl;
	cout << "ceo_salary: " << ceo_salary << endl;
	cout << "io_salar: " << io_salary << endl;
	cout << "sa_salar: " << sa_salary << endl;
	cout << "pgm_salar: " << pgm_salary << endl;

	increaseSalary(ceo_salary, CEO_INCREMENT);
	increaseSalary(io_salary, IO_INCREMENT);
	increaseSalary(sa_salary, SA_INCREMENT);
	increaseSalary(pgm_salary, PGM_INCREMENT);

	cout << endl << endl;
	cout << "The salary in 2010 is: " << endl;
	cout << "ceo_salary: " << ceo_salary << endl;
	cout << "io_salar: " << io_salary << endl;
	cout << "sa_salar: " << sa_salary << endl;
	cout << "pgm_salar: " << pgm_salary << endl;

	return 0;
}
