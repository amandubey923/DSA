#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int r = 0, c = n - 1;

        // Start searching from the top-right corner
        while (r < m && c >= 0) {
            if (target == mat[r][c]) {
                return true;  // Target found
            } 
            else if (target < mat[r][c]) {
                c--;  // Move left in the row
            } 
            else {
                r++;  // Move down to the next row
            }
        }
        return false;  // Target not found
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;

    if (obj.searchMatrix(mat, target)) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}
