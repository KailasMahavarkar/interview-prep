#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/k-inverse-pairs-array/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (top-down) -> TLE
// TC : O(n*k)*sizeof(recursion_stack) -> O(n*k*min(n, k))
// SC : O(n*k)
class SolutionOne {
   public:
    const int M = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(int n, int k) {
        if (n == 0)
            return 0;

        if (k == 0)
            return 1;

        if (dp[n][k] != -1)
            return dp[n][k];

        int totalInversions = 0;

        // In an array of length n, We can'dp create inversions more than (n-1) -> min(n-1, k)
        for (int i = 0; i <= min(n - 1, k); i++) {
            totalInversions = (totalInversions % M + kInversePairs(n - 1, k - i) % M) % M;
        }

        return dp[n][k] = totalInversions;
    }

    int kInversePairs(int n, int k) {
        dp.resize(n + 1000, vector<int>(k + 1, -1));
        return solve(n, k);
    }
};

// Approach-1 (bottom-up) --> ACCEPTED
// TC : O(n*k)
// SC : O(n*k)
class Solution {
   public:
    int M = 1e9 + 7;

    int kInversePairs(int n, int k) {
        vector<vector<int>> t(n + 1, vector<int>(k + 1));

        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        // O(n*k)
        for (int i = 1; i <= n; i++) {
            long long cumSum = 1;
            for (int j = 1; j <= k; j++) {
                cumSum += t[i - 1][j];
                if (j >= i) {
                    cumSum -= t[i - 1][j - i];
                }
                t[i][j] = cumSum % M;
            }
        }
        return t[n][k];
    }
};

int main() {
    Solution sol;
    int ans = sol.kInversePairs(3, 1);
    cout << "ans --> " << ans << endl;
}