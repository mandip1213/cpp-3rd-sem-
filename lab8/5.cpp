#include<iostream>
#include<fstream>
#define endl '\n'
/*
Write a program for transaction processing that write and read object randomly to and from a random access file so that user can add, update, delete and display the account information
(account-number, last-name, first-name, total-balance).
*/
using namespace std;
struct Account {
	char fName[100];
	char lName[100];
	unsigned accN;
	float balance;

	static unsigned getcount(string filename) {
		fstream file(filename, ios::in | ios::binary | ios::ate);
		if (!file.is_open())
			return 0;
		unsigned count = file.tellg() / sizeof(Account);
		file.close();
		return count;
	}

	bool readFrom(fstream& file, unsigned position) {
		if (!file.is_open())
			return false;
		file.seekg(0, ios::end);
		unsigned count = file.tellg() / sizeof(Account);
		if (position >= count)
			return false;
		file.seekg(sizeof(Account) * position, ios::beg);
		file.read(reinterpret_cast<char*>(this), sizeof(Account));
		return true;
	}
	bool readFrom(string filename, unsigned position) {
		fstream file(filename, ios::in | ios::ate | ios::binary);
		bool result = readFrom(file, position);
		file.close();
		return result;
	}
	bool writeTo(fstream& file, unsigned position) {
		if (!file.is_open())
			return false;
		file.seekg(0, ios::end);
		unsigned count = file.tellg() / sizeof(Account);
		if (position > count)
			position = count;
		file.seekg(sizeof(Account) * position, ios::beg);
		file.write(reinterpret_cast<const char*>(this), sizeof(Account));
		file.close();
		return true;
	}
	bool writeTo(string filename, unsigned position) {
		fstream file(filename, ios::binary | ios::app | ios::in);
		bool result = writeTo(file, position);
		file.close();
		return result;
	}
	void getRecord() {

		cout << "\nAccount Number : ";
		cin >> accN;
		cout << "First Name : ";
		cin >> fName;
		cout << "Last Name : ";
		cin >> lName;
		cout << "Balance : ";
		cin >> balance;
	}
};

int main() {
	string fileName;
	cout << "Enter the file name ";
	cin >> fileName;

	char choice = 'c';

	cout << "Enter your choice as follow : "
		<< "\nDisplay records : d"
		<< "\nAdd record : a"
		<< "\nRemove record : r"
		<< "\nUpdate record : u"
		<< "\nQuit : q";
	while (choice != 'q' && choice != 'Q') {
		cout << "\nEnter choice : ";
		cin >> choice;
		switch (choice) {
		case 'd':
		{

			unsigned count = Account::getcount(fileName);

			fstream file(fileName, ios::binary | ios::in);

			for (unsigned n = 0; n < count; n++) {
				Account acc;
				acc.readFrom(file, n);
				std::cout << "\nRecord No :" << n + 1 << "\n\tName:" << acc.fName << " " << acc.lName
					<< "\n\tAcc No : " << acc.accN
					<< "\n\tBalance : " << acc.balance << endl;
			}
			file.close();
		}
		break;
		case 'r':
		{
			cout << "Enter record number to remove : ";
			int n;
			cin >> n;

			unsigned count = Account::getcount(fileName);
			if ((n > Account::getcount(fileName) || (n <= 0))) {
				cout << "Invalid Record.\n";
				break;
			}
			for (unsigned i = 0; i < count; i++) {
				Account acc;
				if (i < (n - 1)) {
					acc.readFrom(fileName, i);
					acc.writeTo("tempfile", i);
				}
				else if (i > (n - 1)) {
					acc.readFrom(fileName, i);
					acc.writeTo("tempfile", i - 1);
				}
			}

			remove(fileName.c_str());
			rename("tempfile", fileName.c_str());
			remove("tempfile");
		}
		break;
		case 'u':
		{
			cout << "Enter record number to update : ";
			int n;
			cin >> n;
			unsigned count = Account::getcount(fileName);
			if ((n > count) || (n <= 0)) {
				cout << "Invalid Record.\n";
				break;
			}
			for (unsigned i = 0; i < count; i++) {
				Account acc;
				if (i == (n - 1)) {
					cout << "\nEnter record to update : ";
					acc.getRecord();
					acc.writeTo("tempfile", i);
				}
				else {
					acc.readFrom(fileName, i);
					acc.writeTo("tempfile", i);
				}
			}

			remove(fileName.c_str());
			rename("tempfile", fileName.c_str());
			remove("tempfile");

		}
		break;
		case 'a':
		{
			cout << "Enter record number to add after : ";
			int n;
			cin >> n;
			unsigned count = Account::getcount(fileName);
			if (n > count)
				n = count;
			if (n <= 0)
				n = 0;

			for (unsigned i = 0; i < count + 1; i++) {
				Account acc;
				if (i < (n)) {
					acc.readFrom(fileName, i);
					acc.writeTo("tempfile", i);
				}
				else if (i == n) {

					cout << "\nEnter record to add : ";
					acc.getRecord();
					acc.writeTo("tempfile", i);
				}
				else if (i > (n)) {
					acc.readFrom(fileName, i - 1);
					acc.writeTo("tempfile", i + 1);
				}
			}

			remove(fileName.c_str());
			rename("tempfile", fileName.c_str());
			remove("tempfile");

		}
		break;
		}
	}
	return 0;
}

