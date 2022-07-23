#include<iostream>
#include<string>
#define endl '\n'
#define PI 3.141592
using std::cout;

class Shape {
public:
	virtual  double  area() const {
		return 0.0;
	}
	virtual std::string getName() const {
		return "shape";
	}
	virtual ~Shape() {
		cout << "Base class shape: desturctor" << endl;
	}
};
class Circle :public Shape {
private:
	double mradius;
public:
	Circle(double r) :mradius{ r } {
	}
	std::string getName()  const override {
		return " circle ";
	}
	double area()  const override {
		return PI * mradius * mradius;
	}
	~Circle()override {
		cout << "Derived Class Circle: desturctor" << endl;
	}
};
class Rectangle :public Shape {
private:
	double mlength;
	double mbreadth;
public:
	Rectangle(double l, double b) :mlength{ l }, mbreadth{ b } {
	}
	std::string getName()  const override {
		return " Rectangle ";
	}
	double area()  const override {
		return mlength * mbreadth;
	}
	~Rectangle() {
		cout << "Derived class Rectangle: desturctor" << endl;
	}
};
class Trapezoid :public Shape {
private:
	double mside1;
	double mside2;
	double mheight;
public:
	Trapezoid(double s1, double s2, double  h) :mside1{s1}, mside2{s2}, mheight{ h }{
	}
	std::string getName()  const override {
		return " Trapezoid ";
	}
	double area()  const override {
		return (mside1 + mside2) * mheight / 2;
	}
	~Trapezoid() {
		cout << "Derived class trapezoid: desturctor" << endl;
	}
};

/*
Write a program to create a class shape with functions to find the area of the shapes and display the names of the shapes and other essential components of the class.
Create derived classes circle, rectangle, and trapezoid each having overriding functions area() and display(). Write a suitable program to illustrate virtual functions and
virtual destructors.
*/

int main() {

	Circle circle{ 3 };
	Shape* cShape{ &circle };
	cout << "Area of" << cShape->getName() << "is " << cShape->area() << " m^2" << endl; //calls the functions of circle
	Rectangle rect{ 4,5 };
	Shape* rShape{ &rect };
	cout << "Area of" <<rShape->getName() << "is " << rShape->area() << " m^2" << endl; //calls the functions of circle
	Trapezoid trap{ 4,5,6 };
	Shape& tShape{ trap };
	cout << "Area of" << tShape.getName() << "is " << tShape.area() << " m^2" << endl; //calls the functions of circle


	cout << endl << endl;
	//calls destructor before returning
	return 0;
}

