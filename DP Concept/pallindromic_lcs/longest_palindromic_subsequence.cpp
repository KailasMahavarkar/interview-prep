#include <bits/stdc++.h>
using namespace std;

// longest pallindromic subsequence
// problem link: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
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

class Solution {
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

        if (text1[n - 1] == text2[m - 1]) {
            dp[n][m] = 1 + lcs(text1, text2, n - 1, m - 1);
        } else {
            dp[n][m] = max(lcs(text1, text2, n - 1, m), lcs(text1, text2, n, m - 1));
        }

        return dp[n][m];
    }

    int longestPalinSubseq(string A) {
        int n = A.length();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        string B = string(A.rbegin(), A.rend());
        int ans = lcs(A, B, n, n);
        printDP("", dp);
        return ans;
    }
};

int main() {
    string str1 = "bbabcbcab";
    Solution sol;
    int ans = sol.longestPalinSubseq(str1);
    cout << "ans --> " << ans << endl;
}