#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Is Subsequence
// problem link: https://leetcode.com/problems/is-subsequence/description/

void printDP(string msg, vector<vector<int>> &dp) {
    cout << msg << " " << endl;
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Method 1: recursion + memoization
class SolutionMemo {
   public:
    vector<vector<int>> dp;
    int lcs(string text1, string text2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (text1[n - 1] == text2[m - 1]) {
            dp[n][m] = 1 + lcs(text1, text2, n - 1, m - 1);
        } else {
            dp[n][m] = max(lcs(text1, text2, n - 1, m), lcs(text1, text2, n, m - 1));
        }

        return dp[n][m];
    }

    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        dp.resize(n + 1, vector<int>(m + 1, -1));
        int lcs_length = lcs(s, t, n, m);

        return lcs_length == n;
    }
};

// Method 2: tabulation (bottom-up)
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // base case
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        // choice diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m] == s.length();
    }
};

int main() {
    string s1 = "ABY";
    string s2 = "ADXCPY";

    Solution sol;
    bool ans = sol.isSubsequence(s1, s2);

    cout << "ans --> " << boolalpha << ans << endl;
    return 0;
}