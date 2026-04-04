// PYRAMID PATTERN------------------------------------

#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    for (int i = 0; i < n; i++)
    {
        // SPACES : n-i-1
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // NUM S1 : i+1
        for (int j = 1; j <= i + 1; j++)
        {
            cout << j;
        }
        // NUM S2
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}