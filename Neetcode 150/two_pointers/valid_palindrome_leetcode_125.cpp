#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/valid-palindrome/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
class SolutionBrute {
   public:
    bool isPalindrome(string s) {
        string constructed = "";

        for (auto x : s) {
            if (isalnum(x)) {
                if (isupper(x)) {
                    constructed += tolower(x);
                } else {
                    constructed += x;
                }
            }
        }

        int l = 0;
        int r = constructed.size() - 1;

        while (l < r) {
            if (constructed[l] != constructed[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};

// Approach-1 (Optimal)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s = "0P";
    bool ans = sol.isPalindrome(s);
    cout << "ans --> " << boolalpha << ans << endl;
}
