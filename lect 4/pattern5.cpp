/*
#include<iostream>
using namespace std;
int main(){
    int n = 4;
    for(int i = 0; i<n; i ++){
        for (int j =1; j<i+1; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/

// REVERSE TRIANGLE---------------------------------
/*
#include<iostream>
using namespace std;
int main(){
    int n = 4;
    for(int i = 0; i<n; i ++){
        for (int j =i+1; j>0; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}

*/

// Inverted Triangle Pattern----------------------

/*
#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)  //OUTER LOOP
    {
        for (int j = 0; j < i; j++)  INNER LOOP 1
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; j++) INNER LOOP 2
        {
            cout << (i + 1);
        }
        cout << endl;
    }
}
*/

//FOR CHARACTER

#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout <<" ";
    
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << char('A'+ i);
        }
        cout << endl;
    }
}
