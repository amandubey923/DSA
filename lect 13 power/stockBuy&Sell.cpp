#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> prices;
    int n, price;
    cout << "Enter number of days: ";
    cin >> n;
    cout << "Enter stock prices for " << n << " days:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> price;
        prices.push_back(price);
    }
    int result = sol.maxProfit(prices);
    cout << "Maximum profit you can achieve is: " << result << endl;
    return 0;
}
