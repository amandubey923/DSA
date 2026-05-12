/*
Constructor : A special member function of a class
that is automatically called when an object of that class is created.
It is used to initialize the object's data members and allocate resources
if necessary.
In C++, constructors:
1. Have the same name as the class
2. Do not have a return type
3. Can be overloaded
*/
/*
Constructors are usually public.
They can also be private or protected.
Memory for object is allocated when the object is created.
*/
/*
Non-Parameterized Constructor (Default Constructor)
It is a constructor that does not take any parameters.
It initializes data members with default values.
Example:
Teacher() {
    name = "Unknown";
    dept = "Unknown";
    subject = "Unknown";
    salary = 0;
}
*/
/*
Parameterized Constructor
It is a constructor that takes parameters.
It initializes data members with user-defined values.
Example:
Teacher(string name, string dept,
        string subject, double salary) {
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
}
*/
/*
this Pointer
It is a pointer that points to the current object.
It is used to access data members and member functions
of the current object.
Example:
this->name = name;
*/
/*
Copy Constructor
It is a constructor that creates a new object
as a copy of an existing object.
Example:
Teacher(const Teacher &t) {
    name = t.name;
    dept = t.dept;
    subject = t.subject;
    salary = t.salary;
}
*/


#include<iostream>
#include<string>
using namespace std;

class Teacher{
    private:
    double salary;

    public: 
    string name;
    string dept;
    string subject;

 // parameterized constructor
    Teacher(string n, string d, string s, double sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }
    // copy constructor
    Teacher(Teacher &t){
        this->name = t.name;
        this->dept = t.dept;
        this->subject = t.subject;
        this->salary = t.salary;
    }
    // this pointer constructor
    Teacher(string name, string dept, string subject, double salary){
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }
    
    void changeDept(string newDept){
        dept = newDept;
    }

    void setSalary(double s){
        salary = s;
    }
    double getSalary(){
        return salary;
    }
};

int main  (){
    Teacher t1("Aman", "IT", "C++", 50000);
    // t1.name="Aman";
    // t1.subject="C++";
    // t1.dept="IT";
    // t1.salary=50000;
    cout<<"Name: "<<t1.dept<<endl;
    cout<<"Salary: "<<t1.getSalary()<<endl;

    // Teacher t2(t1);  copy constructor
    return 0;
}
