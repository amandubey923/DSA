/*
Inheritance in C++
Inheritance is an OOP feature in which one class acquires the properties and methods of another class.
When properties and member function of base class are passed on to the derived class.

Parent/Base Class:
The class whose properties are inherited.
Child/Derived Class:
The class that inherits the properties.

Advantages of Inheritance:
1. Code Reusability
2. Reduces Redundant Code
3. Better Code Organization
4. Improves Maintainability

Syntax:
class Child : accessSpecifier Parent

Types of Inheritance:
1. Single Inheritance
2. Multiple Inheritance
3. Multilevel Inheritance
4. Hierarchical Inheritance
5. Hybrid Inheritance

1. Single Inheritance:
One child class inherits one parent class.

2. Multiple Inheritance:
One child class inherits multiple parent classes.

3. Multilevel Inheritance:
A derived class becomes the base class for another class.

4. Hierarchical Inheritance:
Multiple child classes inherit from one parent class.

5. Hybrid Inheritance:
Combination of different types of inheritance.

Modes of Inheritance:
1. Public Inheritance
2. Protected Inheritance
3. Private Inheritance

Public Inheritance:
Public members remain public.
Protected members remain protected.

Protected Inheritance:
Public and protected members become protected.

Private Inheritance:
Public and protected members become private.

Important Points:
1. Private members cannot be accessed directly in derived class.
2. Protected members can be accessed in derived class.
3. Constructors are called from parent to child.
4. Destructors are called from child to parent.
5. Inheritance supports code reusability.
*/


/*
1. Single Inheritance
One child class inherits one parent class.

class Animal {
};

class Dog : public Animal {
};
*/

/*
2. Multiple Inheritance
One child class inherits multiple parent classes.

class Teacher {
};

class Researcher {
};

class Professor : public Teacher, public Researcher {
};
*/

/*
3. Multilevel Inheritance
A derived class becomes base class for another class.

class Animal {
};

class Dog : public Animal {
};

class Puppy : public Dog {
};
*/

/*
4. Hierarchical Inheritance
Multiple child classes inherit one parent class.

class Shape {
};

class Circle : public Shape {
};

class Rectangle : public Shape {
};
*/

/*
5. Hybrid Inheritance
Combination of multiple inheritance types.

class Animal {
};

class Mammal : public Animal {
};

class Bird {
};

class Bat : public Mammal, public Bird {
};
*/

#include<iostream>
#include<string>
using namespace std;

class Person{
    public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    Person(){
        cout<<"Parent Constructor called"<<endl;
    }
};
class Student : public Person{ // single inheritance
    public:
    // name , age , RollNo
    Student(string name,int age, int rollno): Person (name,  age){
        this->rollNo = rollno;
        cout<<"Child Constructor called"<<endl;
    }
    int rollNo;
    void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Roll No: "<<rollNo<<endl;
    }
};

int main(){
    Student s1("Aman", 20, 101);
    s1.name = "Aman";
    s1.age = 20;
    s1.rollNo = 101;
    s1.getInfo();
    return 0;
}

