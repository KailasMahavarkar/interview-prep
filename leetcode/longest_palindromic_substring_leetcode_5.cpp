#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
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

    string longestPalindrome(string s) {
        int n = s.length();

        // Initialize the dp array for LCS
        dp.resize(n + 1, vector<int>(n + 1, -1));

        // Reverse the input string to find its reverse
        string reversedS = s;
        reverse(reversedS.begin(), reversedS.end());

        // Find the LCS of the original string and its reverse
        int lcsLength = lcs(s, reversedS, n, n);

        // Reconstruct the longest palindromic substring
        string longestPalindromicSubstr;
        int i = n, j = n;

        while (i > 0 && j > 0) {
            if (s[i - 1] == reversedS[j - 1]) {
                longestPalindromicSubstr += s[i - 1];
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }

        return longestPalindromicSubstr;
    }
};

int main() {
}