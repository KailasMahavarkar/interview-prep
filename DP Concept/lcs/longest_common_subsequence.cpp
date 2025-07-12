#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// longest common subsequence
// problem link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// Tags: Paytm, VMWare, Amazon, Microsoft, Citrix, MakeMyTrip

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
    int solve(string text1, string text2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (text1[n - 1] == text2[m - 1]) {
            dp[n][m] = 1 + solve(text1, text2, n - 1, m - 1);
        } else {
            dp[n][m] = max(solve(text1, text2, n - 1, m), solve(text1, text2, n, m - 1));
        }

        return dp[n][m];
    }

    int lcs(int x, int y, string s1, string s2) {
        int ans = solve(s1, s2, x, y);
        return ans;
    }
};

int main() {
    string str1 = "abcde";
    string str2 = "ace";
    Solution sol;
    int ans = sol.lcs(str1.length(), str2.length(), str1, str2);
    cout << "ans --> " << ans << endl;
}