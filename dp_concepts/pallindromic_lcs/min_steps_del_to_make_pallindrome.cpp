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

int count = 0;
vector<vector<int>> dp;
int lcs(string S1, string S2, int n, int m) {
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
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int minDeletions(string str, int n) {
    string rev_str = string(str.rbegin(), str.rend());
    dp.resize(n + 1, vector<int>(n + 1, -1));
    int lps = lcs(str, rev_str, n, n);
    return n - lps;
}

int main() {
    string str1 = "abcba";
    int ans = minDeletions(str1, str1.length());
    cout << "ans --> " << ans << endl;
}