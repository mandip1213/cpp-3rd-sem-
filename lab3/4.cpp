#include<iostream>
#define endl '\n'
#define PI 3.14
using std::cout;
class Rectangle {
	private:
		float mlength;
		float mbreadth;
	public:
		void setDimension(float length,float breadth) {
			mlength = length;
			mbreadth = breadth;
		}
		float area() const {
			return mlength * mbreadth;
		}
		float perimeter()const {
			return 2 * (mlength + mbreadth);
		}
		void display()const {
			cout << endl << "The dimensions of the given rectangle is : " << endl <<
				"length : " << mlength << endl <<
				"breadth : " << mbreadth << endl <<
				"perimeter : " << perimeter() << endl <<
				"area : " << area() << endl << endl;
		}
};
class Triangle {
	private:
		float ma;
		float mb;
		float mc;
	public:
		void setDimension(float a, float b, float c) {
			if(a+b>c&&b+c>a&&c+a>b){
				ma = a;
				mb = b;
				mc = c;
				return;
			}
			cout<<"THe given sides cannot be the sides of the triangle"<<endl;
			ma=mb=mc=0;
		}
		float area() const {
			float s{ (ma + mb + mc) / 2 };
			return  sqrt(s * (s - ma) * (s - mb) * (s - mc));
		}
		float perimeter()const {
			return ma + mb + mc;
		}
		void display()const {
			cout << endl << "The dimensions of the given triangle is : " << endl <<
				"side a : " << ma << endl <<
				"side b : " << mb << endl <<
				"side c : " << mc << endl <<
				"perimeter : " << perimeter() << endl <<
				"area : " << area() << endl << endl;
		}
};
class Circle {
	private:
		float mradius;
	public:
		void setDimension(float  radius) {
			mradius = radius;
		}
		float area() const {
			return mradius * mradius * PI;
		}
		float perimeter()const {
			return 2 * PI * mradius;
		}
		void display()const {
			cout << endl << "The dimensions of the given circle is : " << endl <<
				"radius : " << mradius << endl <<
				"perimeter : " << perimeter() << endl <<
				"area : " << area() << endl << endl;
		}
};

int main() {
	/*
	 *Wap with classes to represent a circle, rectangle, and triangle. Each class should have data members to represent the actual objects and member functions to read and
	 *display objects, find perimeter and area of the objects, and other useful fucntions. Use the classes to create objects in your program.
	 */

	Rectangle rect;
	rect.setDimension(3,4);
	rect.display();

	Triangle tri;
	tri.setDimension(3, 4, 5);
	tri.display();

	Circle circle;
	circle.setDimension(2.5);
	circle.display();


	return 0;
}


