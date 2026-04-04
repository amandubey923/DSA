#include <iostream>
#include <vector>
#include <algorithm> // for min() and max() functions
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; // Variable to store the maximum water area

        // Iterate over all pairs of lines (i, j)
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                // Calculate the width between the two lines
                int w = j - i;
                // Find the minimum height between the two lines
                int ht = min(height[i], height[j]);
                // Calculate the current water area
                int currWater = w * ht;
                // Update maxWater if the current water area is greater
                maxWater = max(maxWater, currWater);
            }
        }
        return maxWater;
    }
};

int main() {
    // Example test case
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    // Create a Solution object
    Solution sol;
    // Call the maxArea function and print the result
    int result = sol.maxArea(height);
    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}
