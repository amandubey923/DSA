#include<iostream>
using namespace std;

void printDigits(int n){
   // int count = 0;
   int sum =0;
    while( n!= 0){
        int digit = n%10;
         sum += digit;
        //count++;
        //cout<< digit<<endl;
        n = n/10;
    }
    //cout<<count<<endl;
    cout<<sum<<endl; 
}

int main(){
    int n = 3658;
    printDigits(n);

    return 0;
}