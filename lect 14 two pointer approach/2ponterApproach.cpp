#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0; // Variable to store the maximum water
        int lp = 0, rp = height.size() - 1; // Left and right pointers

        while (lp < rp) {
            int w = rp - lp; // Width between the two lines
            int ht = min(height[lp], height[rp]); // Height of the container
            int currWater = w * ht; // Current water contained
            maxWater = max(maxWater, currWater); // Update max water if current is larger
            height[lp] < height[rp] ? lp++ : rp--; // Move the pointer of the shorter line
        }

        return maxWater; // Return the maximum water found
    }
};

int main() {
    Solution solution; // Create an instance of Solution
    vector<int> height = {1,8,6,2,5,4,8,3,7}; // Example input
    int result = solution.maxArea(height); // Call maxArea method
    cout << "The maximum area of water that can be contained is: " << result << endl; // Output result
    return 0; // Return success
}
