#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/longest-palindrome/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(2*n) -> O(n)
// SC : O(64)  -> O(1)
class Solution {
   public:
    // Question Rephrased:
    // what is length of longest pallindrome that can be formed
    // It is not manditory to use all frequency of char in string
    // ccceee -> cecec -> (5) --> (we choose not use use 3rd 'e')
    int longestPalindrome(string s) {
        vector<int> freq(64, 0);

        for (auto& x : s) {
            freq[x - 'A']++;
        }

        int len = 0;
        bool hasOdd = false;

        for (auto& x : freq) {
            if (x % 2 == 0) {
                len += x;
            } else {
                len += x - 1;
                hasOdd = true;
            }
        }

        return len + hasOdd;
    }
};

int main() {
    Solution sol;
    string s = "abccccdd";
    int ans = sol.longestPalindrome(s);
    cout << "ans --> " << ans << endl;
}
