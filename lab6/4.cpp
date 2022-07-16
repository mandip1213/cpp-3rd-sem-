/*from: https://github.com/bipul018/ClassCppPractice/blob/39c4fb98d88dc434a7865bd2bf6381d862c6fbe1/lab6/lab6.cpp#L89-L166*/
/*alixi laagyo*/
#include <iostream>
#include <string>
using namespace std;
class person {
private:
    string Name;
    int Age;
public:
    void askName() {
        cout << "What is the name? " << endl;
        cin >> Name;
    }
    void askAge() {
        cout << "What is the age? " << endl;
        cin >> Age;
    }
    void pAdd() {
        cout << this << endl;
    }
};
class student : public person {
private:
    int rollNo;
    int level;
public:
    void printRollNo() {
        cout << "Roll Number: " << rollNo << endl;
    }
    void printLevel() {
        cout << "Level: " << level << endl;
    }
    void pAdd() {
        cout << this << endl;
    }
};
class employee : public person {
private:
    int salary;
    int idNo;
public:
    void printSalary() {
        cout << "Salary: " << salary << endl;
    }
    void printIdNo() {
        cout << "Id Number: " << idNo << endl;
    }
    void pAdd() {
        cout << this << endl;
    }
};
int main() {
    person p1, p2;
    student s1, s2;
    employee e1, e2;
    cout << "Addresses of pointers\n";

    cout << "P1 :"; 
    p1.pAdd(); 
    cout << " P2 :"; 
    p2.pAdd();
    cout << "\nS1 :" ; 
    s1.pAdd(); 
    cout<< " S2 :" ; 
    s2.pAdd();
    cout << "\nE1 :" ; 
    e1.pAdd(); 
    cout << " E2 :"; 
    e2.pAdd();

    cout << "Sizes of objects: \n";
    cout << "Person: " << sizeof(p1) << endl;

    cout << "Student: " << sizeof(s1) << endl;

    cout << "mployee: " << sizeof(e1) << endl;

    return 0;
}

