#include<iostream>
#define endl '\n'
using std::cout;
class Id {
private:
	static	int sidGenerator;
	int mserialNumber;
public:
	Id() :mserialNumber{ sidGenerator++ } { }
	void display() {
		cout << "Id: " << mserialNumber << endl;
	}
	static int getNextId()  {
		return sidGenerator;
	}

};
int Id::sidGenerator = 0;//initialization of static memeber variable
/*
Create a class with a data member to hold a "serial number" for each object created from the class. That is, the first object created will be numbered 1, the second 2, and
so on by using the basic concept of static data members. Use static member function if it is useful in the program. Otherwise, make a separate program that demonstrates the
use of static member function.
*/
int main() {
	Id id1;
	Id id2;
	Id id3;
	id1.display();
	id2.display();
	id3.display();

	cout << endl << "The id of next object will be " << Id::getNextId() << "." << endl;
	return 0;
}
