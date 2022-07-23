#include<iostream>
#include<typeinfo>
#include<array>
#define endl '\n'
using std::cout;
class Vehicle {
	public:
		virtual ~Vehicle() {};

};
class Car :public Vehicle {

};
class Bike :public Vehicle {

};
class Bus :public Vehicle {

};

/*
   Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid
   operators in this program.
   */

int main() {
	Car c;
	Bike b;
	Bus bs;
	std::array<Vehicle*, 3>ptrs{ &c,&b,&bs };
	for (auto item : ptrs) {
		cout << typeid(item).name() << endl;
	}
	cout << endl;
	for (auto item : ptrs) {
		cout << typeid(*item).name() << endl;
	}
	for (auto item : ptrs) {
		Car* tempCarPtr = dynamic_cast<Car*>(item);
		if (!tempCarPtr)
			cout << typeid(item).name()<<"("<<typeid(*item).name()<<")" << " -> " << typeid(tempCarPtr).name() << " not possible" << endl;
		else
			cout << typeid(item).name() <<"("<<typeid(*item).name()<<")" << " -> " << typeid(tempCarPtr).name() << "  conversion successful" << endl;
	}

	Bike* bikeptr = dynamic_cast<Bike*>(ptrs[1]);


	return 0;
}


