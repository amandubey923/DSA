/*
Shallow Copy
In shallow copy, only addresses are copied.
Both objects point to the same memory location.
Changes made through one object may affect the other object.
Example:
class Test {
public:
    int *p;
    Test(int x) {
        p = new int(x);
    }
    Test(const Test &t) {
        p = t.p; // shallow copy
    }
};
*/
/*
Deep Copy
In deep copy, separate memory is allocated
for the new object.
Both objects have different memory locations.
Example:
class Test {
public:
    int *p;
    Test(int x) {
        p = new int(x);
    }
    Test(const Test &t) {
        p = new int(*t.p); // deep copy
    }
};
*/

#include<iostream>
using namespace std;
// ---------- SHALLOW COPY ----------
class Shallow {
public:
    int *p;
    Shallow(int x) {
        p = new int(x);
    }
    // Shallow Copy Constructor
    Shallow(const Shallow &t) {

        p = t.p; // same address copied
    }
    void show() {
        cout << *p << endl;
    }
};
// ---------- DEEP COPY ----------
class Deep {
public:
    int *p;
    Deep(int x) {
        p = new int(x);
    }
    // Deep Copy Constructor
    Deep(const Deep &t) {
        p = new int(*t.p); // new memory allocated
    }
    void show() {
        cout << *p << endl;
    }
};
int main() {

    // ---------- SHALLOW COPY ----------
    cout << "Shallow Copy:" << endl;
    Shallow s1(10);
    Shallow s2 = s1;
    *s2.p = 50;
    cout << "s1 value: ";
    s1.show();
    cout << "s2 value: ";
    s2.show();
    // ---------- DEEP COPY ----------
    cout << endl;
    cout << "Deep Copy:" << endl;
    Deep d1(10);
    Deep d2 = d1;
    *d2.p = 50;
    cout << "d1 value: ";
    d1.show();
    cout << "d2 value: ";
    d2.show();
    return 0;
}