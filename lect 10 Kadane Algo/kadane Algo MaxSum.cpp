#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;

        for (int val : nums) {
            currSum += val;
            maxSum = max(currSum, maxSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Find maximum subarray sum
    int max_sum = solution.maxSubArray(nums);

    cout << "Maximum Subarray Sum is " << max_sum << endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN

using namespace std;

int maxSubArraySum(vector<int>& nums) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < nums.size(); i++) {
        max_ending_here += nums[i];
        
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int max_sum = maxSubArraySum(nums);
    
    cout << "Maximum Subarray Sum is " << max_sum << endl;
    
    return 0;
}
*/