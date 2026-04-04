#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n = A.size();
        if (n == 1) return A[0]; // Case 1
        
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            if (mid == 0 && A[0] != A[1]) return A[mid]; // Corner case 2
            if (mid == n - 1 && A[n - 1] != A[n - 2]) return A[mid]; // Case 3
            if (A[mid - 1] != A[mid] && A[mid] != A[mid + 1]) return A[mid]; // Mid element
            
            if (mid % 2 == 0) { // Even index
                if (A[mid - 1] == A[mid]) { // Left side
                    end = mid - 1;
                } else { // Right side
                    st = mid + 1;
                }
            } else { // Odd index
                if (A[mid - 1] == A[mid]) { // Left side
                    st = mid + 1;
                } else { // Right side
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> A = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    cout << "Single non-duplicate element: " << sol.singleNonDuplicate(A) << endl;
    return 0;
}
