#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        // Count frequency of characters in s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int windowSize = s1.length();

        // Initialize the first window of size equal to s1
        for (int i = 0; i < windowSize; i++) {
            freq2[s2[i] - 'a']++;
        }

        // Compare the first window
        if (equal(begin(freq1), end(freq1), begin(freq2))) return true;

        // Slide the window over s2
        for (int i = windowSize; i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;                    // Add the next character in the window
            freq2[s2[i - windowSize] - 'a']--;       // Remove the previous character from the window

            if (equal(begin(freq1), end(freq1), begin(freq2))) return true;
        }

        return false;
    }
};

int main() {
    Solution solution;
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    if (solution.checkInclusion(s1, s2)) {
        cout << "Yes, s1's permutation is a substring of s2." << endl;
    } else {
        cout << "No, s1's permutation is not a substring of s2." << endl;
    }
    return 0;
}
