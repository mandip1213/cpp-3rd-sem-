#include<iostream>
#define endl '\n'
using std::cout;

int& replaceLarger(int& temp1, int& temp2) {
	return (temp1>temp2?temp1:temp2);
}

int main() {
	/*Write a function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using
	 * return by reference.*/

	int temp1{}, temp2{} , newTemp{};
	cout << "Enter temp1: ";
	std::cin >> temp1;
	cout << "Enter temp2: ";
	std::cin >> temp2;
	cout << "Enter the value to replace larger temperature : ";
	std::cin >> newTemp;

	cout << "Before replacing:" << endl;
	cout << "Temp1: " << temp1 << endl;
	cout << "Temp2: " << temp2 << endl;

	replaceLarger(temp1, temp2) = newTemp;

	cout << "After replacing:" << endl;
	cout << "Temp1: " << temp1 << endl;
	cout << "Temp2: " << temp2 << endl;

	return 0;
}

