#include <bits/stdc++.h>
using namespace std;

// Longest Repeating Subsequence
// problem link: https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
// Tags: Amazon, Google

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
    int count = 0;
    int lcs(string text1, string text2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (text1[n - 1] == text2[m - 1] && n != m) {
            dp[n][m] = 1 + lcs(text1, text2, n - 1, m - 1);
        } else {
            dp[n][m] = max(lcs(text1, text2, n - 1, m), lcs(text1, text2, n, m - 1));
        }

        return dp[n][m];
    }

    int LongestRepeatingSubsequence(string str) {
        int n = str.length();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return lcs(str, str, str.length(), str.length());
    }
};

// Method 1: recursion + memoization
class Solution {
   public:
    int LongestRepeatingSubsequence(string str) {
        int n = str.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // base case
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        // choice diagram
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (str[i - 1] == str[j - 1] && i != j) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        printDP("", dp);
        return dp[n][n];
    }
};

int main() {
    Solution sol;
    int ans = sol.LongestRepeatingSubsequence("axxzxy");
    cout << "ans --> " << ans << endl;
}