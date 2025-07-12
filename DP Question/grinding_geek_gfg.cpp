#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://www.geeksforgeeks.org/problems/grinding-geek/1
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(idx * total)
// SC : O(idx * total)
class Solution {
   public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int> &cost, int idx, int total) {
        // base case for failure
        if (idx >= n || total <= 0) {
            return 0;
        }

        if (dp[idx][total] != -1) {
            return dp[idx][total];
        }

        int take = 0;
        int not_take = 0;

        if (total >= cost[idx]) {
            int returnBack = 0.9 * cost[idx];
            take = 1 + solve(cost, idx + 1, total - cost[idx] + returnBack);
        }

        not_take = solve(cost, idx + 1, total);
        return dp[idx][total] = max(take, not_take);
    }

    int max_courses(int N, int total, vector<int> &cost) {
        n = N;
        dp.resize(1001, vector<int>(1001, -1));
        return solve(cost, 0, total);
    }
};

int main() {
    int n = 2;
    int total = 10;
    vector<int> cost = {10, 9};
    Solution sol;
    int ans = sol.max_courses(n, total, cost);
    cout << "ans --> " << ans << endl;
}