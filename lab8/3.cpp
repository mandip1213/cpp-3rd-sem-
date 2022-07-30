#include<iostream>
#define endl '\n'
using std::cout;

/*
   Write a program to overload stream operators to read a complex number and display the complex number in a+ib format.
   */
class Complex {
private:
	int mr;
	int mi;
public:
	Complex() = default;
	Complex(int r, int i) :mr{ r }, mi{ i }  {
	}

	friend std::istream& operator>>(std::istream& in, Complex& c);
	friend std::ostream& operator<<(std::ostream& out, const Complex& c);
};
std::istream& operator>>(std::istream& in, Complex& c) {
	cout << "real part: ";
	in >> c.mr;
	cout << "imaginary part: ";
	in >> c.mi;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Complex& c) {
	out << c.mr << " + i" << c.mi;
	return out;
}
int main() {
	Complex c;
	cout << "Enter a complex number." << endl;
	std::cin >> c;
	cout << "The complex number is: " << c << endl;
	return 0;
}

