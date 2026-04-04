#include<iostream>
#include<string>
using namespace std;

class Teacher{
    //properties  // attributes
private:
    double salary;
public:
    // non paramaterized 
    // Teacher(){
    //     cout<<"hi I Am constructor\n";
    // }
    //paramaterized
    Teacher(string n,  string d, string s , double sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }

    string name;
    string dept;
    string subject;
    

    //method / member function
    void changeDept(string newDept){
        dept = newDept;
    }
    void getInfo(){
        cout<<"name: "<<name<<endl;
        cout<<"subject "<<subject<<endl;
    }
};

int main(){
    Teacher t1("aman" , "computer science", 'c++', 250000); //constructor call
    
    t1.getInfo();
    return 0;
}