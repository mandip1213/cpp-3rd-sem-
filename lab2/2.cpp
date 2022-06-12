#include<iostream>
#define endl '\n'
using std::cout;
void convertFtToIn() {
	int feet{};
	cout << "Enter the length in feet: ";
	std::cin >> feet;
	cout << feet << " feet = " << feet * 12 << " inches." << endl;
}

int convertFtToIn(const int& feet) {
	return feet * 12;
}

int convertFtToIn(const int& feet, const int& inch) {
	return feet * 12 + inch;
}



