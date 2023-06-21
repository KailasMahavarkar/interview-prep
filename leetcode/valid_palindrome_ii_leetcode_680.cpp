#include <bits/stdc++.h>
using namespace std;

// <---- READ QUESTION ---->
// Given a string s
// return true if the s can be palindrome after deleting at most one character from it.

class Solution {
   public:
    bool isValidPallindrome(string s, int i, int j) {
        int size = i + (j - i) / 2;
        while (i <= size) {
            if (i != j) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] != s[j]) {
                return isValidPallindrome(s, i + 1, j) || isValidPallindrome(s, i, j - 1);
            } else {
                i++;
                j--;
            }
        }

        return true;
    }
};

int main() {
    // string s = "kailas";
    Solution sol;
    bool ans = sol.validPalindrome("kaisak");
    cout << boolalpha << "ans: " << ans << endl;
}