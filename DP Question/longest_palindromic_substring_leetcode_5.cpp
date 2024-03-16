#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/longest-palindromic-substring/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n^2) - Because the AMortized Time Complexity of solve() will become 1 due to memoization.
// SC : O(n^2)
class Solution {
   public:
    vector<vector<int>> dp;

    bool solve(string &s, int l, int r) {
        if (l >= r)
            return 1;

        if (dp[l][r] != -1) {
            return dp[l][r];
        }

        if (s[l] == s[r]) {
            return dp[l][r] = solve(s, l + 1, r - 1);
        }

        return dp[l][r] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        int maxlen = INT_MIN;
        int startingIndex = 0;
        dp.resize(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j)) {
                    if (j - i + 1 > maxlen) {
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};

int main() {
    string s = "babad";
    string ans = Solution().longestPalindrome(s);
    cout << "ans --> " << ans << endl;
}