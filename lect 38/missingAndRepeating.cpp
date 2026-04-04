#include <iostream>         // For input/output
#include <vector>          // For vector container
#include <unordered_set>   // For unordered_set container
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2, 0);            // Result vector [repeated, missing]
        unordered_set<int> s;             // Set to track seen numbers
        int n = grid.size();              // Grid size (n x n)

        // Use long long to prevent integer overflow
        long long expectedSum = (long long)n * n * (n * n + 1) / 2;  // Sum of 1 to n*n
        long long actualSum = 0;          // Actual sum of grid numbers

        // First pass: Find repeated number and calculate actual sum
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                actualSum += grid[i][j];
                // If number already exists in set, it's the repeated one
                if(!s.insert(grid[i][j]).second) {
                    ans[0] = grid[i][j];  // Store repeated number
                }
            }
        }

        // Calculate missing number
        ans[1] = expectedSum - actualSum + ans[0];

        return ans;  // Return [repeated, missing]
    }
};

// Main function to test the solution
int main() {
    // Example 1: 2x2 grid
    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    
    // Create Solution object
    Solution sol;
    
    // Get result
    vector<int> result1 = sol.findMissingAndRepeatedValues(grid1);
    
    // Print result
    cout << "Example 1 Output: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "Repeated: " << result1[0] << ", Missing: " << result1[1] << endl;

    // Example 2: 3x3 grid
    vector<vector<int>> grid2 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> result2 = sol.findMissingAndRepeatedValues(grid2);
    
    cout << "\nExample 2 Output: [" << result2[0] << ", " << result2[1] << "]" << endl;
    cout << "Repeated: " << result2[0] << ", Missing: " << result2[1] << endl;

    return 0;
}