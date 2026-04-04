 
#include<iostream>
using namespace std;

int main (){
    int n = 4;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            cout<<"*";
        }
    cout<< endl;
    }


    return 0;
}



//FOR CHARACTER A B C D

#include<iostream>
using namespace std;
int main(){
    int n = 4;

    for(int i = 0; i<n; i++){ // outer
        char ch ='A';
        for (int j=0; j<n; j++){ // inner starr => line start
        cout << ch;
        ch = ch + 1;

        }
        cout<< endl;
    }


    return 0;
}
