#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;
        if (x == 1) return 1.0;
        if (x == -1 && n % 2 == 0) return 1.0;
        if (x == -1 && n % 2 != 0) return -1.0;

        long long binForm = n;
        if (n < 0) {
            x = 1 / x;
            binForm = -binForm;
        }
        double ans = 1;
        while (binForm > 0) {
            if (binForm % 2 == 1) {
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    double x;
    int n;

    // User input
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;

    // Calling the function
    double result = sol.myPow(x, n);
    
    // Display result
    cout << x << " raised to the power " << n << " is: " << result << endl;

    return 0;
}
