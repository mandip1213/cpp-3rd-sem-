#include<iostream>
#include<cmath>
#define endl '\n'
using std::cout;
class Coordinates {
private:
	int mx, my, mz;
public:
	Coordinates() = default;
	Coordinates(int x, int y, int z) :mx{ x }, my{ y }, mz{ z } {};
	friend Coordinates  operator+(const Coordinates& a, const Coordinates& b);
	friend Coordinates  operator-(const Coordinates& a, const Coordinates& b);
	friend std::ostream& operator<<(std::ostream& out, const Coordinates& a);
};

std::ostream& operator<<(std::ostream& out, const Coordinates& a) {
	out << "(" << a.mx << ", " << a.my << ", " << a.mz << ")";
	return out;
}
Coordinates  operator+(const Coordinates& a, const Coordinates& b) {
	return Coordinates{ a.mx + b.mx,a.my + b.my,a.mz + b.mz };
}
Coordinates  operator-(const Coordinates& a, const Coordinates& b) {
	return Coordinates{ a.mx - b.mx,a.my - b.my,a.mz - b.mz };
}

/*
Write a class to store x, y, and z coordinates of a point in three-dimensional space. Overload addition and subtraction operators for addition and subtraction of two
coordinate objects. Implement the operator functions as non-member functions (friend operator functions).
*/
int main() {
	Coordinates A{ 3,4,6 }, B{ 1,2,1 };
	cout << "A: " << A<<endl;
	cout << "B: " << B<<endl;
	cout << "The sum of A and B is: " << A + B << endl;
	cout << "The sum of A and B is: " << A - B << endl;
	return 0;
}

