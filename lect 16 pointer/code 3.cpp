//pass by reference
#include<iostream>
#include<vector>
using namespace std;

/*void changeA(int a){  //pass by value
    a= 20;
}
*/
void changeA(int*ptr){
    *ptr = 20 ;
}

int main(){
    int a = 10;
    changeA(&a);
    cout <<"inside main fn: "<<a<< endl;
    return 0; 
}