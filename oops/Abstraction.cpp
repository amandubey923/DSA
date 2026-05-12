/*
Abstraction : Hiding all unnecessary details from the user and showing only essential features of the object is called abstraction. 
It is one of the fundamental OOP concepts. 
It is used to hide the internal implementation of the function and only show the functionality to the user. 
Abstraction can be achieved with either abstract classes or interfaces in C++.

/*
Abstract Class in C++

An abstract class is a class that contains at least one pure virtual function.

A pure virtual function is declared by assigning 0 to a virtual function.

Syntax:
virtual returnType functionName() = 0;

Abstract classes are used to provide a common interface for derived classes.

Important Points:
1. Abstract class cannot be instantiated.
2. Objects of abstract class cannot be created.
3. Abstract class can contain normal functions and variables.
4. Derived class must implement all pure virtual functions.
5. Pure virtual functions support runtime polymorphism.
6. Abstract classes are mainly used for abstraction.

Purpose of Abstract Class:
1. Hide implementation details
2. Provide common structure
3. Achieve abstraction
4. Improve code reusability

Pure Virtual Function:
A virtual function initialized with = 0.

Example:
virtual void display() = 0;

Advantages of Abstract Class:
1. Data Abstraction
2. Better Security
3. Code Reusability
4. Flexibility
5. Maintainability

Difference Between Abstract Class and Normal Class:

Abstract Class:
1. Contains pure virtual function
2. Object cannot be created

using Abstract Class:
Abstract classes are used to provide a base class from which other classes can be derived.
They cannot be instaminated and are meant to be inherited .
Abstract classes are typically used to define an interface for derived classes.

Normal Class:
1. Does not contain pure virtual function
2. Object can be created
*/
#include<iostream>
using namespace std;

// Abstract Class
class Animal{
public:
    // Pure Virtual Function
    virtual void sound() = 0;
    // Normal Function
    void eat(){
        cout<<"Animal is eating"<<endl;
    }
};
// Derived Class
class Dog : public Animal{
public:
    // Function Overriding
    void sound() override{
        cout<<"Dog Barks"<<endl;
    }
};
// Derived Class
class Cat : public Animal{
public:
    // Function Overriding
    void sound() override{
        cout<<"Cat Meows"<<endl;
    }
};
int main(){
    // Object of Derived Class
    Dog d;
    Cat c;
    // Calling Normal Function
    d.eat();
    // Runtime Polymorphism
    Animal *a;
    a = &d;
    a->sound();
    a = &c;
    a->sound();
    return 0;
}
