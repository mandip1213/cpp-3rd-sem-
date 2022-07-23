#include<iostream>
#include<array>
#define endl '\n'
using std::cout;

class Student {
	public:
		virtual void printClass() {
			cout << "Student class" << endl;
		};
};

class Science : public Student {
	public:
		virtual void printClass() {
			cout << "Science class" << endl;
		};
};
class Medicine : public Student {
	public:
		virtual void printClass() {
			cout << "Medicine class" << endl;
		};

};
class Engineering : public Student {
	public:
		virtual void printClass() {
			cout << "Engineering class" << endl;
		};

};

/*
   Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of
   the derived classes and process them and access them using an array of pointers of type base class Student.
   */
int main() {
	Engineering e;
	Science s;
	Medicine m;
	Student st;
	std::array<Student*, 4> sarr{ &e, &s, &m ,&st };
	for (auto ptr : sarr) {
		ptr->printClass();
	}
	return 0;
}
