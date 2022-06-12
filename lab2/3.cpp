#include<iostream>
#define endl '\n'
using std::cout;

namespace square {
	int num{};
	int fun(int num) {
		return (num * num);
	}
}

namespace cube {
	int num{};
	int fun(int num) {
		return num * num * num;
	}
}

int main() {
	/*
	*Define two namespaces: Square and Cube. In both the namespaces, define an integer variable named "num" and a function named "fun". The "fun" function in "Square"
	*namespace, should return the square of an integer passed as an argument while the "fun" function in "Cube" namespace, should return the cube of an integer passed as an
	*argument. In the main function, set the integer variables "num" of both the namespaces with different values. Then, compute and print the cube of the integer variable
	*"num" of the "Square" namespace using the "fun" function of the "Cube" namespace and the square of the integer variable "num" of the "Cube" namespace using the "fun"
	*function of the "Square" namespace.
	*/

	square::num = 5;
	cube::num = 6;
	cout << "The cube of " << square::num << " is " << cube::fun(square::num) << endl;
	cout << "The square of " << cube::num << " is " << square::fun(cube::num) << endl;

	return 0;
}

