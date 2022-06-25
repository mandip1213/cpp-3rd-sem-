
#include<iostream>
#include<cstring>
#define endl '\n'
using std::cout;

class Phrase {
	private:
		char* mtext{ nullptr };
	public:
		Phrase() = default;
		Phrase(const char* text) {
			int length = strlen(text) + 1;
			mtext = new char[length];
			memcpy(mtext, text, length);
		}
		~Phrase() {
			delete[] mtext;
		}
		Phrase(const Phrase& phrase):Phrase(phrase.mtext) {
		}
		Phrase join(const Phrase& phrase)const {
			int length = strlen(mtext) + strlen(phrase.mtext) + 1;
			char* newText = new char[length];
			newText[0] = '\0';
			strcat_s(newText, length, mtext);
			strcat_s(newText, length, phrase.mtext);
			Phrase newPhrase;
			newPhrase.mtext = newText;
			return newPhrase;
		}
		void display()const {
			cout << mtext << endl;
		}


};
/*Write a program that has a class with a dynamically allocated character array as its data member. One object should contain "Engineers
 * are" and another should contain " Creatures of logic". Member function join() should concatenate two strings by passing two objects as
 * arguments . Display the concatenated string through a member function. Use constructors to allocate and initialize the data member.
 * Also, write a destructor to free the allocated memory for the character array. Make your own function for the concatenation of two
 * strings.
 */
int main() {
	Phrase p1{ "Engineers are" };
	Phrase p2{ " Creatures of logic" };
	p1.display();
	p2.display();
	Phrase p3 = p1.join(p2);
	p3.display();

	return 0;
}
