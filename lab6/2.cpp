#include<iostream>
#define endl '\n'
using std::cout;
#define MTRTOFEETRATIO 3.28084

/*
   Write two classes to store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert
   objects of both types.
   */
class SI;
class ImperialSystem {
	private:
		int mfeet;
		int minch;
	public:
		ImperialSystem(int m, int cm) :mfeet{ m }, minch{ cm }{};
		ImperialSystem(float dis) :mfeet{ static_cast<int>(dis) }, minch{ static_cast<int>((dis - mfeet) * 12) } {}
		explicit operator SI()const;
		friend std::ostream& operator <<(std::ostream& out, const ImperialSystem& dis);
};

class SI {
	private:
		int mmeter;
		int mcentimeter;
	public:
		SI(int m, int cm) :mmeter{ m }, mcentimeter{ cm }{};
		SI(float dis) :mmeter{ static_cast<int>(dis) }, mcentimeter{ static_cast<int>((dis - mmeter) * 12) } {}
		explicit operator ImperialSystem() const;
		friend std::ostream& operator <<(std::ostream& out, const SI& dis);
};

std::ostream& operator <<(std::ostream& out, const SI& dis) {
	out << " " << dis.mmeter << " m " << dis.mcentimeter << " cm ";
	return out;
}
std::ostream& operator <<(std::ostream& out, const ImperialSystem& dis) {
	out << " " << dis.mfeet << " ft " << dis.minch << " in ";
	return out;
}
ImperialSystem::operator SI()const {
	double feet = mfeet + minch / 12;
	double meter = feet / MTRTOFEETRATIO;
	return meter;
}
SI::operator ImperialSystem() const{
	double meter = mmeter + mcentimeter / 100.0;
	double feet = meter * MTRTOFEETRATIO;
	return feet;
}


int main() {
	SI s{ 20,35 };
	cout << s << " =  " << static_cast<ImperialSystem>(s) << endl;
	ImperialSystem i{ 10,11 };
	cout << i << " =  " << static_cast<SI>(i) << endl;
	return 0;
}


