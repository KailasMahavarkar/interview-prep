#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/knight-dialer/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n*k)
// SC : O(n*k)
class Solution {
   public:
    int M = 1e9 + 7;
    vector<vector<int>> dp;
    vector<vector<int>> adj = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}};

    int solve(int k, int cell) {
        if (k == 0) {
            return 1;
        }

        if (dp[k][cell] != -1) {
            return dp[k][cell];
        }

        int result = 0;

        for (int &nextCell : adj[cell]) {
            result = (result + solve(k - 1, nextCell)) % M;
        }

        dp[k][cell] = result;
        return dp[k][cell];
    }

    int knightDialer(int k) {
        int result = 0;
        dp.resize(5001, vector<int>(10, -1));

        for (int i = 0; i <= 9; i++) {
            result = (result + solve(k - 1, i)) % M;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int result = sol.knightDialer(3131);
    cout << "ans --> " << result << endl;
}
