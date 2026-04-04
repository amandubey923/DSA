#include <iostream>
#include <vector>
#include <algorithm> // For max_element
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int students = 1, pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
            if (students > m) return false; // Early return to avoid unnecessary checks
        }
    }
    return true;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n) return -1;

    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxBook = max(maxBook, arr[i]);
    }

    int ans = -1;
    int st = maxBook, end = sum;  // Range of possible answers
    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) { // Check feasibility
            ans = mid;
            end = mid - 1; // Try for a better minimum
        } else {
            st = mid + 1;  // Increase the allowed max pages
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {15, 17, 20};
    int n = arr.size(), m = 2; // Fix the value of 'n' to match the array size
    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}
