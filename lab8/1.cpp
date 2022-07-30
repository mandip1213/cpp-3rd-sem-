#include <iostream>
#include <string>
#include <iomanip>
//lINK: https://github.com/bipul018/ClassCppPractice/blob/master/lab8/lab8.cpp
namespace Q1 {

	using namespace std;
	struct ItemDetail {
		std::string name;
		float unitPrice;
		int quantity;
	};

	int main() {

		string departName;
		unsigned size = 0;
		float totalAmt = 0;
		int totalQty = 0;
		cout << "Enter name of store : ";
		getline(cin, departName);
		cout << "Enter number of items types bought : ";
		cin >> size;
		ItemDetail* pItem = new ItemDetail[size];

		unsigned maxNameLen = string("Particulars").length();

		for (unsigned i = 0; i < size; i++) {
			cout << "Enter item name : ";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			getline(cin, pItem[i].name);
			cout << "Enter unitPrice : ";
			cin >> pItem[i].unitPrice;
			cout << "Enter quantity : ";
			cin >> pItem[i].quantity;
			if (pItem[i].name.length() > maxNameLen)
				maxNameLen = pItem[i].name.length();
		}
		cout << endl << departName;
		cout << "\nTAX INVOICE\n";
		cout<<endl<< "  SN"<< setw(maxNameLen + 1) << left << " Particulars";
		cout.setf(ios::right);
		cout<< " Qty" << setw(9) << "Rate"
			<< setw(9) << "Amount" << endl;

		cout << setw(maxNameLen + 28) << setfill('-') << '\n';
		cout.fill(' ');
		for (int i = 0; i < size; i++) {

			cout << setw(4) << i+1 << " ";
			cout.unsetf(ios::right);
			cout<< left << setw(maxNameLen) << pItem[i].name;
			cout.setf(ios::right);
			cout << setw(4) << pItem[i].quantity << setw(9) 
				<< pItem[i].unitPrice << setw(9) << pItem[i].quantity*pItem[i].unitPrice << endl;
			totalAmt += pItem[i].quantity * pItem[i].unitPrice;
			totalQty += pItem[i].quantity;
		}
		cout << "Total Quantity = " << totalQty << endl << "Total Amount = " << totalAmt << endl;

		delete[] pItem;

		return 0;
	}	

}

#include <iostream>
#include <cstdlib>

int main() {

	Q5::main();
	system("pause");
	std::cout << std::endl;
	return 0;
	Q1::main();
	system("pause");
	std::cout << std::endl;

	Q2::main();
	system("pause");
	std::cout << std::endl;

	Q3::main();
	system("pause");
	std::cout << std::endl;

	Q4::main();
	system("pause");
	std::cout << std::endl;

	Q5::main();
	system("pause");
	std::cout << std::endl;

	return 0;
}
