#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    /*
    char str2[]={'a','b','c','\0'};
    cout<< str2 << endl; //constant pointers
    char str[]= "hello";
    cout<< strlen(str)<<endl;
*/
/*
    char str[9];
    cout << " enter char array: ";

    //cin >> str;
    //cin.getline(str,100, '&');
    cin.getline(str,9);
    //cout << "output: " << str << endl;
    for(char ch:str){
        cout<<ch<<" ";
    }
    cout<<endl;
    */

   char str[] ="Aman Dubey";
   int len = 0;

   for(int i = 0; i<str[i] != '\0'; i++){
    len++;
   }
   cout<<"length of string: "<<len <<endl;
    return 0;
}