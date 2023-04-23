#include <bits/stdc++.h>
using namespace std;

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
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;
        int n = text1.size();
        int m = text2.size();

        dp.resize(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    string str1 = "abcde";
    string str2 = "ace";
    Solution sol;
    int ans = sol.longestCommonSubsequence(str1, str2);
    cout << "ans --> " << ans << endl;
}