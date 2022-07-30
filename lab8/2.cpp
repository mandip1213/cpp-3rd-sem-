/*
   Write a program to create a user-defined manipulator that will format the output by setting the width, 
   precision, and fill character at the same time by passing arguments.
   */
#include<iostream>
#include<iomanip>
using namespace std;
class MyManipulator {
	public:
		MyManipulator(unsigned w = 0, unsigned pre = 6, char c = ' ') :wid(w), precs(pre), fill(c) {

		}
		MyManipulator(const MyManipulator&) = delete;


		friend ostream& operator <<(ostream& os, const MyManipulator& man) {
			os << setprecision(man.precs) << setw(man.wid) << setfill(man.fill);
			return os;
		}
	private:
		unsigned wid;
		unsigned precs;
		char fill;
};

int main() {
	cout << "Manipulator:" << MyManipulator(8, 3, '@') << 1.2435535;
	return 0;
}

