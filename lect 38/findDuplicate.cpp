#include <iostream>         // For input/output
#include <vector>          // For vector container
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0], fast = arr[0];  // Start both pointers at first element

        // Phase 1: Find intersection point of slow and fast pointers
        // Slow moves 1 step, Fast moves 2 steps
        do {
            slow = arr[slow];          // Move one step
            fast = arr[arr[fast]];     // Move two steps
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle (duplicate number)
        slow = arr[0];                 // Reset slow to start
        while (slow != fast) {
            slow = arr[slow];          // Move one step
            fast = arr[fast];          // Move one step
        }
        return slow;                   // Return the duplicate number
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    // Test Case 1: Array with duplicate 3
    vector<int> arr1 = {1, 3, 4, 2, 3};
    int result1 = sol.findDuplicate(arr1);
    cout << "Test Case 1 - Array: [1, 3, 4, 2, 3]" << endl;
    cout << "Duplicate number: " << result1 << endl;

    // Test Case 2: Array with duplicate 2
    vector<int> arr2 = {3, 1, 2, 4, 2};
    int result2 = sol.findDuplicate(arr2);
    cout << "\nTest Case 2 - Array: [3, 1, 2, 4, 2]" << endl;
    cout << "Duplicate number: " << result2 << endl;

    return 0;
}