
#include<iostream>
#include<string>
using namespace std;

class Teacher{
    private:
    double salary;

    
// {
//     public: can be accessed from anywhere
//     private: can only be accessed within the class
//     protected: can be accessed within the class and by derived classes 
// }

    public: //access specifier (public, private, protected)

    //properties or attributes
    string name;
    string dept;
    string subject;
    
    //methods or member function (function of class)
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


int main(){
    Teacher t1;
    t1.name="Aman";
    t1.subject="C++";
    t1.dept="IT";
    // t1.salary=50000;

    t1.setSalary(50000);
    cout<<"Name: "<<t1.name<<endl;
    cout<<"Salary: "<<t1.getSalary()<<endl;

    return 0;
}
