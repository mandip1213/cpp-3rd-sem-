#include<iostream>
#include<cmath>
#define endl '\n'
using std::cout;
class Integer {
	private:
		int mvalue;
	public:
		Integer() = default;
		Integer(int a) :mvalue{ a } {}
		bool operator==(const Integer& a)const;
		bool operator!=(const Integer& a)const;
		bool operator<(const Integer& a)const;
		bool operator>(const Integer& a)const;
		bool operator<=(const Integer& a)const;
		bool operator>=(const Integer& a)const;
		friend std::ostream& operator<<(std::ostream& out, Integer a);
};
bool Integer::operator==(const Integer& a)const {
	return (mvalue == a.mvalue);
}
bool Integer::operator!=(const Integer& a)const {
	return (mvalue != a.mvalue);
}
bool Integer::operator<(const Integer& a) const {
	return (mvalue < a.mvalue);
}
bool Integer::operator>(const Integer& a) const {
	return (mvalue > a.mvalue);
}
bool Integer::operator>=(const Integer& a) const {
	return (mvalue >= a.mvalue);
}
bool Integer::operator<=(const Integer& a) const {
	return (mvalue <= a.mvalue);
}
std::ostream& operator<<(std::ostream& out, Integer a) {
	out << a.mvalue;
	return out;
}
/*
   Write a program to compare two objects of a class that contains an integer value as its data member. Make overloading functions to overload equality(==), less than(<), greater
   than(>), not equal (!=), greater than or equal to (>=), and less than or equal to(<=) operators using member operator functions.
   */
int main() {
	Integer a{ 4 };
	Integer b{ 6 };
	cout << std::boolalpha;
	cout << a << " > " << b << " : " << (a > b) << endl;
	cout << a << " < " << b << " : " << (a < b) << endl;
	cout << a << " == " << b << " : " << (a == b) << endl;
	cout << a << " != " << b << " : " << (a != b) << endl;
	cout << a << " <= " << b << " : " << (a <= b) << endl;
	cout << a << " >= " << b << " : " << (a >= b) << endl;

	return 0;
}
