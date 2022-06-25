#include<iostream>
#define endl '\n'
using std::cout;
class Employee {
	private:
		int mid;
		float  mbonus;
		float movertime;
		int myear;
	public:
		void setPara(int id, float bonus, float overtime, int year) {
			mid = id;
			mbonus = bonus;
			movertime = overtime;
			myear = year;
		}
		void displayReport() {
			cout << endl << "An employee with id " << mid << " has received Rs" << mbonus << " as bonus and had worked " << movertime << " hours as overtime in the year " << myear << "." << endl;
		}
};

int main() {
	/*
	 * Assume that an object represents an Employee report that contains info like id, total bonus, total overtime in a particular year.
	 * Use an array of objects to represent n employeea' reports. WAP that displays the report.
	 * Use `setPara` member member function toset report attributes by passing arguments
	 * and member function to display report to according to parameter set.
	 * Display the report in the following  format:
	 * An employee with ... has received Rs... as bonus and had worked ... hours as overtime in the year ...  .
	 */
	int n;
	cout << "Enter the number of employees: ";
	std::cin >> n;
	Employee* employees=new Employee[n];
	for (int i = 0; i < n; i++)
	{
		int id, year;
		float overtime, bonus;
		cout << "Enter details for employee " << i + 1 << ": " << endl;
		cout << "id: ";
		std::cin >> id;
		cout << "bonus: ";
		std::cin >> bonus;
		cout << "overtime: ";
		std::cin >> overtime;
		cout << "year: ";
		std::cin >> year;
		employees[i].setPara(id, bonus, overtime, year);
	}
	cout << endl << "Report of Each employee :" << endl;
	for (int i= 0; i < n; i++) {
		employees[i].displayReport();
	}
	delete[] employees;
	return 0;
}


