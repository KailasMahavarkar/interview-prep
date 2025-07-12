#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/perfect-squares/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    int r;
    vector<int> dp;
    int solve(int idx) {
        if (idx == 3) {
            return 2;
        }

        if (idx <= 2) {
            return 1;
        }

        if (dp[idx] != -1){
            return dp[idx];
        }

        int min_value = INT_MAX;
        for (int i = 1; i < 100; i++) {
            int diff = idx - pow(i, 2);
            if (diff > 0) {
                min_value = min(min_value, 1 + solve(diff));
            }
        }

        return dp[idx] = min_value;
    }

    int numSquares(int n) {
        r = n;
        dp.resize(n + 1, -1);
        return solve(n);
    }
};

int main() {
    Solution sol;
    int ans = sol.numSquares(81);
    cout << "ans --> " << ans << endl;
}
