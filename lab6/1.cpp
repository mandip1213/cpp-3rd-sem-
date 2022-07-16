#include<iostream>
#define endl '\n'
using std::cout;
class Distance {
private:
	int mmeter;
	int mcentimeter;
public:
	Distance(float dis) :mmeter{ static_cast<int>(dis) }, mcentimeter{ static_cast<int>((dis - mmeter) * 100) } {}
	Distance(int m, int cm) :mmeter{ m }, mcentimeter{ cm }{}
	explicit operator float() const{
		return mmeter + mcentimeter / 100.0;
	}
	friend std::ostream& operator <<(std::ostream& out, const Distance& dis);

};
std::ostream& operator <<(std::ostream& out, const Distance& dis) {
	out << " " << dis.mmeter << " m " << dis.mcentimeter << " cm ";
	return out;
}
/*
   Write a program that can convert the Distance (meter, centimeter) to meters measurement in float and vice versa. Make a class distance with two data
   members, meter and centimeter. You can add function members as per your requirement.
   */
int main() {
	Distance dis{ 44,80 };
	cout << dis << " = " << static_cast<float>(dis)<<" m" << endl;
	float fdistance{ 22.2 };
	Distance diss{fdistance};
	cout <<fdistance<<"m = "<< diss << endl;


	return 0;
}

