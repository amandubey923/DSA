/*
~ClassName()
Automatically called when object is destroyed
Used to free memory/resources
No return type
No parameters
Only one destructor in a class
*/

#include<iostream>
using namespace std;
class Student {
public:
    string name;
    // Constructor
    Student(string name) {
        this->name = name;
        cout << "Constructor called for "
             << name << endl;
    }
    // Destructor
    ~Student() {
        cout << "Destructor called for "
             << name << endl;
             delete this; // free memory or memory leak
    }
};
int main() {
    Student s1("Aman");
    cout << "Inside main function" << endl;
    return 0;
}