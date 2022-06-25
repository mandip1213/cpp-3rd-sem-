#include<iostream>
#define endl '\n'
using std::cout;
class Result {
private:
	int msubid;
	int mmarks;
public:
	Result() :msubid{ 0 }, mmarks{ 40 }{}
	Result(int id, int m) :msubid{ id }, mmarks{ m }{}
	void display() const {
		cout << "subject " << msubid << " : " << mmarks << " marks" << endl;
	}
	void increaseMarks(int mark) {
		mmarks += mark;
	}
};
/*
Write a program that illustrates the following relationship and comment on them.
i) const_object.non_const_mem_function
ii) const_object.const_mem_function
iii) non_const_object.non_const_mem_function
iv) non_const_object.const_mem_function
*/
int main() {
	Result math{ 1,60 };
	const Result oop{ 2,30 };

	oop.display(); //const object.const_mem_function
	math.display(); //non_const_object.const_mem_function
	math.increaseMarks(10); //non_const_object.non_const_function
	//oop.increaseMarks(13);//const object.const_mem_function
	//Error:  The object has type qualifiers that arenot compatible with member functions




	return 0;
}
