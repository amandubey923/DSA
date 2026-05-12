/*
Friend Function in C++

A friend function is a function that is not a member of a class
but can access private and protected members of the class.

It is declared using friend keyword inside the class.

Properties:
1. Not a member of class
2. Can access private and protected members
3. Called like normal function
4. Uses objects to access members

Syntax:
friend returnType functionName(className &obj);

Advantages:
1. Increases flexibility
2. Used for operator overloading
3. Allows external functions to access private data
*/

/*
Friend Class in C++

A friend class is a class that can access private
and protected members of another class.

It is declared using friend keyword.

Properties:
1. Friend class can access private members
2. Friendship is not inherited
3. Friendship is not mutual automatically

Syntax:
friend class ClassName;

Advantages:
1. Allows collaboration between classes
2. Provides controlled access
3. Useful in complex programs
*/

#include<iostream>
using namespace std;
// Friend Function
class Student{
private:
    int marks = 95;
    friend void showMarks(Student s);
};
void showMarks(Student s){
    cout<<"Marks: "<<s.marks<<endl;
}
// Friend Class
class Teacher;
class College{
private:
    string secret = "CGC";

    friend class Teacher;
};
class Teacher{
public:
    void showSecret(College c){
        cout<<"Secret: "<<c.secret<<endl;
    }
};
int main(){
    // Friend Function
    Student s;
    showMarks(s);
    // Friend Class
    College c;
    Teacher t;
    t.showSecret(c);
    return 0;
}