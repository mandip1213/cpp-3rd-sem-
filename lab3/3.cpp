#include<iostream>
#define endl '\n'
using std::cout;
class Carpark {
	private:
		int mid;
		int mcharge;
		float mtime;
	public:
		void setId(int id) {
			mid = id;
		}
		void setCharge(int charge) {
			mcharge = charge;
		}
		void setTime(float time) {
			mtime = time;
		}

		int getId() const{
			return mid;
		}
		int getCharge() const{
			return mcharge;
		}
		float getTime() const{
			return mtime;
		}
		float getTotalCharge()const {
			return mtime * mcharge;
		}
};
Carpark createCarParkObject(int id, int charge, float time) {
	Carpark carpark;
	carpark.setId(id);
	carpark.setCharge(charge);
	carpark.setTime(time);
	return carpark;

}
void printCarParkObject(Carpark carpark) {
	cout << "id: " << carpark.getId() << endl;
	cout << "time: " << carpark.getTime() << endl;
	cout << "charge/hour: " << carpark.getCharge() << endl;
	cout << "Total charge : " << carpark.getTotalCharge() << endl;
}
int main() {
	/*Create a class carpark that has:
	 *int data member for car id
	 * int data member fro charge/hour
	 * and float data membere for the parked time
	 * Make functions for setting and showing the data members.
	 * Member fucntions should be called from other functions.
	 */
	Carpark carpark=createCarParkObject(1,22,2.5);
	printCarParkObject(carpark);
	return 0;
}
