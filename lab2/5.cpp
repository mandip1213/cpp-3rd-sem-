#include<iostream>
#define endl '\n'
using std::cout;
float netPayment(float salary) {
	return salary - salary * 0.1f;
}
int main() {
	/*
	 *Assume that employee will have to pay 10 percent income tax to the government. Ask user to enter the employee salary. Use inline function to display the net payment to
	 *the employee by the company.
	 */
	float salary{};
	cout << "Enter your salary: ";
	std::cin >> salary;

	cout << "The net payment after tax deduction is: " << netPayment(salary) << endl;

	return 0;
}

