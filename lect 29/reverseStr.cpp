#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str = "Aman Dubey";

    reverse(str.begin(), str.end());// iterators
    cout<<str<<endl;

    return 0;
}