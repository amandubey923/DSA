#include <iostream>
#include <vector>
using namespace std;

int reccurBinarySearch(const vector<int>& arr, int tar, int st, int end) {
    if (st <= end) {
        int mid = st + (end - st) / 2;

        if (tar > arr[mid]) {
            return reccurBinarySearch(arr, tar, mid + 1, end);
        }
        else if (tar < arr[mid]) {
            return reccurBinarySearch(arr, tar, st, mid - 1);
        }
        else {
            return mid; // Found the target
        }
    }
    return -1; // Not found
}

int main() {
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // Odd-sized array
    int tar1 = 12;

    cout << reccurBinarySearch(arr1, tar1, 0, arr1.size() - 1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // Even-sized array
    int tar2 = 0;

    cout << reccurBinarySearch(arr2, tar2, 0, arr2.size() - 1) << endl;

    return 0;
}
