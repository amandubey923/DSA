#include <iostream>
using namespace std;

int linearSearch(int arr[], int sz, int target)
{
    for (int i = 0; i<sz; i++)
    { // found
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1; // not found
}
int main()
{
    int arr[] = {4, 2, 7, 9, 6, 5, 1};
    int sz = 7;
    int target = 9;

    cout << linearSearch(arr, sz, target)<<endl;

    return 0;
}