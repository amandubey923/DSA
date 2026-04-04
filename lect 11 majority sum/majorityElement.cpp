#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int val : nums) {
            int freq = 0;
            for (int el : nums) {
                if (el == val) {
                    freq++;
                }
            }
            if (freq > n / 2) {
                return val;
            }
        }
        return -1;
    }
};

int main() {
    // Example input
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    Solution sol;
    int majority = sol.majorityElement(nums);

    if (majority != -1) {
        cout << "The majority element is: " << majority << endl;
    } else {
        cout << "There is no majority element." << endl;
    }

    return 0;
}
