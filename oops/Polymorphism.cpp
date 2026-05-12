/*
Polymorphism is the ability of objects to take on different forms or behave in different ways depending upon the context in which they are used.
-compiler time polymorphism (function overloading, operator overloading)
-run time polymorphism (virtual functions, abstract classes)



Polymorphism in C++

Polymorphism is an OOP feature in which one entity can take many forms.

Poly means many.
Morphism means forms.

Types of Polymorphism:
1. Compile Time Polymorphism
2. Run Time Polymorphism

1. Compile Time Polymorphism:
Polymorphism achieved during compilation.

Types:
a) Function Overloading or constructor overloading
b) Operator Overloading

Function Overloading:
Multiple functions with same name but different parameters.

Example:
add(int a, int b)
add(int a, int b, int c)

Operator Overloading:
Operators can be redefined for user-defined data types.

Example:
Operator + can be overloaded for objects.

2. Run Time Polymorphism:
Polymorphism achieved during program execution.

Achieved using:
Function Overriding and Virtual Functions.

Function Overriding:
Derived class redefines the function of base class.

The function in base and derived class must have:
1. Same name
2. Same parameters

Virtual Function:
A function declared with virtual keyword in base class.

It allows dynamic binding and supports runtime polymorphism.

Example:
virtual void display();

Important Terms:

Early Binding:
Function call resolved during compile time.

Late Binding:
Function call resolved during runtime.

Advantages of Polymorphism:
1. Code Reusability
2. Flexibility
3. Easy Maintenance
4. Improves Readability
5. Supports Dynamic Behavior

Important Points:
1. Function Overloading is compile time polymorphism.
2. Function Overriding is runtime polymorphism.
3. Virtual functions are used for runtime polymorphism.
4. Constructors cannot be virtual.
5. Polymorphism is an important feature of OOP.
*/

#include<iostream>
using namespace std;
// Compile Time Polymorphism
class Math{
public:
    // Function Overloading
    int add(int a,int b){
        return a+b;
    }
    int add(int a,int b,int c){
        return a+b+c;
    }
    // Operator Overloading
    void operator + (Math &obj){
        cout<<"Operator Overloading"<<endl;
    }
};
// Runtime Polymorphism
class Animal{
public:
    // Virtual Function
    virtual void sound(){
        cout<<"Animal Sound"<<endl;
    }
};
class Dog : public Animal{
public:
    // Function Overriding
    void sound() override{
        cout<<"Dog Barks"<<endl;
    }
};
int main(){
    // Function Overloading
    Math m1,m2;
    cout<<m1.add(2,3)<<endl;
    cout<<m1.add(2,3,4)<<endl;
    // Operator Overloading
    m1 + m2;
    // Runtime Polymorphism
    Animal *a;
    Dog d;
    a = &d;
    a->sound();
    return 0;
}