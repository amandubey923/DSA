/*
Single Inheritance:
One child class inherits one parent class.

Example:
class Dog : public Animal
*/

/*
Multiple Inheritance:
One child class inherits multiple parent classes.

Example:
class Professor : public Teacher, public Researcher
*/

/*
Multilevel Inheritance:
One class inherits another derived class.

Example:
class Puppy : public Dog
*/

/*
Hierarchical Inheritance:
Multiple child classes inherit one parent class.

Example:
class Cat : public Animal
class Cow : public Animal
*/

/*
Hybrid Inheritance:
Combination of different types of inheritance.

Example:
class Bat : public Animal, public Bird
*/
#include<iostream>
using namespace std;

// Single Inheritance
class Animal{
public:
    void eat(){
        cout<<"Eating"<<endl;
    }
};

class Dog : public Animal{
};

// Multiple Inheritance
class Teacher{
public:
    void teach(){
        cout<<"Teaching"<<endl;
    }
};

class Researcher{
public:
    void research(){
        cout<<"Researching"<<endl;
    }
};

class Professor : public Teacher, public Researcher{
};

// Multilevel Inheritance
class Puppy : public Dog{
};

// Hierarchical Inheritance
class Cat : public Animal{
};

class Cow : public Animal{
};

// Hybrid Inheritance
class Bird{
public:
    void fly(){
        cout<<"Flying"<<endl;
    }
};

class Bat : public Animal, public Bird{
};

int main(){

    // Single Inheritance
    Dog d;
    d.eat();

    // Multiple Inheritance
    Professor p;
    p.teach();
    p.research();

    // Multilevel Inheritance
    Puppy pu;
    pu.eat();

    // Hierarchical Inheritance
    Cat c;
    c.eat();

    Cow cw;
    cw.eat();

    // Hybrid Inheritance
    Bat b;
    b.eat();
    b.fly();

    return 0;
}