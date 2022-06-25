#include<iostream>
#define endl '\n'
using std::cout;

class Fare {
private:
	int mnum_vehicle;
	float mhour;
	float mrate;
public:
	Fare(int nv, float h, float r) :mnum_vehicle{ nv }, mhour{ h }, mrate{ r } {
	}
	Fare(const Fare& fare) {
		mnum_vehicle= fare.mnum_vehicle ;
		mhour= fare.mhour ;
		mrate= fare.mrate ;
	}
	void display() const{
		cout << "num_vehicle: " << mnum_vehicle << endl;
		cout << "hour: " << mhour << endl;
		cout << "rate: " << mrate << endl;
		cout << "Total charge: " << mrate * mhour * mnum_vehicle * (mnum_vehicle > 10 ? 0.9 : 1) << endl;
	}
};
/*
Assume that one constructor initializes data member say num_vehicle, hour, and rate. There should be a 10% discount if num_vehicle exceeds 10. Display the total charge. Use
two objects and show a bit-by-bit copy of one object to another (make your own copy constructor).
*/
int main() {
	Fare fare1{ 11,10,20 };
	Fare fare2{ fare1 };
	fare2.display();


	return 0;
}
