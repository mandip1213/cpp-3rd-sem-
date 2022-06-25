#include<iostream>
#include<cmath>
#define endl '\n'
using std::cout;
class Prime {
	private:
		int mvalue{};
	public:
		void setNum(int num) {
			mvalue = num;
		}
		bool isPrime(){
			if (mvalue<2) {
				return false;
			}
			for (int i = 2; i < mvalue; i++)
			{
				if (mvalue % i == 0) {
					return false;
				}
			}
			return true;
		};
		int getNum()const {
			return mvalue;
		}
};
int main() {

	/*Wap that asks for numbers repeatedly. When it finishes checking a number is prime or not, program asks i the user wants to do another calculation. The response can be
		'y' or 'n'. Don't forget to use the object-oriented concept. */
	cout << "WELCOME TO PRIME NUMBER CHECKER: " << endl << endl;
	while (1) {
		int num;
		cout << "Enter a number: ";
		std::cin >> num;
		Prime prime;
		prime.setNum(num);
		cout << "The number you have entered " << num << " is" << (prime.isPrime()  ? " " : " not ") << "prime" << endl;
		char c;
		cout << "Do you wnat to check another number? (y/n) ";
		std::cin >> c;
		if (c != 'y')
			break;
	}
	return 0;
}
