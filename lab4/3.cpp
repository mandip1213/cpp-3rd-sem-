#include<iostream>
#define endl '\n'
using std::cout;

class Department {
private:
	int mid;
	char* mname = nullptr;
public:
	Department() = default;
	Department(int id, const char* name) :mid{ id } {
		int length = strlen(name) + 1;
		mname = new char[length];
		memcpy(mname, name, length);
		cout << "Object "<<mid<<"created" << endl;
	}
	~Department() {
		delete[] mname;
		cout << "Object " << mid << " goes out of scope "<< endl;
	}
	void display() const{
		cout << mid << " " << mname << endl;
	}
};
/*
*Write a class that can store Department ID and Department Name with constructors to initialize its members. Write destructor member in the same class and display the message
*"Object n goes out of the scope". Your program should be made such that it should show the order of constructor and destructor invocation.
*/
int main() {
	Department dep1{ 1,"BCT" };
	Department dep2{ 2,"BME" };
	Department dep3{ 3,"BEI" };
	Department dep4{ 4,"BCE" };

	return 0;
}
