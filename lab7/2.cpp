#include<iostream>
#define endl '\n'
using std::cout;

class Person {
protected:
	std::string mname;
	int mage;
public:
	Person() = default;
	Person(const std::string& name, int age) :mname{ name }, mage{ age }{}
};
class Employee :virtual public Person {
protected:
	int msalary;
public:
	Employee(const std::string& name, int age, int sal) :Person{ name,age }, msalary{ sal }{}
	Employee(int sal) : msalary{ sal } {}
};
class Student : virtual public Person {
protected:
	int mclass;
public:
	Student(const std::string& name, int age, int cls) :Person{ name,age }, mclass{ cls }{}
	Student(int cls) :mclass{ cls } {}
};

class Manager :public Student, Employee {
public:
	Manager(const std::string& name, int age, int salary, int cl) :Person{ name,age }, Student{ cl }, Employee{ salary } {}
	void displayDetails() {
		cout << "Name " << mname << endl;
		cout << "Age " << mage << endl;
		cout << "Name " << msalary << endl;
		cout << "class " << mclass << endl;
	}
};

/*
Create a class Person and two derived classes Employeeand Student, inherited from class Person.Now create a class Manager which is derived from two base
classes Employee
and Student. Show the use of the virtual base class.
*/

int main() {
	Manager manager{ "lorem",40,10000 ,10 };
	manager.displayDetails();
	return 0;
}

