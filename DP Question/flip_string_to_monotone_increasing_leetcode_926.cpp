#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
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
    int n;
    int dp[100001][2];
    int solve(string &s, int currIndex, int prev) {
        if (currIndex >= n) {
            return 0;
        }

        if (dp[currIndex][prev] != -1) {
            return dp[currIndex][prev];
        }

        int flip = INT_MAX;
        int no_flip = INT_MAX;

        // case 1: curr=0
        if (s[currIndex] == '0') {
            if (prev == 0) {
                // 0   0
                // p   c
                // we go currIndex + 1 and also flip

                // 0   1   0
                // p   c   c+1
                // thus for c+1.. previous flip is 1

                // In this question flip does not mean ... flpping state of previous value
                // but while standing at currIndex + 1, when we look back ... and if flip takes place
                // we update the state
                // Think of this intution

                flip = 1 + solve(s, currIndex + 1, 1);
                no_flip = solve(s, currIndex + 1, 0);
            } else {
                flip = 1 + solve(s, currIndex + 1, 1);
            }
        } else {
            if (prev == 0) {
                flip = 1 + solve(s, currIndex + 1, 0);
                no_flip = solve(s, currIndex + 1, 1);
            } else {
                no_flip = solve(s, currIndex + 1, 1);
            }
        }

        return dp[currIndex][prev] = min(flip, no_flip);
    }

    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp));
        n = s.length();
        return solve(s, 0, 0);
    }
};

int main() {
    string str = "010110";
    Solution sol;
    int answer = sol.minFlipsMonoIncr(str);
    cout << "answer --> " << answer << endl;
}