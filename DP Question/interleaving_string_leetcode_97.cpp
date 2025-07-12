#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/interleaving-string/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    int x, y, N;
    int dp[101][101];
    bool solve(string s1, string s2, string s3, int i, int j) {
        // remember K -> i + j
        // we can either calculate 'K' like this or keep 'K' in dp
        // making it a 3D dp

        // remember when we have question like s1, s2 and we have do something related to s3
        // always keep i+j in mind
        if (x == i && y == j && i + j == N) {
            return true;
        }

        if (i + j >= N) {
            return false;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool result = false;

        // We trying to make string s3 from char of s1 in this recursive INSTANCE
        if (s1[i] == s3[i + j]) {
            result = solve(s1, s2, s3, i + 1, j);
        }

        // since if can happen we already found answer thus we need this check
        if (result == true) {
            return dp[i][j];
        }

        // We trying to make string s3 from char of s2 in this recursive INSTANCE
        if (s2[j] == s3[i + j]) {
            result = solve(s1, s2, s3, i, j + 1);
        }

        return dp[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        x = s1.length();
        y = s2.length();
        N = s3.length();
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0);
    }
};

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution sol;
    bool ans = sol.isInterleave(s1, s2, s3);
    cout << "ans --> " << boolalpha << ans << endl;
}