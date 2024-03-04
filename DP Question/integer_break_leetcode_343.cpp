#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/integer-break/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
    Notes          : A very good question to test recursion skills
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    int dp[60];
    int solve(int n) {
        if (n == 1) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int result = INT_MIN;
        for (int i = 1; i < n; i++) {
            // either i * (n - i) will be best answer lets say 5 -> 4, 1
            // so.. 4 x 1 = 4 .. is valid candidate to form best answer
            // or
            // solve(n - i) lets say it yeilds 6
            // so i * max(4, 6) becomes 6
            int product = i * max(n - i, solve(n - i));

            result = max(result, product);
        }

        return dp[n] = result;
    }
    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};

int main() {
    Solution sol;
    int ans = sol.integerBreak(10);
    cout << "ans -> " << ans << endl;
}