#include<iostream>
#include<string>
using namespace std;

class Teacher{
    //properties  // attributes
private:
    double salary;
public:
    string name;
    string dept;
    string subject;
    

    //method / member function
    void changeDept(string newDept){
        dept = newDept;
    }
    //setter
    void setSalary(double s){
        salary = s;
    }
    //getter
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name="Aman";
    t1.subject="c++";
    t1.dept="computer science";
    t1.setSalary(250000);
    cout<<t1.name<<endl;
    cout<<t1.getSalary();
    // Teacher t2;
    // Teacher t3;
    // Teacher t4;

    return 0;
}