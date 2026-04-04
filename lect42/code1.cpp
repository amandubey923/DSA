#include<iostream>
using namespace std;

void printNums(int n){ // recursive fn
    if(n == 1){
        cout<<"1\n";
        return ;
    }

    cout<<n<<" "; // n, n-1, n-2, ..... to 1
    printNums(n-1);
}

int main (){
    printNums(10);


    return 0; 
}