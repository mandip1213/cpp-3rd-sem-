#include<iostream>
#include<fstream>
#define endl '\n'
using std::cout;

/*
Write a program that stores the information about students (name, student id, department, and address) in a structure and then transfers the information to a file in your directory. Finally,
retrieve the information from your file and print it in the proper format on your output screen.
*/
struct Student {
	std::string name;
	int id;
	std::string department;
	std::string address;
};

std::ostream& operator<<(std::ostream& out, const Student& s) {
	out << "Id: " << s.id << endl;
	out << "Name: " << s.name << endl;
	out << "Department: " << s.department << endl;
	out << "Address: " << s.address << endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, const Student& s) {
	out << s.id << ' ' << s.name << ' ' << s.department << ' ' << s.address<<endl;
	return out;
}
std::ifstream& operator>>(std::ifstream& in, Student& s) {
	in >> s.id >> s.name >> s.department >> s.address;
	return in;
}


int main() {
	Student st{
		.name = "Lorem",
		.id = 1,
		.department = "BCT",
		.address = "Riverhill"
	};

	std::ofstream foptr{ "student.txt" };
	foptr << st;
	foptr.close();

	Student stu;
	std::ifstream fiptr{ "student.txt" };
	fiptr >> stu;
	cout << "The retreived student data is: " << endl;
	cout << stu;

	return 0;
}

