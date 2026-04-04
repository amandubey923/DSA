#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int st, int end, int mid) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1); // Count inversions
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for (size_t idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx]; // Copy back to original array
    }
    return invCount;
}

int mergeSort(vector<int>& arr, int st, int end) {
    if (st >= end) return 0; // Base case: single element has 0 inversions

    int mid = st + (end - st) / 2;
    int leftInv = mergeSort(arr, st, mid);
    int rightInv = mergeSort(arr, mid + 1, end);
    int mergeInv = merge(arr, st, end, mid);

    return leftInv + rightInv + mergeInv;
}

int main() {
    //vector<int> arr = {6, 3, 5, 2, 7};
    vector<int>arr = {1,3,5,10,2,6,8,9};
    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "Inversion count: " << ans << endl;

    return 0;
}