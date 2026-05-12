/*
Constructor = a special member function of a class
that is automatically called when an object of that class is created. 
It is used to initialize the object's data members and allocate resources
if necessary. In C++, constructors have the same name as the class and 
do not have a return type. They can be overloaded, meaning that a class
can have multiple constructors with different parameters. 
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

    //constructor : always public and has the same name as the class and 
    // memory is allocated when the object is created

/*
Non-parameterized constructor : It is a constructor that does not take any parameters. It is also known as default constructor. It is used to initialize the data members with default values.
example:
Teacher(){
    name = "Unknown";
    dept = "Unknown";
    subject = "Unknown";
    salary = 0;
}
*/

// parameterized constructor : It is a constructor that takes parameters. 
// It is used to initialize the data members with user defined values.
    Teacher(string n, string d, string s, double sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
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
    return 0;
}
