/*
#include<iostream>
using namespace std;
int main(){
    int n=6;
    for(int i=0; i<n ; i++){
         for (int j=0; j<i+1; j++){
            cout<<"* ";
         }
        cout<<endl;
    }

    return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main(){
    int n= 5;
    for (int i = 0; i<n; i++){
        for ( int j= 0; j<i+1; j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

*/
// HOME WORK //

#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << char('A' + i) << " ";
        }
        cout << endl;
    }
    return 0;
}