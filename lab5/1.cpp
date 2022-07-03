#include<iostream>
#include<cmath>
#define endl '\n'
using std::cout;
class Coordinates;
class Function {
	public:
		static	Coordinates add(const Coordinates& a, const Coordinates& b);

};
class Coordinates {
	private:
		double mx;
		double my;
	public:
		Coordinates(double x = 0, double y = 0) :mx{ x }, my{ y }{}
		friend Coordinates Function::add(const Coordinates& a, const Coordinates& b);
		friend Coordinates difference(const Coordinates& a, const Coordinates& b);
		friend Coordinates product(const Coordinates& a, const Coordinates& b);
		friend Coordinates divide(const Coordinates& a, const Coordinates& b);
		friend class Utils;


};
class Utils {
	public:
		static	double distance(const Coordinates& a, const Coordinates& b) {
			return sqrt(pow(a.mx - b.mx, 2) + pow(a.my - b.my, 2));
		}
		static Coordinates midpoint(const Coordinates& a, const Coordinates& b) {
			return Coordinates{ (a.mx + b.mx) / 2, (a.my + b.my) / 2 };
		}
		static	void display(const Coordinates& a) {
			cout << "(" << a.mx << " , " << a.my << ")" << endl;
		}
};

Coordinates difference(const Coordinates& a, const Coordinates& b) {
	return Coordinates{ a.mx - b.mx,a.my - b.my };
}
Coordinates product(const Coordinates& a, const Coordinates& b) {
	return Coordinates{ a.mx * b.mx,a.my * b.my };
}
Coordinates divide(const Coordinates& a, const Coordinates& b) {
	return Coordinates{ a.mx / b.mx,a.my / b.my };
}
Coordinates Function::add(const Coordinates& a, const Coordinates& b) {
	return Coordinates{ a.mx + b.mx,a.my + b.my };
};
/*
   Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
   A. Make a particular member function of one class as a friend function of another class for addition.
   B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
   C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.
   */
int main() {
	Coordinates A{ 1,2 };
	Coordinates B{ 5,5 };
	cout << "A: ";
	Utils::display(A);
	cout << "B: ";
	Utils::display(B);
	cout << "The sum of A and B is: ";
	Utils::display(Function::add(A, B));
	cout << "The difference of A and B is: ";
	Utils::display(difference(A, B));
	cout << "The distance between A and B is: " << Utils::distance(A, B) << endl;
	cout << "The midpoint between A and B is: ";
	Utils::display(Utils::midpoint(A, B));
	return 0;
}
