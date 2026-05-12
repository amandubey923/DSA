
/*
Static Keyword in C++

The static keyword is used to share the same variable or function among all objects of a class.

Types of Static:
1. Static Variable
2. Static Member Function
3. Static Local Variable
4. Static Global Variable

1. Static Variable:
A variable declared with static keyword inside a class.

Properties:
1. Shared by all objects
2. Memory allocated only once
3. Value remains same for all objects
4. Accessed using class name

Syntax:
static dataType variableName;

Example:
static int count;

Important:
Static data member must be defined outside the class.

Example:
int Student::count = 0;

2. Static Member Function:
A function declared with static keyword inside a class.

Properties:
1. Can access only static members
2. Called using class name
3. Does not use this pointer

Syntax:
static void show();

Example:
Student::show();

3. Static Local Variable:
A local variable declared as static inside a function.

Properties:
1. Created only once
2. Retains value between function calls
3. Lifetime is entire program

Example:
static int x = 0;

4. Static Global Variable:
A global variable declared with static keyword.

Properties:
1. Scope limited to current file
2. Cannot be accessed from other files

Advantages of Static:
1. Memory Efficient
2. Data Sharing
3. Retains Value
4. Improves Performance

Important Points:
1. Static members belong to class, not object.
2. Only one copy of static variable exists.
3. Static functions can access only static data members.
4. Static member functions can be called without object.
5. Static variables are initialized to 0 by default.

Static Keyword

Static variables in function - Variable declared as static in a function are created  & 
initialised once for the lifeline of the program.

Static variables in class - Static variables in class are shared by all objects of the class.


*/
#include<iostream>
using namespace std;

// Static Global Variable
static int globalVar = 100;

class Student{
public:
    string name;
    // Static Data Member
    static int count;
    Student(string name){
        this->name = name;
        count++;
    }
    // Static Member Function
    static void showCount(){
        cout<<"Total Students: "<<count<<endl;
    }
};
// Static Variable Definition
int Student::count = 0;
// Function for Static Local Variable
void demo(){
    // Static Local Variable
    static int x = 0; // iniT statement 1 run only once
    x++;
    cout<<"x = "<<x<<endl;
}
int main(){
    // Static Global Variable
    cout<<"Global Variable: "<<globalVar<<endl;
    // Objects
    Student s1("Aman");
    Student s2("Rahul");
    // Access Static Variable
    Student::showCount();
    // Static Local Variable
    demo();
    demo();
    demo();

    return 0;
}