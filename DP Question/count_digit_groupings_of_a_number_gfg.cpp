#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    int n;
    int dp[101][901];  // dp[idx][prevSum]

    int solve(int idx, int prevSum, string str) {
        // when j pointer reaches to end
        // base case for success
        // there isnt base case for failure since its controlled via for loop
        if (idx >= n) {
            return 1;
        }

        if (dp[idx][prevSum] != -1) {
            return dp[idx][prevSum];
        }

        int currSum = 0;
        int result = 0;
        for (int j = idx; j < n; j++) {
            currSum += (str[j] - '0');
            if (currSum >= prevSum) {
                result += solve(j + 1, currSum, str);
            }
        }
        return dp[idx][prevSum] = result;
    }

    int TotalCount(string str) {
        memset(dp, -1, sizeof(dp));
        n = str.length();
        return solve(0, 0, str);
    }
};

int main() {
    Solution sol;
    string s = "1119";
    int ans = sol.TotalCount(s);
    cout << "ans -->" << ans << endl;
}