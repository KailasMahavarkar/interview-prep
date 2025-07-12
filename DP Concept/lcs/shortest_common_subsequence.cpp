#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
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

// Method 1: recursion + memoization
class SolutionMemo {
   public:
    int result = 0;
    vector<vector<int>> dp;
    int LCS(string s1, string s2, int n, int m) {
        // when either string1 or string2 is empty
        if (n == 0 || m == 0) {
            return 0;
        }

        // check subproblem in memo
        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        LCS(s1, s2, n - 1, m);
        LCS(s1, s2, n, m - 1);

        if (s1[n - 1] == s2[m - 1]) {
            dp[n][m] = 1 + LCS(s1, s2, n - 1, m - 1);
            result = max(result, dp[n][m]);
        } else {
            dp[n][m] = 0;
        }

        return dp[n][m];
    }
    int longestCommonSubstr(string S1, string S2, int n, int m) {
        dp.resize(n + 1, vector<int>(m + 1, -1));
        LCS(S1, S2, n, m);
        return result;
    }
};

// Method 2: (tabulation) bottom-up
class Solution {
   public:
    int result = 0;
    vector<vector<int>> dp;
   
    int longestCommonSubstr(string S1, string S2, int n, int m) {
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
                    dp[i][j] = 0;
                }
            }
        }

        int maxx = INT_MIN;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                maxx = max(maxx, dp[i][j]);

        return maxx;
    }
};

int main() {
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    int n = s1.length();
    int m = s2.length();

    Solution sol;
    int ans = sol.longestCommonSubstr(s1, s2, n, m);

    cout << ans << endl;
    return 0;
}