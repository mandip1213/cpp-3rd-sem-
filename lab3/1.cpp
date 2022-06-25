#include<iostream>
#define endl '\n'
using std::cout;

class Fahrenheit{
	private:
		float mvalue;
	public:
		Fahrenheit(float val):mvalue{val}{}
		float toCelsius() const {
			return ((mvalue - 32) * 5) / 9;
		}
		float getTempr() const{ 
			return mvalue; 
		}
};
class Celsius {
	private:
		float mvalue;
	public:
		Celsius(float val):mvalue{val}{}
		float toFahrenheit() const{
			return (9 * mvalue) / 5 + 32;
		}
		float getTempr()const { 
			return mvalue; 
		}
};

int main() {
	/*Wap that converts the temperature in Celsius scale to Fahrenheit scale and vice-varsa  using the basic concept of class and object. Make separte class for Celsius and 
	 *Fahrenheit scale which will have the private members that hold the temperature value and make conversino functions in each class for conversion from one to0 another.
	 */
	Fahrenheit fahrenheit{98.6};
	Celsius celsius{100};

	cout << fahrenheit.getTempr() << " fahrenheit = " << fahrenheit.toCelsius() << " celsius" << endl;
	cout << celsius.getTempr() << " celsius = " << celsius.toFahrenheit() << " fahrenheit" << endl;

	return 0;
}
