#include <iostream>
#include <vector>
#include <algorithm>  // For the sort function
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        // Sort the vector
        sort(nums.begin(), nums.end());
        
        // Frequency count
        int freq = 1, ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                freq++;
            } else {
                freq = 1;
                ans = nums[i];
            }
            if (freq > n / 2) {
                return ans;
            }
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;
    int majority = sol.majorityElement(nums);

    cout << "The majority element is: " << majority << endl;

    return 0;
}
