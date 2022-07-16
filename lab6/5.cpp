/*from: https://github.com/bipul018/ClassCppPractice/blob/39c4fb98d88dc434a7865bd2bf6381d862c6fbe1/lab6/lab6.cpp#L1-L73*/
/* Yo ni alxi laagyo*/

#include <iostream>
using namespace std;


class Complex
{
public:
    void getIn() {
        cout << "Enter real and imaginary :";
        cin >> m_real >> m_imag;
    }
    void display()
    {
        cout << "The complex number is: " << m_real << " + i" << m_imag << endl;
    }


    float m_real;
    float m_imag;
};


class Inherit : public Complex
{
public:
    friend class CFriend;
    void add(Complex a)
    {
        cout << "The sum from base and inherited : " << a.m_real + m_real << " + i" << a.m_imag + m_imag << endl;
    }
    
};
class CFriend
{
public:
    void diff(Complex a)
    {
        cout << "The difference of base and friend: " << a.m_real - m_real << " + i" << a.m_imag - m_imag << endl;
    }
    void getIn() {
        cout << "Enter real and imaginary :";
        cin >> m_real >> m_imag;
    }
    void display()
    {
        cout << "The complex number is: " << m_real << " + i" << m_imag << endl;
    }
private:
    float m_real, m_imag;


};
/*
Write a base class that asks the user to enter a complex number and make 
a derived class that adds the complex number of its own with the base. 
Finally, make a third class that is a friend of derived and calculate 
the difference of the base complex number and its own complex number.
*/

int main()
{
    Complex a;
    cout << "For base class: " << endl;
    a.getIn();
    a.display();
    Inherit b;
    cout << "For inherited class: " << endl;
    b.getIn();
    b.display();
    b.add(a);
    CFriend c;
    cout << "For friend class: " << endl;
    c.getIn();
    c.display();
    c.diff(a);
    return 0;
}


