// Encapsulation : It is the process of wrapping data and 
// functions into a single unit called class. 
// It is also known as data hiding. 
// It is used to protect the data from unauthorized access and modification.

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

class Account{
    private: // data hiding
    double balance;
    string password;

    public:
    string accountId;
    string userName;
    
};

int main(){
    return 0;
}