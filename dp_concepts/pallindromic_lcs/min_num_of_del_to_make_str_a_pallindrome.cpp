#include <bits/stdc++.h>
using namespace std;

// Form a palindrome (minimum number of deletions to make a string pallindrome)
// problem link: https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1
// Note: min number insertions and deletions are basically the same thing
// Tags: Amazon, Microsoft, Google, Airtel

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

    int findMinInsertions(string S) {
        string rev_str = string(S.rbegin(), S.rend());
        int n = S.length();
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int lps = lcs(S, rev_str, n, n);
        return n - lps;
    }
};

int main() {
    Solution sol;
    int ans = sol.findMinInsertions("abcd");
    cout << "ans --> " << ans << endl;
}
