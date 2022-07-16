#include<iostream>
#include<string>
#define endl '\n'
using std::cout;

class Musicians {
	protected:
		std::string mperc[5];
		std::string mstring[5];
		std::string mwind[5];
	public:
		void string() {
			mstring[0] = "veena";
			mstring[1] = "guitar";
			mstring[2] = "sitar";
			mstring[3] = "sarod";
			mstring[4] = "mandolin";
			cout << "String Instruments:\n[\t";
			for (auto currStr : mstring) {
				cout << currStr << "\t";
			}
			cout << "]";
		}
		void perc() {
			mperc[0] = "veena";
			mperc[1] = "guitar";
			mperc[2] = "sitar";
			mperc[3] = "sarod";
			mperc[4] = "mandolin";
			cout << "Percussion Instruments\n[\t ";
			for (auto currStr : mperc) {
				cout << currStr << "\t ";
			}
			cout << "]";
		}
		void wind() {
			mwind[0] = "veena";
			mwind[1] = "guitar";
			mwind[2] = "sitar";
			mwind[3] = "sarod";
			mwind[4] = "mandolin";
			cout << "Wind instruments\n[\t ";
			for (auto currStr : mwind) {
				cout << currStr << "\t ";
			}
			cout << "]";
		}

};
class TypeIns :public Musicians {
	private:
		char mchoice;
	public:
		void get() {
			cout << "Type of instruments to be displayed" << endl;
			cout << "a.  String instruments" << endl;
			cout << "b.  Wind instruments" << endl;
			cout << "c.  Percussion instruments" << endl;
			cout << "Enter your choice: " << endl;
			std::cin >> mchoice;
			show();
		}
		void show() {
			switch (mchoice) {
				case 'a':string(); break;
				case 'b': wind(); break;
				case 'c':perc(); break;
				default:
						 cout << endl << endl << "Please choose from the available choice" << endl << endl;
						 get();
						 break;
			}
		}
};
/*
   Create a class called Musicians to contain three methods string(), wind(), and perc(). Each of these methods should initialize a string array to contain the following instruments
   -  veena, guitar, sitar, sarod and mandolin under string()
   -  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()
   -  tabla, mridangam, bangos, drums and tambour under perc()
   It should also display the contents of the arrays that are initialized. Create a derived class called TypeIns to contain a method called get() and show(). The get() method must display a  menu as follows
   Type of instruments to be displayed
   a.  String instruments
   b.  Wind instruments
   c.  Percussion instruments
   The show() method should display the relevant detail according to our choice. The base class variables must be accessible only to their derived classes.
   */

int main() {
	TypeIns type;
	type.get();

	return 0;
}
