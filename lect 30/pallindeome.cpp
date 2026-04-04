#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Function to check if a character is alphanumeric
    bool isAlphaNum(char ch) {
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }
        return false;
    }

    // Function to check if a string is a palindrome
    bool isPalindrome(string s) {
        int st = 0, end = s.length() - 1;

        while (st < end) {
            if (!isAlphaNum(s[st])) {
                st++; 
                continue;
            }
            if (!isAlphaNum(s[end])) {
                end--; 
                continue;
            }
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }
            st++; 
            end--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    if (solution.isPalindrome(s)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
